// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ScreenMain_screen_init(void)
{
    ui_ScreenMain = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenMain, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenMain, lv_color_hex(0x3B3B3B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenMain, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeHour = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_TimeHour, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeHour, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeHour, -75);
    lv_obj_set_y(ui_TimeHour, -180);
    lv_obj_set_align(ui_TimeHour, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimeHour, "09");
    lv_obj_set_style_text_color(ui_TimeHour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeHour, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeHour, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeMin = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_TimeMin, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeMin, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeMin, 5);
    lv_obj_set_y(ui_TimeMin, -180);
    lv_obj_set_align(ui_TimeMin, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimeMin, "35");
    lv_obj_set_style_text_color(ui_TimeMin, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeMin, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeMin, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TimeSec = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_TimeSec, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimeSec, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TimeSec, 85);
    lv_obj_set_y(ui_TimeSec, -180);
    lv_obj_set_align(ui_TimeSec, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimeSec, "30");
    lv_obj_set_style_text_color(ui_TimeSec, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimeSec, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimeSec, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Air = lv_arc_create(ui_ScreenMain);
    lv_obj_set_width(ui_Air, 150);
    lv_obj_set_height(ui_Air, 150);
    lv_obj_set_x(ui_Air, 135);
    lv_obj_set_y(ui_Air, -5);
    lv_obj_set_align(ui_Air, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Air, 0, 256);
    lv_arc_set_value(ui_Air, 15);
    lv_obj_set_style_arc_width(ui_Air, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Air, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Air, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Air, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Air, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Air, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_AirValue = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_AirValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AirValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AirValue, 115);
    lv_obj_set_y(ui_AirValue, 0);
    lv_obj_set_align(ui_AirValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_AirValue, "15");
    lv_obj_set_style_text_color(ui_AirValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AirValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SliderTemp = lv_slider_create(ui_ScreenMain);
    lv_slider_set_range(ui_SliderTemp, -40, 60);
    lv_slider_set_value(ui_SliderTemp, 25, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_SliderTemp) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_SliderTemp, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_SliderTemp, 15);
    lv_obj_set_height(ui_SliderTemp, 150);
    lv_obj_set_x(ui_SliderTemp, 280);
    lv_obj_set_y(ui_SliderTemp, -20);
    lv_obj_set_align(ui_SliderTemp, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_SliderTemp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderTemp, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderTemp, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderTemp, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderTemp, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_SliderHum = lv_slider_create(ui_ScreenMain);
    lv_slider_set_value(ui_SliderHum, 45, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_SliderHum) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_SliderHum, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_SliderHum, 15);
    lv_obj_set_height(ui_SliderHum, 150);
    lv_obj_set_x(ui_SliderHum, 350);
    lv_obj_set_y(ui_SliderHum, -20);
    lv_obj_set_align(ui_SliderHum, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_SliderHum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderHum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SliderHum, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderHum, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Temp = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Temp, 270);
    lv_obj_set_y(ui_Temp, -110);
    lv_obj_set_align(ui_Temp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Temp, "25");
    lv_obj_set_style_text_color(ui_Temp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Hum = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Hum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Hum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Hum, 340);
    lv_obj_set_y(ui_Hum, -110);
    lv_obj_set_align(ui_Hum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Hum, "45");
    lv_obj_set_style_text_color(ui_Hum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Hum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Year = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Year, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Year, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Year, -82);
    lv_obj_set_y(ui_Year, -131);
    lv_obj_set_align(ui_Year, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Year, "2024");
    lv_obj_set_style_text_color(ui_Year, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Year, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Month = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Month, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Month, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Month, -28);
    lv_obj_set_y(ui_Month, -131);
    lv_obj_set_align(ui_Month, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Month, "02");
    lv_obj_set_style_text_color(ui_Month, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Month, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Day = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Day, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Day, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Day, 12);
    lv_obj_set_y(ui_Day, -131);
    lv_obj_set_align(ui_Day, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Day, "23");
    lv_obj_set_style_text_color(ui_Day, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Day, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Week = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Week, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Week, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Week, 100);
    lv_obj_set_y(ui_Week, -130);
    lv_obj_set_align(ui_Week, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Week, "五");
    lv_obj_set_style_text_color(ui_Week, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Week, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Week, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_uDay = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_uDay, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_uDay, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_uDay, -244);
    lv_obj_set_y(ui_uDay, -166);
    lv_obj_set_align(ui_uDay, LV_ALIGN_CENTER);
    lv_label_set_text(ui_uDay, "2024-02-23");
    lv_obj_set_style_text_color(ui_uDay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_uDay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_uDay, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextDay = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_TextDay, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TextDay, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TextDay, -211);
    lv_obj_set_y(ui_TextDay, -135);
    lv_obj_set_align(ui_TextDay, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TextDay, "多云");
    lv_obj_set_style_text_color(ui_TextDay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextDay, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextDay, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MinTemp = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_MinTemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MinTemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MinTemp, -235);
    lv_obj_set_y(ui_MinTemp, -105);
    lv_obj_set_align(ui_MinTemp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MinTemp, "-15");
    lv_obj_set_style_text_color(ui_MinTemp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MinTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MaxTemp = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_MaxTemp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MaxTemp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_MaxTemp, -197);
    lv_obj_set_y(ui_MaxTemp, -105);
    lv_obj_set_align(ui_MaxTemp, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MaxTemp, "30");
    lv_obj_set_style_text_color(ui_MaxTemp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_MaxTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_outHum = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_outHum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_outHum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_outHum, -197);
    lv_obj_set_y(ui_outHum, -76);
    lv_obj_set_align(ui_outHum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_outHum, "55");
    lv_obj_set_style_text_color(ui_outHum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_outHum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_weatherImg = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_weatherImg, &ui_img_cloudy_png);
    lv_obj_set_width(ui_weatherImg, 120);
    lv_obj_set_height(ui_weatherImg, 80);
    lv_obj_set_x(ui_weatherImg, -320);
    lv_obj_set_y(ui_weatherImg, -100);
    lv_obj_set_align(ui_weatherImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_weatherImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_weatherImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button1 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button1, 50);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, 350);
    lv_obj_set_y(ui_Button1, 180);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button1, &ui_img_ventilate_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button2, 50);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_x(ui_Button2, 280);
    lv_obj_set_y(ui_Button2, 180);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button2, &ui_img_curtain_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button3, 50);
    lv_obj_set_height(ui_Button3, 50);
    lv_obj_set_x(ui_Button3, 210);
    lv_obj_set_y(ui_Button3, 180);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button3, &ui_img_light_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Button3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -330);
    lv_obj_set_y(ui_Label1, -165);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "三天天气 :");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 16);
    lv_obj_set_y(ui_Label2, -130);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "年      月      日    星期");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label2, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, -194);
    lv_obj_set_y(ui_Label3, -105);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "~      ℃");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFAFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 290);
    lv_obj_set_y(ui_Label4, -110);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "℃");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label4, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 360);
    lv_obj_set_y(ui_Label5, -110);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "%");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, -320);
    lv_obj_set_y(ui_Label6, -210);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "武汉");
    lv_obj_set_style_text_color(ui_Label6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label6, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image1 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image1, &ui_img_battery_png);
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image1, 360);
    lv_obj_set_y(ui_Image1, -210);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image2 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image2, &ui_img_6g_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image2, 270);
    lv_obj_set_y(ui_Image2, -208);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image3 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image3, &ui_img_signal_png);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image3, 305);
    lv_obj_set_y(ui_Image3, -210);
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image5 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image5, &ui_img_location_png);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image5, -360);
    lv_obj_set_y(ui_Image5, -210);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image6 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image6, &ui_img_air_conditioner_png);
    lv_obj_set_width(ui_Image6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image6, 140);
    lv_obj_set_y(ui_Image6, 180);
    lv_obj_set_align(ui_Image6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_outline_color(ui_Image6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Image6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Image6, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Image6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image7 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image7, &ui_img_temperature_png);
    lv_obj_set_width(ui_Image7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image7, 280);
    lv_obj_set_y(ui_Image7, 80);
    lv_obj_set_align(ui_Image7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image8 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image8, &ui_img_humidity_png);
    lv_obj_set_width(ui_Image8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image8, 350);
    lv_obj_set_y(ui_Image8, 80);
    lv_obj_set_align(ui_Image8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button4 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button4, 150);
    lv_obj_set_height(ui_Button4, 100);
    lv_obj_set_x(ui_Button4, -300);
    lv_obj_set_y(ui_Button4, 50);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button4, &ui_img_back_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button5 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button5, 150);
    lv_obj_set_height(ui_Button5, 100);
    lv_obj_set_x(ui_Button5, -135);
    lv_obj_set_y(ui_Button5, 50);
    lv_obj_set_align(ui_Button5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button5, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button5, &ui_img_leave_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Button5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button6 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button6, 150);
    lv_obj_set_height(ui_Button6, 100);
    lv_obj_set_x(ui_Button6, -300);
    lv_obj_set_y(ui_Button6, 160);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button6, &ui_img_visitor_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button7 = lv_btn_create(ui_ScreenMain);
    lv_obj_set_width(ui_Button7, 150);
    lv_obj_set_height(ui_Button7, 100);
    lv_obj_set_x(ui_Button7, -135);
    lv_obj_set_y(ui_Button7, 160);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button7, lv_color_hex(0x686868), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_Button7, &ui_img_sleep_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Button7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Button7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image9 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image9, &ui_img_air_png);
    lv_obj_set_width(ui_Image9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image9, 135);
    lv_obj_set_y(ui_Image9, 80);
    lv_obj_set_align(ui_Image9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image9, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label13 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, 150);
    lv_obj_set_y(ui_Label13, 0);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "μg/m³");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label13, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image10 = lv_img_create(ui_ScreenMain);
    lv_img_set_src(ui_Image10, &ui_img_air_conditioner_panel_png);
    lv_obj_set_width(ui_Image10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image10, 30);
    lv_obj_set_y(ui_Image10, 150);
    lv_obj_set_align(ui_Image10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label16 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label16, -210);
    lv_obj_set_y(ui_Label16, -75);
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "湿度 :       %");
    lv_obj_set_style_text_color(ui_Label16, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label16, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label17 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label17, -240);
    lv_obj_set_y(ui_Label17, -35);
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "空气质量 : 优  紫外线 : 0  PM2.5 : 15");
    lv_obj_set_style_text_color(ui_Label17, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label17, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label17, &ui_font_Font1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label19 = lv_label_create(ui_ScreenMain);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label19, 4);
    lv_obj_set_y(ui_Label19, -180);
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, ":     :");
    lv_obj_set_style_text_color(ui_Label19, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label19, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label19, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

}