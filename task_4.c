#include <superkarel.h>
void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void turn_back(){
    turn_left();    
    turn_left();
}


int main(){
    turn_on("task_4.kw");    
    set_step_delay(20);
    turn_left();    
    while(front_is_clear()){        
        if (beepers_present()) pick_beeper();
        step();    
    }
    turn_right();    
    if (front_is_clear()){        
        turn_right();
        while(front_is_clear()){            
            if (!beepers_present()) put_beeper();
            step();        
        }
        if (!beepers_present()) put_beeper();    
        }
        turn_left();
    while(front_is_clear()){        
        step();
        turn_left();        
        if (beepers_present())pick_beeper();
        while(front_is_clear()){            
            step();
            if (beepers_present()) pick_beeper();
        }        //UP
        if (left_is_clear()&&right_is_clear()){            
            turn_back();
            while(front_is_clear()){                
                put_beeper();
                step();            
            }
            put_beeper();        
        }else{
            turn_back();            
            while(front_is_clear()){
                step();           
            }
        }        
        turn_left();
    }
    turn_left();
    while(front_is_clear())step();    
    turn_left();
    if (front_is_clear()){        
        turn_left();
        while(front_is_clear()){            
            put_beeper();
            step();        
        }
        put_beeper();    
    }else{
        turn_left();        
        while(front_is_clear()){
            step();        
        }
    }    
    turn_left();
    turn_off();    
    return 0;
}