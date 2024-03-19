#ifndef led_included
#define led_included

#define LED_RED BIT6               // P1.0 Corrected 
#define LED_GREEN BIT0             // P1.6
#define LEDS (BIT0 | BIT6)

void green(int on);
void update_dim_green();
void update_250th();

#endif // included
