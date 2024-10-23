#include <karel.h>

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

void turn_back() {
    turn_left();
    turn_left();
}

bool right_is_blocked() {
    turn_right();
    bool result = !front_is_clear();
    turn_left();
    return result;
}

void check_line() {
    if (front_is_clear() && !beepers_present()) {
        step();
        check_line();
    } else {
        turn_back();
        if (beepers_present()) {
            pick_beeper();
        }
    }
    
    if (front_is_clear()) {
        step();
    }
}

void check() {
    if (right_is_blocked()) {
        turn_left();
        
        while (front_is_clear() && beepers_present()) {
            step();
        }
        turn_right();

        while (front_is_clear()) {
            check_line();
            if (front_is_clear()) {
                turn_back();
                step();
            } else {
                turn_back();
            }
            
            if (beepers_in_bag()) {
                put_beeper();
                turn_left();
                if (front_is_clear()) {
                    step();
                }
                turn_right();
            } else {
                turn_left();
                break;
            }
        }

        turn_back();
        while (front_is_clear()) {
            step();
        }
        turn_left();
    }
}

void move_to_wall() {
    while (front_is_clear()) {
        step();
    }
}

void align_with_left_wall() {
    while (front_is_clear()) {
        turn_left();
    }
    turn_back();
}

int main() {
    turn_on("task_3_1.kw");
    set_step_delay(20);
    
    align_with_left_wall();
    move_to_wall();
    turn_back();
    
    while (front_is_clear()) {
        check();
        step();
    }

    turn_off();
    return 0;
}