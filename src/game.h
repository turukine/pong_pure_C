// game.h
#ifndef GAME_H
#define GAME_H

// Определение констант
#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3

// Объявление функций
void draw();
void input();
// Объявление внешних переменных
extern int paddle1_y;
extern int paddle2_y;
extern int ball_x;
extern int ball_y;
extern int score1;
extern int score2;

#endif
