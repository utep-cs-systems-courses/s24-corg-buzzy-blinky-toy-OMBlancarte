#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


enum State current_state = START;
int update_sec = 0;
int sec_flag = 0;


// 250 interrupts/sec
void update_250th()
{
  update_sec++;
  if(update_sec == 25) {
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
  if(sec_flag){
    toggle_red();
    sec_flag = 0;
  }
}


// Siren state: creates a siren type sound
void siren_state()
{
  if(sec_flag){
    toggle_red();
    toggle_green();
    siren_sound();
    sec_flag = 0;      // reset sec_flag
  }
}

void song1_state()
{
  if(sec_flag){
    song_1();
    toggle_green();
    sec_flag = 0;       // reset sec_flag
  }
}

void song2_state()
{
  if(sec_flag){
    song_2();
    toggle_green();
    sec_flag = 0;       // reset sec_flag
  }
}

void song3_state()
{
  if(sec_flag){
    song_3();
    sec_flag = 0;       // rest sec_flag
  }
}
