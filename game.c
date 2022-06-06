#include <stdio.h>
#include "game.h"
char color[4] = {'W', 'O', 'B', 'R'};
t_tile bag[106];
t_tile players[4][106];

void debug_game(int nb_players)
{
    printf("Bag content :\n");
    for (int i = 0; i < 106; i++)
    {
        printf("%d : %d(%c)\n", i, bag[i].number, bag[i].color);
    }

    for (int j = 0; j < nb_players; j++)
    {
        printf("Player %d rack content :\n", j + 1);
        for (int i = 0; i < 106; i++)
        {
            printf("%d : %d(%c)\n", i, players[j][i].number, players[j][i].color);
        }
    }
}

void print_game(int nb_players)
{
    printf("Bag content :\n");
    int j = 0;
    for (int i = 0; i < 106; i++)
    {
        if (bag[i].number > -1)
        {
            if (bag[i].number > -1)
            {
                printf("%d : %d(%c)\n", i, bag[i].number, bag[i].color);
                j++;
            }
        }
    }
    if (j == 0)
        printf("Rack umpty\n");
    else
        printf("Number of tiles : %d\n", j);
    for (int j = 0; j < nb_players; j++)
    {
        int k = 0;
        printf("Player %d rack content :\n", j + 1);
        for (int i = 0; i < 106; i++)
        {
            if (players[j][i].number > -1)
            {
                k++;
                printf("%d : %d(%c)\n", i, players[j][i].number, players[j][i].color);
            }
        }
        if (k == 0)
            printf("Rack umpty\n");
        else
            printf("Number of tiles : %d\n", k);
    }
}

void fill_bag(void)
{
    int j = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int number = 1; number < 14; number++)
        {
            for (int c = 0; c < 4; c++)
            {
                bag[j].number = number;
                bag[j].color = color[c];
                j++;
            }
        }
    }
    // jokers
    for (int i = 0; i < 2; i++)
    {
        bag[j].number = 0;
        bag[j].color = 'X';
        j++;
    }
}

void init_racks(int nb_players)
{
    for (int i = 0; i < nb_players; i++)
    {
        for (int j = 0; j < 106; j++)
        {
            players[i][j].number = -1;
            players[i][j].color = 'X';
        }
    }
}

void init_game(int nb_players)
{
    fill_bag();
    init_racks(nb_players);
    print_game(nb_players);
}

void start_game(int nb_players)
{
    printf("Game started !\n");
    init_game(nb_players);
}
