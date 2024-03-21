#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "socket/tcp_client.h"
#include "cJSON/cJSON.h"
#include "ui/ui.h"

/* 请求包 */
#define REQUEST_PKG \
    "GET https://api.seniverse.com/v3/weather/%s.json?key=%s&location=%s&language=zh-Hans&unit=c\r\n"

/* 心知天气 API key */
#define API_KEY "your-api-key"

/* 天气数据类型 */
#define DAILY "daily"

/* 地点 */
#define WUHAN "wuhan"

/* 天气数据结构体 */
typedef struct weather
{
    /* 实况天气数据 */
    char id[32];              // 城市 ID
    char name[32];            // 城市中文名
    char country[32];         // 国家
    char path[32];            // 完整城市地址
    char timezone[32];        // 时区
    char timezone_offset[32]; // 时差
    char text[32];            // 天气预报文字
    char code[32];            // 天气预报代码
    char temperature[32];     // 温度
    char last_update[32];     // 数据更新时间

    /* 三天天气数据 */
    char date[3][32];                   // 日期
    char text_day[3][64];               // 白天天气现象文字
    char code_day[3][32];               // 白天天气现象代码
    char text_night[3][64];             // 晚间天气现象文字
    char code_night[3][32];             // 晚间天气现象代码
    char high[3][32];                   // 当天最高温度
    char low[3][32];                    // 当天最低温度
    char rainfall[3][32];               // 降水量，单位 mm
    char precip[3][32];                 // 降水概率，范围 0~100，单位百分比
    char wind_direction[3][32];         // 风向文字
    char wind_direction_degree[3][32];  // 风向角度，范围 0~360
    char wind_speed[3][32];             // 风速，单位 km/h（当 unit = c 时）、mph（当 unit = f 时）
    char wind_scale[3][32];             // 风力等级
    char humidity[3][32];               // 相对湿度，0~100，单位为百分比
} weather_t;

static pthread_t weather_update_ui_thread_id;
static weather_t weather_daily;

static int cJSON_Parse_Weather_Daily(char *JSON, weather_t *results)
{
    cJSON *json, *arrayItem, *object, *subobject, *item, *sub_child_object, *child_Item;

    json = cJSON_Parse(JSON);
    if (json == NULL)
    {
        return cJSON_False;
    }
    else
    {
        if ((arrayItem = cJSON_GetObjectItem(json, "results")) != NULL)
        {

            if ((object = cJSON_GetArrayItem(arrayItem, 0)) != NULL)
            {
                /* 匹配 location */
                if ((subobject = cJSON_GetObjectItem(object, "location")) != NULL)
                {
                    if ((item = cJSON_GetObjectItem(subobject, "name")) != NULL)
                    {
                        /* 匹配 name */
                        memcpy(results->name, item->valuestring, strlen(item->valuestring));
                    }
                }
                /* 匹配 daily */
                if ((subobject = cJSON_GetObjectItem(object, "daily")) != NULL)
                {
                    int sub_array_size = cJSON_GetArraySize(subobject);
                    for (int i = 0; i < sub_array_size; i++)
                    {
                        if ((sub_child_object = cJSON_GetArrayItem(subobject, i)) != NULL)
                        {
                            /* 匹配日期 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "date")) != NULL)
                            {
                                memcpy(results->date[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配白天天气现象文字 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "text_day")) != NULL)
                            {
                                memcpy(results->text_day[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配白天天气现象代码 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "code_day")) != NULL)
                            {
                                memcpy(results->code_day[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配夜间天气现象文字 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "text_night")) != NULL)
                            {
                                memcpy(results->text_night[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配夜间天气现象代码 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "code_night")) != NULL)
                            {
                                memcpy(results->code_night[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配当天最高温度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "high")) != NULL)
                            {
                                memcpy(results->high[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配当天最低温度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "low")) != NULL)
                            {
                                memcpy(results->low[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配降水量 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "rainfall")) != NULL)
                            {
                                memcpy(results->rainfall[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配降水概率 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "precip")) != NULL)
                            {
                                memcpy(results->precip[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风向文字 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_direction")) != NULL)
                            {
                                memcpy(results->wind_direction[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风向角度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_direction_degree")) != NULL)
                            {
                                memcpy(results->wind_direction_degree[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风速 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_speed")) != NULL)
                            {
                                memcpy(results->wind_speed[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配风力等级 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "wind_scale")) != NULL)
                            {
                                memcpy(results->wind_scale[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                            /* 匹配相对湿度 */
                            if ((child_Item = cJSON_GetObjectItem(sub_child_object, "humidity")) != NULL)
                            {
                                memcpy(results->humidity[i], child_Item->valuestring, strlen(child_Item->valuestring));
                            }
                        }
                    }
                }
                /* 匹配 last_update */
                if ((subobject = cJSON_GetObjectItem(object, "last_update")) != NULL)
                {
                    memcpy(results->last_update, subobject->valuestring, strlen(subobject->valuestring));
                }
            }
        }
    }

    cJSON_Delete(json);

    return 0;
}

