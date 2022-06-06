#ifndef GAME_H
#define GAME_H

struct s_tile 
{
    int number;
    char color;
};

typedef struct s_tile t_tile;

void start_game(int);

#endif