#include <stdio.h>
#include "def.h"
#include "protocol/protocol.h"
#include "socket/tcp_server.h"
#include "ui/ui.h"

extern int server_fd, client_fd;

static void led_ryg_turn(int cmd, int code)
{
    msg_frame_t led_msg_frame;
    led_msg_frame.type = LED_RYG;
    led_msg_frame.cmd = cmd;
    led_msg_frame.code = code;
    led_msg_frame.datalen = 0;

    msg_buf_t *_msg_buf = pkg_frame(&led_msg_frame);

    server_send_data(client_fd, (char *)_msg_buf->buf_ptr, _msg_buf->buf_size);
}

static void btn1_click_cb(lv_event_t *event) 
{
    printf("Button1 clicked\n");
    static char flag = 0;

    if(flag == 0)
    {
        flag = 1;
        led_ryg_turn(LED_R, LED_ON);
    }
    else
    {
        flag = 0;
        led_ryg_turn(LED_R, LED_OFF);
    }
}

static void btn2_click_cb(lv_event_t *event) 
{
    printf("Button2 clicked\n");
    static char flag = 0;

    if(flag == 0)
    {
        flag = 1;
        led_ryg_turn(LED_Y, LED_ON);
    }
    else
    {
        flag = 0;
        led_ryg_turn(LED_Y, LED_OFF);
    }
}

static void btn3_click_cb(lv_event_t *event) 
{
    printf("Button3 clicked\n");
    static char flag = 0;

    if(flag == 0)
    {
        flag = 1;
        led_ryg_turn(LED_G, LED_ON);
    }
    else
    {
        flag = 0;
        led_ryg_turn(LED_G, LED_OFF);
    }
}

int button_init(void)
{
    lv_obj_add_event_cb(ui_Button1, btn1_click_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(ui_Button2, btn2_click_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(ui_Button3, btn3_click_cb, LV_EVENT_CLICKED, NULL);

    return 0;
}