static void weather_show_data(weather_t *results)
{
    printf("--- %s 三天天气情况 --- \r\n", results->name);

    for(int i = 0; i < 3; i++)
    {
        printf("\r\n日期: %s \r\n", results->date[i]);
        printf("白天: %s(%s) \r\n夜晚: %s(%s) \r\n", 
               results->text_day[i], results->code_day[i],
               results->text_night[i], results->code_night[i]); 
        printf("温度: %s ~ %s ℃ \r\n", results->low[i], results->high[i]); 
        printf("降水量: %s mm \r\n降水概率: %s %%\r\n", 
               results->rainfall[i], results->precip[i]);
        printf("风向: %s(%s) %s 级 \r\n风速: %s km/h \r\n",
               results->wind_direction[i], results->wind_direction_degree[i], 
               results->wind_scale[i], results->wind_speed[i]);
        printf("湿度: %s %% \r\n", results->humidity[i]); 
    }
    printf("\r\n数据更新时间: %s \r\n", results->last_update);
    printf("\r\n");
}

static void weather_update_ui_img(int code)
{
    switch (code)
    {
    case 0: lv_img_set_src(ui_weatherImg, &ui_img_icons_00_png); break;
    case 1: lv_img_set_src(ui_weatherImg, &ui_img_icons_01_png); break;
    case 2: lv_img_set_src(ui_weatherImg, &ui_img_icons_02_png); break; 
    case 3: lv_img_set_src(ui_weatherImg, &ui_img_icons_03_png); break;
    case 4: lv_img_set_src(ui_weatherImg, &ui_img_icons_04_png); break;
    case 5: lv_img_set_src(ui_weatherImg, &ui_img_icons_05_png); break; 
    case 6: lv_img_set_src(ui_weatherImg, &ui_img_icons_06_png); break;
    case 7: lv_img_set_src(ui_weatherImg, &ui_img_icons_07_png); break;
    case 8: lv_img_set_src(ui_weatherImg, &ui_img_icons_08_png); break; 
    case 9: lv_img_set_src(ui_weatherImg, &ui_img_icons_09_png); break;

    case 10: lv_img_set_src(ui_weatherImg, &ui_img_icons_10_png); break;
    case 11: lv_img_set_src(ui_weatherImg, &ui_img_icons_11_png); break; 
    case 12: lv_img_set_src(ui_weatherImg, &ui_img_icons_12_png); break;
    case 13: lv_img_set_src(ui_weatherImg, &ui_img_icons_13_png); break;
    case 14: lv_img_set_src(ui_weatherImg, &ui_img_icons_14_png); break; 
    case 15: lv_img_set_src(ui_weatherImg, &ui_img_icons_15_png); break;
    case 16: lv_img_set_src(ui_weatherImg, &ui_img_icons_16_png); break;
    case 17: lv_img_set_src(ui_weatherImg, &ui_img_icons_17_png); break; 
    case 18: lv_img_set_src(ui_weatherImg, &ui_img_icons_18_png); break;
    case 19: lv_img_set_src(ui_weatherImg, &ui_img_icons_19_png); break;

    case 20: lv_img_set_src(ui_weatherImg, &ui_img_icons_20_png); break;
    case 21: lv_img_set_src(ui_weatherImg, &ui_img_icons_21_png); break; 
    case 22: lv_img_set_src(ui_weatherImg, &ui_img_icons_22_png); break;
    case 23: lv_img_set_src(ui_weatherImg, &ui_img_icons_23_png); break;
    case 24: lv_img_set_src(ui_weatherImg, &ui_img_icons_24_png); break; 
    case 25: lv_img_set_src(ui_weatherImg, &ui_img_icons_25_png); break;
    case 26: lv_img_set_src(ui_weatherImg, &ui_img_icons_26_png); break;
    case 27: lv_img_set_src(ui_weatherImg, &ui_img_icons_27_png); break; 
    case 28: lv_img_set_src(ui_weatherImg, &ui_img_icons_28_png); break;
    case 29: lv_img_set_src(ui_weatherImg, &ui_img_icons_29_png); break;

    case 30: lv_img_set_src(ui_weatherImg, &ui_img_icons_30_png); break;
    case 31: lv_img_set_src(ui_weatherImg, &ui_img_icons_31_png); break; 
    case 32: lv_img_set_src(ui_weatherImg, &ui_img_icons_32_png); break;
    case 33: lv_img_set_src(ui_weatherImg, &ui_img_icons_33_png); break;
    case 34: lv_img_set_src(ui_weatherImg, &ui_img_icons_34_png); break; 
    case 35: lv_img_set_src(ui_weatherImg, &ui_img_icons_35_png); break;
    case 36: lv_img_set_src(ui_weatherImg, &ui_img_icons_36_png); break;
    case 37: lv_img_set_src(ui_weatherImg, &ui_img_icons_37_png); break; 
    case 38: lv_img_set_src(ui_weatherImg, &ui_img_icons_38_png); break;
    case 99: lv_img_set_src(ui_weatherImg, &ui_img_icons_99_png); break;
    default: break;
    }
}

