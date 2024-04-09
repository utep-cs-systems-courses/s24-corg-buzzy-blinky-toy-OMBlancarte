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


void song_1()
{
  int length = 12;
  static int index1 = 0;
  int notes[12] = {4000, 4000, 4000, 3100, 3100, 3100, 2700, 2700, 2700, 4600, 4600, 4600};
  if(index1 == length){
    index1 = 0;
  }
  else{
    buzzer_set_period(notes[index1]);
    index1++;
  }
}

void song_2()
{
  int length = 24;
  static int index2 = 0;
  int notes[24] = {1220, 1260, 1330, 1440, 1490, 1330, 1260, 1490, 1520,
		   1330, 1260, 1520, 1370, 1290, 1220, 1370, 1330, 1260,
		   1220, 1260, 1260, 1330, 1260, 1220};
  if(index2 == length){
    index2 = 0;
  }
  else {
    buzzer_set_period(notes[index2]);
    index2++;	      
  }
}

void song_3()
{
  int length = 112;
  static int index3 = 0;
  int notes[112] = {
    1864, 1244,  987, 830, 1661, 1244,  987, 830, 1480, 1244,  987, 830, 1661, 1244,  987, 830,
    1661, 1108,  932, 739, 1480, 1108,  932, 739, 1318, 1108,  932, 739, 1480, 1108,  932, 739,
    1661,  987,  830, 659, 1318,  987,  830, 659, 1244,  987,  830, 659, 1318,  987,  830, 659,
    1318,  932,  739, 622, 1244,  932,  739, 622, 1108,  932,  739, 622, 1244,  932,  739, 622,
    1864, 1244,  987, 830, 1661, 1244,  987, 830, 1480, 1244,  987, 830, 1661, 1244,  987, 830,
    1975, 1318, 1108, 783, 1864, 1318, 1108, 783, 1661, 1318, 1108, 783, 1864, 1318, 1108, 783,
    2217, 1244,  987, 783, 1875, 1244,  987, 783, 1864, 1244,  987, 783, 1975, 1244,  987, 783,
    //1864,  987//,  783, 659, 1568,  987,  783, 659, 1480,  987,  783, 659, 1318,  987,  783, 659
  };
  if(index3 == length){
    index3 = 0;
  }
  else{
    buzzer_set_period(notes[index3]);
    index3++;
  }
}
