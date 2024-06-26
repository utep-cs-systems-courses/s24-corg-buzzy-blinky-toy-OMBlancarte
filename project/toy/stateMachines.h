#ifndef stateMachine_included
#define stateMachine_included

// supported states
enum State{
  START = 0,
  SIREN = 1,
  SONG1 = 2,
  SONG2 = 3,
  SONG3 = 4
};


// external variables
extern enum State current_state;
extern int sec_count;
extern int sec_flag;

void start_state();
void siren_state();
void song1_state();
void song2_state();
void song3_state();
void update_250th();
void sec();

#endif // included
