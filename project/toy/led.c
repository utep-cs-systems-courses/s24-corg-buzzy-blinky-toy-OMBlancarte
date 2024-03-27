#include <msp430.h>
#include "led.h"

// initialize leds
void led_init()
{
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |=LED_RED;        // Red led is on
}

// turn green led on
void green_on()
{
  P1OUT &= ~LEDS;
  P1OUT |= LED_GREEN;
}

// turn red led on
void red_on()
{
  P1OUT &= ~LEDS;
  P1OUT|= LED_RED;
}

// turn both leds on
void lights_on()
{
  P1OUT &= ~LEDS;
  P1OUT |= LEDS;
}
