#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

int main() {
  configureClocks();
  enableWDTInterrupts();
  led_init();
  switch_init();
  buzzer_init();
  

  or_sr(0x18);          // CPU off, GIE on

}
