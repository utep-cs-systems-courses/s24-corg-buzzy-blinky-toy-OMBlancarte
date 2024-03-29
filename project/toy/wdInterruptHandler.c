#include <msp430.h>
#include "stateMachines.h"

void __interrupt_vec(WDT_VECTOR) WDT()     // 250 interrupts/sec
{
  update_250th();
  switch (current_state) {
  case START:                // Start state: Blinking red led
    start_state();
    break;
  case SIREN:
    siren_state();
    break;
  }

}
