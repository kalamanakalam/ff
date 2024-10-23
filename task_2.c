#include <superkarel.h>
#define SPEED 100

void turn_right();

void go();

void turn_back();

int main () {
        turn_on("task_2.kw");
        set_step_delay(100);
        
        while (true){
        go();
        if (right_is_blocked() && left_is_blocked() && front_is_blocked()){
            break;}
        }


        turn_off();
        return 0;
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(SPEED);
    turn_left();
    } 
void turn_back(){
        turn_left();
        turn_left();
        }
void go(){
    while (front_is_clear()){
            if(!beepers_present()) {step();}
            
            if (beepers_present()){
            pick_beeper();
            turn_back();
            step();
            
            }
            while (left_is_clear()){
            turn_left();
            step();
             }
            while(right_is_clear()){
                    turn_right();
                    step();}

}                        
}
