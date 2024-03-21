// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_ScreenMain
void ui_ScreenMain_screen_init(void);
lv_obj_t * ui_ScreenMain;
lv_obj_t * ui_TimeHour;
lv_obj_t * ui_TimeMin;
lv_obj_t * ui_TimeSec;
lv_obj_t * ui_Air;
lv_obj_t * ui_AirValue;
lv_obj_t * ui_SliderTemp;
lv_obj_t * ui_SliderHum;
lv_obj_t * ui_Temp;
lv_obj_t * ui_Hum;
lv_obj_t * ui_Year;
lv_obj_t * ui_Month;
lv_obj_t * ui_Day;
lv_obj_t * ui_Week;
lv_obj_t * ui_uDay;
lv_obj_t * ui_TextDay;
lv_obj_t * ui_MinTemp;
lv_obj_t * ui_MaxTemp;
lv_obj_t * ui_outHum;
lv_obj_t * ui_weatherImg;
lv_obj_t * ui_Button1;
lv_obj_t * ui_Button2;
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Image6;
lv_obj_t * ui_Image7;
lv_obj_t * ui_Image8;
lv_obj_t * ui_Button4;
lv_obj_t * ui_Button5;
lv_obj_t * ui_Button6;
lv_obj_t * ui_Button7;
lv_obj_t * ui_Image9;
lv_obj_t * ui_Label13;
lv_obj_t * ui_Image10;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Label17;
lv_obj_t * ui_Label19;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_[40] = {&ui_img_icons_00_png, &ui_img_icons_01_png, &ui_img_icons_02_png, &ui_img_icons_03_png, &ui_img_icons_04_png, &ui_img_icons_05_png, &ui_img_icons_06_png, &ui_img_icons_07_png, &ui_img_icons_08_png, &ui_img_icons_09_png, &ui_img_icons_10_png, &ui_img_icons_11_png, &ui_img_icons_12_png, &ui_img_icons_13_png, &ui_img_icons_14_png, &ui_img_icons_15_png, &ui_img_icons_16_png, &ui_img_icons_17_png, &ui_img_icons_18_png, &ui_img_icons_19_png, &ui_img_icons_20_png, &ui_img_icons_21_png, &ui_img_icons_22_png, &ui_img_icons_23_png, &ui_img_icons_24_png, &ui_img_icons_25_png, &ui_img_icons_26_png, &ui_img_icons_27_png, &ui_img_icons_28_png, &ui_img_icons_29_png, &ui_img_icons_30_png, &ui_img_icons_31_png, &ui_img_icons_32_png, &ui_img_icons_33_png, &ui_img_icons_34_png, &ui_img_icons_35_png, &ui_img_icons_36_png, &ui_img_icons_37_png, &ui_img_icons_38_png, &ui_img_icons_99_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenMain_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_ScreenMain);
}
