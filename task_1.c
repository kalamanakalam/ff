#include <karel.h>

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

bool right_is_blocked() {
    turn_right();
    bool result = !front_is_clear();
    turn_left();
    return result;
}

bool left_is_blocked() {
    turn_left();
    bool result = !front_is_clear();
    turn_right();
    return result;
}

void jump_over_right() {
    turn_left();
    while (right_is_blocked()) {
        step();
    }
    turn_right();
    step();
    while (right_is_blocked()) {
        step();
    }
    turn_right();
    step();
    while (right_is_blocked() && front_is_clear()) {
        if (beepers_present()) {
            pick_beeper();
            return;
        }
        step();
    }
    turn_left();
}

void jump_over_left() {
    turn_right();
    while (left_is_blocked()) {
        step();
    }
    turn_left();
    step();
    while (left_is_blocked()) {
        step();
    }
    turn_left();
    step();
    while (left_is_blocked() && front_is_clear()) {
        if (beepers_present()) {
            pick_beeper();
            return;
        }
        step();
    }
    turn_right();
    if (beepers_present()) {
        pick_beeper();
    }
}

int main() {
    turn_on("task_1.kw");
    set_step_delay(20);
    put_beeper();

    while (!beepers_present()) {
        jump_over_right();
    }

    pick_beeper();
    turn_right();

    while (!beepers_present()) {
        jump_over_left();
    }

    pick_beeper();
    turn_off();
    return 0;
}
