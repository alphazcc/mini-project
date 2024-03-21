#ifndef __DEF_H__
#define __DEF_H__

#define AHT20 0x01
#define ADC 0x02
#define LED_RYG 0x03

#define LED_R 0x1
#define LED_Y 0x2
#define LED_G 0x3

#define LED_ON 0x1
#define LED_OFF 0x0

#define _EXPORT_FUNC(function)     \
    do                             \
    {                              \
        extern int function(void); \
        function();                \
    } while (0)

#endif
