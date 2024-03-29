#ifndef led_include
#define led_include

// Corrected Led P1.0 and P1.6 are switched
#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)


void led_init();
void green_on(int on);
void red_on(int on);
void toggle_red();
void toggle_green();
void lights_on(int on);


#endif // included
