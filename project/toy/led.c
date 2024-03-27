#include <msp430.h>
#include "led.h"

// initialize leds off
void led_init()
{
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT &= ~LED_RED;        
}

// Turn green led on or off
void green_on(int on)
{
  if(on)
    P1OUT |= LED_GREEN;
  else
    P1OUT &= ~LED_GREEN;
}

// Turn red led on or off
void red_on(int on)
{
  if(on)
    P1OUT |= LED_RED;
  else
    P1OUT &= ~LED_RED;
}

// Toggle red led
void toggle_red()
{
  P1OUT ^= LED_RED;
}

// turn both leds on or off
void lights_on(int on)
{
  if(on)
    P1OUT |= LEDS;
  else
    P1OUT &= ~LEDS;
}
