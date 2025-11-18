#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void input() {
    char key;
    while (1) {
        key = getchar(); // Ждем ввода
        if (key == '\n' || key == 'k') // Если нажат Enter, выходим из цикла
            break;
        if (key == 'a' && paddle1_y > 0)
            paddle1_y--;
        if (key == 'z' && paddle1_y < HEIGHT - PADDLE_SIZE)
            paddle1_y++;
        if (key == 'k' && paddle2_y > 0)
            paddle2_y--;
        if (key == 'm' && paddle2_y < HEIGHT - PADDLE_SIZE)
            paddle2_y++;
    }
}