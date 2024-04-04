#ifndef led_include
#define led_include

// New msp430, leds are linked to correct bits
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)


void led_init();
void green_on(int on);
void red_on(int on);
void toggle_red();
void toggle_green();
void lights_on(int on);


#endif // included
