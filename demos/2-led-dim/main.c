//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

void green(int on)
{
  if(on)
    P1OUT |= LED_GREEN;
  else
    P1OUT &= ~LED_GREEN;
}

#define LED_BRIGHT 0
#define LED_DIM 1
#define LED_OFF 2
#define LED_MAX 2
static char bright_state = LED_OFF;

void
update_dim_green()
{
  static int flashState = 0;
  switch (bright_state) {
  case LED_DIM:
    switch (flashState) {
    case 0: flashState = 1; break;
    case 1: flashState = 2; break;
    case 2: flashState = 3; break;
    case 3: flashState = 4; break;
    }
    green(flashState == 0);
    break;
  case LED_BRIGHT: green(1); break;
  case LED_OFF: green(0); break;
  }
}

// Called once every second
void
sec() 
{
  bright_state++;
  if(bright_state >= LED_MAX)
    bright_state = 0;
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  update_250th();
  update_dim_green();
} 

void update_250th()
{
  static int sec_count = 0;
  sec_count++;
  if(sec_count == 250){
    sec_count = 0;
    sec();
  }
}
