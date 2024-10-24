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

void sides_check() {
    turn_left();
    if (front_is_clear()) {
        turn_back();
        if (front_is_clear()) {
            turn_left();
            move_to_wall(); // Если с обеих сторон есть проход, идём вперед
        } else {
            turn_left();
            move_to_wall(); // Возвращаемся назад
        }
    } else {
        turn_right();
    }
}

void right_wall_check() {
    turn_right();
    if (front_is_clear()) {
        turn_left();
    } else {
        turn_left();
        move_to_wall(); // Проверяем, есть ли проход справа
    }
}

int main() {
    turn_on("task_4.kw");  // Загружаем задачу
    set_step_delay(20);     // Устанавливаем задержку для видимости шагов
    turn_left();            // Поворачиваем налево

    while (front_is_clear()) {
        if (beepers_present()) {
            pick_beeper();  // Собираем бипер
        }
        step();
    }
    
    turn_right();  // Поворачиваем направо
    
    if (front_is_clear()) {
        turn_right();
        while (front_is_clear()) {
            if (!beepers_present()) {
                put_beeper();  // Ставим бипер, если его нет
            }
            step();
        }
        if (!beepers_present()) {
            put_beeper();
        }
    }
    
    turn_left();
    while (front_is_clear()) {
        step();
        turn_left();
        if (beepers_present()) {
            pick_beeper();
        }
        while (front_is_clear()) {
            step();
            if (beepers_present()) {
                pick_beeper();
            }
        }

        // Поднимаемся вверх, если есть проходы по сторонам
        sides_check();
        
        if (front_is_clear()) {
            turn_back();
            while (front_is_clear()) {
                put_beeper();
                step();
            }
            put_beeper();
        } else {
            turn_back();
            move_to_wall();
        }

        turn_left();
    }
    
    turn_left();
    move_to_wall();
    turn_left();
    
    if (front_is_clear()) {
        turn_left();
        while (front_is_clear()) {
            put_beeper();
            step();
        }
        put_beeper();
    } else {
        turn_left();
        move_to_wall();
    }
    
    turn_left();
    turn_off();
    return 0;
}
