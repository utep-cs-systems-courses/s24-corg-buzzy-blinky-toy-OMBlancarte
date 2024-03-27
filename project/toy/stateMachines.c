#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

enum State current_state = START;
int update_sec = 0;
int sec_flag = 0;

// 250 interrupts/sec
void update_250th()
{
  update_sec++;
  if(update_sec == 250) {
    update_sec = 0;
    sec();
  }
}

// Toggles the sec_flag when sec_count is equal to 250
void sec()
{
  sec_flag = sec_flag == 0 ? 1 : 0;
}

// Start state: toggles red light every sec when the sec_flag is on
void start_state()
{
  if(sec_flag)
    toggle_red();
}
