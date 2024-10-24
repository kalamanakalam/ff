#include <superkarel.h>

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

bool right_is_blocked() {
    turn_right();
    if (!front_is_clear()) {
        turn_left();
        return true;
    }
    turn_left();
    return false;
}

bool left_is_blocked() {
    turn_left();
    if (!front_is_clear()) {
        turn_right();
        return true;
    }
    turn_right();
    return false;
}

void jump_over_right() {
    turn_left();
    while (right_is_blocked()) {
        if (!front_is_clear()) {  // Проверяем, если впереди стена
            turn_left();
            return;  // Выходим, если тупик
        }
        step();
    }
    turn_right();
    step();
    while (right_is_blocked()) {
        if (!front_is_clear()) {  // Проверяем, если впереди стена
            turn_right();
            return;  // Выходим, если тупик
        }
        step();
    }
    turn_right();
    step();
    while (right_is_blocked() && front_is_clear()) {
        if (beepers_present()) {
            return;  // Остановимся, если нашли бипер
        }
        step();
    }
    turn_left();
}

void jump_over_left() {
    turn_right();
    while (left_is_blocked()) {
        if (!front_is_clear()) {  // Проверяем, если впереди стена
            turn_right();
            return;  // Выходим, если тупик
        }
        step();
    }
    turn_left();
    step();
    while (left_is_blocked()) {
        if (!front_is_clear()) {  // Проверяем, если впереди стена
            turn_left();
            return;  // Выходим, если тупик
        }
        step();
    }
    turn_left();
    step();
    while (left_is_blocked() && front_is_clear()) {
        if (beepers_present()) {
            return;  // Остановимся, если нашли бипер
        }
        step();
    }
    turn_right();
    if (beepers_present()) {
        return;  // Остановимся, если нашли бипер
    }
}

int main() {
    turn_on("task_1.kw");
    set_step_delay(20);
    put_beeper();
    
    // Пытаемся прыгнуть через препятствие справа
    while (!beepers_present()) {
        jump_over_right();  // Прыжок через препятствие справа
    }
    
    pick_beeper();
    turn_right();
    
    // Пытаемся прыгнуть через препятствие слева
    while (!beepers_present()) {
        jump_over_left();  // Прыжок через препятствие слева
    }
    
    pick_beeper();
    turn_off();
    return 0;
}