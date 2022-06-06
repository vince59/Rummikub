#ifndef GAME_H
#define GAME_H

struct s_tile 
{
    int number;
    char color;
};

typedef struct s_tile t_tile;

struct s_rack_info 
{
    int score;
    int tile_number;
};

typedef struct s_rack_info t_rack_info;

void start_game(int);

#endif