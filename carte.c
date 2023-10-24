#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>

#include "carte.h"

#define LARGEUR_CARTE 7
#define LONGUEUR_CARTE 11
#define NB_CARD 12

typedef struct Carte Carte;

struct Carte{
    WINDOW *carte;
    unsigned int cursor;
    char var;
    bool etat;
};

void defineCard(Carte c, int largeur, int longueur, int cursor, char var, bool etat, int posx, int posy);

int DisplayCard()
{
    //Definition des cartes et ajouts des cartes dans le tableau
    Carte c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12 = {NULL};
    Carte deck[NB_CARD] = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12};
    int space = 2;
    Carte * currentCardptr = deck;

    //define color
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    //Struct pour les stats du jeu ?

    //ligne de carte 1
    for(int i=0 ; i<6 ; i++) {
        defineCard(deck[i], LARGEUR_CARTE, LONGUEUR_CARTE, 2, 'D', 0, 5, space);
        space += 13;
    }

    space = 2;

    //ligne de carte 2
    for(int j=7 ; j <= 12 ; j++){
        defineCard(deck[j],LARGEUR_CARTE,LONGUEUR_CARTE,0,'G',1,14,space);
        space += 13;
    }

    refresh();

    endwin();
    return 0;
}

void defineCard(Carte c, int largeur, int longueur, int cursor, char var, bool etat, int posx, int posy)
{
    c.cursor = cursor;
    c.var = var;
    c.etat = etat;
    c.carte = subwin(stdscr,largeur,longueur,posx,posy);

    wborder(c.carte, '|', '|', '-', '-', ' ', ' ', ' ', ' ');

    /*if (c.etat) {
        wborder(c.carte, '|', '|', '-', '-', '0', '0', '0', '0');
        mvwprintw(c.carte, 3, 5, "%c", c.var);

    } else if (c.cursor == 1) {
        wattron(c.carte, COLOR_PAIR(1));
        wborder(c.carte, '|', '|', '-', '-', ' ', ' ', ' ', ' ');
        wattroff(c.carte, COLOR_PAIR(1));
    } else if (c.cursor == 2){
        wattron(c.carte, COLOR_PAIR(2));
        wborder(c.carte, '|', '|', '-', '-', ' ', ' ', ' ', ' ');
        wattroff(c.carte, COLOR_PAIR(2));
    } else {
        wborder(c.carte, '|', '|', '-', '-', ' ', ' ', ' ', ' ');
    }*/

}

//gcc main.c - main.out -lncurses -I~/programme/carte.c