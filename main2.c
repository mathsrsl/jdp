//
// Created by maths on 10/25/23.
//
#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>

#include "carte.h"

#define LONGUEUR 8
#define LARGEUR 10
#define TAILLE_DECK 12


int main()
{
    printf("Valide ");
    Carte c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12 = {NULL};
    Carte deck[TAILLE_DECK];//malloc(12 * sizeof(Carte))
    printf("Valide ");
    char * lettre = "AABBCCDDEEFF";
    if(deck != NULL)
    {
        for(int j = 0;j < TAILLE_DECK;j++)
        {
            //deck[j] =malloc(sizeof(Carte));
            deck[0] = c1;
            deck[1] = c2;
            deck[2]= c3;
            deck[3] = c4;
            deck[4] = c5;
            deck[5] = c6;
            deck[6] = c7;
            deck[7] = c8;
            deck[8] = c9;
            deck[9] = c10;
            deck[10] = c11;
            deck[11] = c12;
        }
    }else
    {
        return -2;
    }
    printf("Valide ");

    initscr();
    printf("Valide ");
    while(1)
    {
        for(int i = 0;i < TAILLE_DECK;i++)
        {
            printf("Valide ");
            AttributsInit(deck[i],0);
            printf("Valide");
            DisplayCard(deck[i],LONGUEUR,LARGEUR,deck[i].etat,i);
            printf("Valide");
            LettreAlea(deck,lettre,TAILLE_DECK);
            printf("Valide");
        }

        refresh();
        if(getch() != 410)
            break;
        usleep(10000);
    }

    endwin();
    return 0;
}
