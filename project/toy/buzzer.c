#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
  */
  
  timerAUpmode();           /* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;             /* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) // buzzer clock = 2MHz.  (period of 1k results in 2kHz tone)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */
}


void siren_sound()
{
  const int MAX = 6000;             // Max note frequency
  const int MIN = 200;              // Minimum note frequency
  static int increment = 200;       // Incrementer for current note
  static int current_note = 1000;   // Current note frequency

  // When current note reaches MAX, incrementer subtracts. When it reaches MIN, incrementer adds 
  if(current_note == MAX){          
    increment = -200;
  }
  else if(current_note == MIN){
    increment = 200;
  }
  buzzer_set_period(current_note);
  current_note += increment;
}
