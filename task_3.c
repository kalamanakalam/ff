#include <superkarel.h>

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

void turn_back() {
    turn_left();
    turn_left();
}

void move_to_wall() {
    while (front_is_clear()) {
        step();
    }
}

void check_line() {
    if (front_is_clear()) {
        if (!beepers_present()) {
            step();
            check_line();
        } else {
            pick_beeper();
            turn_back();
            move_to_wall();
        }
    } else {
        turn_back();
        move_to_wall();
    }
}

void check() {
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
    move_to_wall();
    turn_left();
}

void align_with_left_wall() {
    while (!left_is_clear()) {
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