#include <stdlib.h>
#include <stdio.h>

#include "carte.h"


void AttributsInit(Carte c,unsigned int etat)
{
    c.etat = etat;
}

void DisplayCard(Carte c,int longeur,int largeur,unsigned int etat,int numCard)
{
    c.carte = subwin(stdscr,longeur,largeur,PosCardX(numCard),PosCardY(numCard));
    wborder(c.carte,'|','|','-','-',' ',' ',' ',' ');
}

int PosCardX(int numCard)
{
    switch(numCard)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return 1;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            return 13;
            break;
    }
}

int PosCardY(int numCard)
{
    switch(numCard)
    {
        case 0:
            return 1;
            break;
        case 1:
            return 12;
            break;
        case 2:
            return 23;
            break;
        case 3:
            return 34;
            break;
        case 4:
            return 45;
            break;
        case 5:
            return 56;
            break;
        case 6:
            return 1;
            break;
        case 7:
            return 12;
            break;
        case 8:
            return 23;
            break;
        case 9:
            return 34;
            break;
        case 10:
            return 45;
            break;
        case 11:
            return 56;
            break;
    }
}

void LettreAlea(Carte deck[],char * lettre,int taille)
{
    srand(time(NULL));
    int index = 0;
    char temp;

    for(int i = taille - 1;i>=2;i--)
    {
        index = rand() %i;
        deck[taille -i -1].var = lettre[index];
        temp = lettre[i];
        lettre[i] = lettre[index];
        lettre[index] = temp;
    }

    deck[0].var = lettre[1];
    deck[1].var = lettre[0];
}
