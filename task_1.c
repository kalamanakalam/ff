#include <superkarel.h>

void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}

void jump_over_right() {
    turn_left();
    while (!right_is_clear()) { // Пока справа стена, двигайся вперед
        step();
    }
    turn_right();
    step();
    while (!right_is_clear()) { // Снова проверяем, пока справа стена
        step();
    }
    turn_right();
    step();
    while (!right_is_clear() && front_is_clear()) { // Двигаемся, пока справа стена и впереди ничего нет
        if (beepers_present()) { // Если есть бипер, останавливаемся
            return;
        }
        step();
    }
    turn_left();
}

void jump_over_left() {
    turn_right();
    while (!left_is_clear()) { // Пока слева стена, двигайся вперед
        step();
    }
    turn_left();
    step();
    while (!left_is_clear()) { // Снова проверяем, пока слева стена
        step();
    }
    turn_left();
    step();
    while (!left_is_clear() && front_is_clear()) { // Двигаемся, пока слева стена и впереди ничего нет
        if (beepers_present()) { // Если есть бипер, останавливаемся
            return;
        }
        step();
    }
    turn_right();
    if (beepers_present()) { // Еще раз проверяем наличие бипера
        return;
    }
}

int main() {
    turn_on("task_1.kw");  // Включаем задачу
    set_step_delay(20);     // Устанавливаем задержку для видимости шагов

    put_beeper();           // Ставим бипер для ориентира

    // Пытаемся перепрыгнуть вправо до тех пор, пока не встретим бипер
    while (true) {
        jump_over_right();
        if (beepers_present()) { // Как только находим бипер, останавливаемся
            break;
        }
    }
    
    pick_beeper();  // Подбираем найденный бипер
    turn_right();   // Поворачиваем направо
    
    // Пытаемся перепрыгнуть влево до тех пор, пока не встретим бипер
    while (true) {
        jump_over_left();
        if (beepers_present()) { // Как только находим бипер, останавливаемся
            break;
        }
    }
    
    pick_beeper();  // Подбираем найденный бипер

    turn_off();     // Завершаем работу программы
    return 0;
}