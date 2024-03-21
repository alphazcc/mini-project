#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include "def.h"
#include "protocol/protocol.h"
#include "socket/tcp_server.h"
#include "ui/ui.h"

int server_fd, client_fd;

static pthread_t date_thread_id;
static pthread_t recv_thread_id;
static msg_buf_t *recv_msg_buf = &msg_buf;

int button_init(void);
int weather_init(void);

static int ctrl_dev_aht20(msg_frame_t *_msg_pack)
{
    printf("--- ctrl_dev_aht20 ---\r\n");

    uint16_t temp_raw = (uint16_t)(_msg_pack->data[0] << 8) + _msg_pack->data[1];
    uint16_t hum_raw =  (uint16_t)(_msg_pack->data[2] << 8) + _msg_pack->data[3];
    uint8_t temp = (temp_raw + 5) / 10;         // 四舍五入
    uint8_t hum = (hum_raw + 5) / 10;
    char temp_src[4], hum_src[4];

    printf("temp raw value: %d, hum raw value: %d \r\n", temp_raw, hum_raw);

    lv_slider_set_value(ui_SliderTemp, temp, LV_ANIM_OFF);
    lv_slider_set_value(ui_SliderHum, hum, LV_ANIM_OFF);

    snprintf(temp_src, sizeof(temp_src), "%d", temp);
    lv_label_set_text(ui_Temp, temp_src);
    snprintf(hum_src, sizeof(hum_src), "%d", hum);
    lv_label_set_text(ui_Hum, hum_src);

    return 0;
}

static int ctrl_dev_adc(msg_frame_t *_msg_pack)
{
    printf("--- ctrl_dev_adc ---\r\n");

    uint16_t adc_raw = (uint16_t)(_msg_pack->data[0] << 8) + _msg_pack->data[1];
    uint8_t pm2_5 = adc_raw / 16;
    char pm2_5_src[4];

    printf("adc raw value: %d, pm2_5 value: %d \r\n", adc_raw, pm2_5);

    lv_arc_set_value(ui_Air, pm2_5);

    snprintf(pm2_5_src, sizeof(pm2_5_src), "%d", pm2_5);
    lv_label_set_text(ui_AirValue, pm2_5_src);

    return 0;
}

static int ctrl_cmd_func(const msg_pkg_t *_msg_pkg)
{
    printf("--- ctrl_cmd_func ---\r\n");
    
    switch(_msg_pkg->pkg->type)
    {
        case AHT20: ctrl_dev_aht20(_msg_pkg->pkg); break;
        case ADC: ctrl_dev_adc(_msg_pkg->pkg); break;
        default: return -1;
    }

    return 0; 
}

static void msg_buf_print(msg_buf_t *_msg_buf)
{
    printf("buf_size: %d \r\n", _msg_buf->buf_size);
    printf("buf_data: ");
    for(uint8_t i = 0; i < _msg_buf->buf_size; i++)
    {
        printf("%x ", _msg_buf->buf_ptr[i]);
    }
    printf("\r\n");
}

static void *date_thread(void *arg)
{
    time_t now;
    struct tm *local;
    char timeHour[4], timeMin[4], timeSec[4];
    char timeYear[8], timeMon[4], timeDay[4];

    // TODO: Getting accurate time via the web

    // time(&now);
    // local = localtime(&now);

    // local->tm_hour += 8;
    // time_t new_time = mktime(local);

    // // 设置 timeval 结构体
    // struct timeval tv;
    // tv.tv_sec = new_time;
    // tv.tv_usec = 0; // 微秒
 
    // // 设置系统时间
    // if (settimeofday(&tv, NULL) == -1) 
    // {
    //     perror("settimeofday");
    //     return NULL;
    // }
    // printf("Time set successfully.\n");

    while(1)
    {
        time(&now);
        local = localtime(&now);

        // printf("Current time: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
        
        {
            // TODO: Weather data needs to be updated on time
            // weather_update(); 
        }

        snprintf(timeHour, sizeof(timeHour), "%02d", local->tm_hour);
        snprintf(timeMin, sizeof(timeMin), "%02d", local->tm_min);
        snprintf(timeSec, sizeof(timeSec), "%02d", local->tm_sec);
        snprintf(timeYear, sizeof(timeYear), "%d", local->tm_year + 1900);
        snprintf(timeMon, sizeof(timeMon), "%d", local->tm_mon + 1);
        snprintf(timeDay, sizeof(timeDay), "%d", local->tm_mday);

        lv_label_set_text(ui_TimeHour, timeHour);
        lv_label_set_text(ui_TimeMin, timeMin);
        lv_label_set_text(ui_TimeSec, timeSec);
        lv_label_set_text(ui_Year, timeYear);
        lv_label_set_text(ui_Month, timeMon);
        lv_label_set_text(ui_Day, timeDay);

        switch (local->tm_wday)
        {
            case 0: lv_label_set_text(ui_Week, "日"); break;
            case 1: lv_label_set_text(ui_Week, "一"); break;
            case 2: lv_label_set_text(ui_Week, "二"); break;
            case 3: lv_label_set_text(ui_Week, "三"); break;
            case 4: lv_label_set_text(ui_Week, "四"); break;
            case 5: lv_label_set_text(ui_Week, "五"); break;
            case 6: lv_label_set_text(ui_Week, "六"); break;
        default:
            break;
        }

        sleep(1);
    }

    return NULL;
}

static void *recv_thread(void *arg)
{
    recv_msg_buf->buf_ptr=recv_msg_buf->buf;
    while(1)
    {
        if(server_receive_data(client_fd, (char *)recv_msg_buf->buf_ptr, (ssize_t *)&recv_msg_buf->buf_size) == 0)
        {
            printf("thread recv \r\n");

            msg_buf_print(recv_msg_buf);
            msg_pkg_t *_msg_pkg = unpkg_frame(recv_msg_buf->buf_ptr, recv_msg_buf->buf_size);
            ctrl_cmd_func(_msg_pkg);
        } 
    }
    return NULL;
}

int application_init(void)
{
    button_init();
    server_fd = server_init_socket();
    // set_socket_timeout(server_fd, 3000);
    client_fd = server_accept_client(server_fd);
    weather_init();
    pthread_create(&date_thread_id, NULL, date_thread, NULL);
    pthread_create(&recv_thread_id, NULL, recv_thread, NULL);

    return 0;
}

#if 0
int aht20_test_cmd(void)
{
    printf("--- aht20_test_cmd ---\r\n");

    msg_frame_t aht_msg_frame = {AHT20, 0, 0, 4, {0x0e, 0x10, 0x13, 0x24}}; // 3600 4900
    msg_buf_t *_msg_buf = pkg_frame(&aht_msg_frame);
    msg_pkg_t *_msg_pkg = unpkg_frame(_msg_buf->buf_ptr, _msg_buf->buf_size);
    ctrl_cmd_func(_msg_pkg);
    return 0;
}

int adc_test_cmd(void)
{
    printf("--- adc_test_cmd ---\r\n");

    msg_frame_t adc_msg_frame = {ADC, 0, 0, 2, {0x00, 0xc8}}; // 200
    msg_buf_t *_msg_buf = pkg_frame(&adc_msg_frame);
    msg_pkg_t *_msg_pkg = unpkg_frame(_msg_buf->buf_ptr, _msg_buf->buf_size);
    ctrl_cmd_func(_msg_pkg);
    return 0;
}
// ED B9 55 AA 01 00 00 00 00 04 00 B5 00 DD 7B B8 5A A5
#endif