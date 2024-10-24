#include <superkarel.h>
int beepers_in_place(){
 if (beepers_present()){
  pick_beeper();

  while (!facing_north()) turn_left();
  if (no_beepers_present()) return 1;
  else{
   pick_beeper(); turn_left();
  if (no_beepers_present()) return 2;
  else{
pick_beeper(); turn_left();
  if (no_beepers_present()) return 3;
  else{
pick_beeper(); turn_left();
  if (no_beepers_present()) return 4;
  else{
pick_beeper(); turn_left();
  if (no_beepers_present()) return 5;
  }
  }
  }
  }}
return 0;

}
int main(){
 turn_on("task_6.kw");
 set_step_delay(20);
 while (!beepers_present()){
  step();
  if (beepers_in_place()==5) break;
 }
    turn_off();
    return 0;
}