#include <superkarel.h>
bool beepers_right(){
    turn_left();
    turn_left();
    turn_left();
    if (front_is_clear()){
        step();
        turn_left();
        turn_left();
        if (beepers_present()){
            step();
            turn_left();
            turn_left();
            turn_left();
            return true;}
        else{
            step();
            turn_left();
            turn_left();
            turn_left();
            return false;
        }
    }else{
        turn_left();
        return false;
    }

}
void move_recurs(){
 if (front_is_clear()&&no_beepers_present()){
 step();
 move_recurs();
}else{turn_left();turn_left();if(beepers_present())pick_beeper();}
 if (front_is_clear()){step();
  
 }
}

int main(){
    turn_on("task_3.kw");
    set_step_delay(50);
    while (!facing_east())turn_left();
    while(front_is_clear())step();
    turn_left();
    turn_left();
    while(front_is_clear()){
        if (right_is_clear()) step();
        else 
        {
            turn_left();
            while(beepers_present()){
                if (front_is_clear())step();
            }
            while(no_beepers_present()){
                turn_left();
                turn_left();
                turn_left();
   
  
    move_recurs();
    if (front_is_clear()){turn_left();
  turn_left();
  step();
  }else {
  turn_left();
  turn_left();
  }
  
                if (no_beepers_present() && beepers_in_bag()) put_beeper();
                turn_left();
                if (front_is_clear())step();
    else break;
            }
            turn_left();
            turn_left();

            while(front_is_clear())step();
            turn_left();
  
  if (front_is_clear()) step();


        }

    }
            turn_left();
            turn_left();
    turn_off();
    return 0;
}