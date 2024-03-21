## 源码结构

```
lvgl_demo
├── app                # 应用源码
|    ├── cJSON         # cJSON 解析器
|    ├── protocol      # 自定义通信协议
|    ├── socket        # socket 源码
|    ├── application.c # 主要应用
|    ├── button.c      # 按键应用
|    ├── def.h         # 一些定义
|    └── weather.c     # 天气应用
├── lv_drivers         # LVGL 驱动源码
├── lvgl               # LVGL 源码
├── ui                 # UI 设计源码
├── lv_conf.h          # LVGL 库配置文件
├── lv_drv_conf.h      # LVGL 驱动配置文件
├── main.c             # main.c 文件
├── Makefile           # Makefile 文件
└── README.md          # README 文件
```

注意：lvgl 和 lv_drivers 源码体积较大，自行下载:

- [lvgl](https://github.com/lvgl/lvgl/releases/tag/v8.3.11)
- [lv_drivers](https://github.com/lvgl/lv_drivers/releases/tag/v8.3.0)