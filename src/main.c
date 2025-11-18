#include <stdio.h>
#include <stdlib.h>
#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define BALL_SIZE 1

int main() {
    int paddle1_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    int paddle2_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;
    int ball_dx = 1;
    int ball_dy = 1;
    int score1 = 0;
    int score2 = 0;

    while (1) {
        system("clear");

        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                // Верхняя и нижняя стенки
                if (y == 0 || y == HEIGHT - 1) {
                    printf("-");
                }
                // Левая ракетка
                else if (x == 0 && y >= paddle1_y && y < paddle1_y + PADDLE_SIZE) {
                    printf("|");
                }
                // Правая ракетка
                else if (x == WIDTH - 1 && y >= paddle2_y && y < paddle2_y + PADDLE_SIZE) {
                    printf("|");
                }
                // Мячик
                else if (x == ball_x && y == ball_y) {
                    printf("O");
                }
                // Пустое пространство
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Player 1: %d\tPlayer 2: %d\n", score1, score2);

        // Движение мяча
        ball_x += ball_dx;
        ball_y += ball_dy;

        // Отскок от верхней и нижней стенок
        if (ball_y <= 1 || ball_y >= HEIGHT - 2) {
            ball_dy = -ball_dy;
        }

        // Отскок от ракеток
        if (ball_x == 1 && ball_y >= paddle1_y && ball_y < paddle1_y + PADDLE_SIZE) {
            ball_dx = -ball_dx;
        }
        if (ball_x == WIDTH - 2 && ball_y >= paddle2_y && ball_y < paddle2_y + PADDLE_SIZE) {
            ball_dx = -ball_dx;
        }

        // Подсчет очков
        if (ball_x <= 0) {
            score2++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_dx = 1;
        }
        if (ball_x >= WIDTH - 1) {
            score1++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_dx = -1;
        }

        // Проверка победы
        if (score1 == 21) {
            printf("Игрок 1 ПОБЕДИЛ!\n");
            break;
        }
        if (score2 == 21) {
            printf("Игрок 2 ПОБЕДИЛ!\n");
            break;
        }

        // Управление
        char key = getchar();
        if (key == 'a' && paddle1_y > 1) paddle1_y--;  // Учитываем стенку сверху
        if (key == 'z' && paddle1_y < HEIGHT - PADDLE_SIZE - 1) paddle1_y++;  // Учитываем стенку снизу
        if (key == 'k' && paddle2_y > 1) paddle2_y--;
        if (key == 'm' && paddle2_y < HEIGHT - PADDLE_SIZE - 1) paddle2_y++;
    }

    return 0;
}