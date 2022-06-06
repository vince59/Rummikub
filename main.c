#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void usage()
{
    printf("Usage  : rummik nb_players\n");
    printf("Sample : rummik 4\n");
    printf("number of players must be between 2 and 4\n");
}

int main(int argc, char *argv[])
{
    printf("Rummikub V1.0 !\n");
    if (argc != 2)
    {
        printf("Bad argument number !\n");
        usage();
        exit(EXIT_SUCCESS);
    } 
    int nb_players = atoi(argv[argc-1]);
    if (nb_players>4 || nb_players<2)
    {
        printf("Bad player number !\n");
        usage();
        exit(EXIT_SUCCESS);
    }
    printf("Number of players : %i\n", nb_players);
    start_game(nb_players);
}