static void *weather_update_ui_thread(void *arg)
{
    weather_t *results = (weather_t *)arg;
    char buffer[64] = {0};
    int day = 0;

    while(1)
    {
        memset(buffer, 0, 64);
        sprintf(buffer, "%s / %s", results->text_day[day], results->text_night[day]);

        lv_label_set_text(ui_TextDay, buffer);
        lv_label_set_text(ui_MinTemp, results->low[day]);
        lv_label_set_text(ui_MaxTemp, results->high[day]);
        lv_label_set_text(ui_outHum, results->humidity[day]);

        lv_label_set_text(ui_uDay, results->date[day]);
        weather_update_ui_img(atoi(results->code_day[day]));
        sleep(2);
        weather_update_ui_img(atoi(results->code_night[day]));
        sleep(2);

        if(++day == 3)
        {
            day = 0;
        }
    }
    return NULL;
}

static int weather_update_ui(weather_t *results)
{
    pthread_create(&weather_update_ui_thread_id, NULL, 
                weather_update_ui_thread, results);
    return 0;
}

int weather_init(void)
{
    int client_fd = 0;
    char buffer[1024] = {0};
    int json_size = 0;

    /* 创建客户端 */
    client_fd = client_init_socket();

    /* 组合请求包 */
    sprintf(buffer, REQUEST_PKG, DAILY, API_KEY, WUHAN);
    printf("\r\n%s \r\n", buffer);

    /* 向心知天气服务端发送请求 */
    client_send_data(client_fd, buffer, strlen(buffer));

    /* 清空缓存准备接收天气数据 */
    memset(buffer, 0, sizeof(buffer));

    /* 接收天气数据 JSON 格式 */
    client_receive_data(client_fd, buffer, &json_size);
    printf("\r\n%s \r\n", buffer);

    /* 解析天气数据到 weather_daily 中 */
    cJSON_Parse_Weather_Daily(buffer, &weather_daily);

    /* 打印天气信息 */
    weather_show_data(&weather_daily);

    /* 更新天气显示 */
    weather_update_ui(&weather_daily);

    /* 关闭客户端 */
    client_close_socket(client_fd);

    return 0;
}
