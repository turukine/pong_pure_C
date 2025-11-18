#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void draw() {
    system("clear"); // обновляем отображение игры (из библиотеки <stdlib.h)
    for (int y = 0; y < HEIGHT; y++) { //рисуем поле по размерам HEIGHT и WIDTH
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 && y >= paddle1_y && y < paddle1_y + PADDLE_SIZE) // отображаем левую ракетку
                printf("|");
            else if (x == WIDTH - 1 && y >= paddle2_y && y < paddle2_y + PADDLE_SIZE) //отображаем правую ракетку
                printf("|");
            else if (x == ball_x && y == ball_y) // мячик
                printf("O");
            else
                printf(" "); //все остальное поле
        }
        printf("\n");
    }

    printf("Игрок 1: %d    Игрок 2: %d\n", score1, score2);// счет 
    printf("нажмите enter чтобы играть (покадрово)\n");
}
