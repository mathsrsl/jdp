#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>

#include "carte.h"

#define LARGEUR_CARTE 8
#define LONGUEUR_CARTE 11
#define NB_CARD 12

typedef struct Carte Carte;

struct Carte{
    WINDOW *carte;
    unsigned int cursor;
    char var;
    bool etat;
};


void defineCard(Carte c,int largeur,int longueur,int cursor,char var,bool etat,int posx,int posy);

int DisplayCard()
{
    //Definition des cartes et ajouts des cartes dans le tableau
    Carte c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12 = {NULL};
    Carte deck[NB_CARD] = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12};
    int cursorPos = 0,space = 2;
    Carte * currentCardptr = deck;


    //Struct pour les stats du jeu ?

    //initalisation de l'ecran de base
    //initscr();

    //clear();
    //cbreak(); //evite de d'attendre une nouvelle ligne pour getch()
    //noecho(); //desactive l'echo automatique des caracteres entréees
    //nodelay(stdscr, TRUE); //eviter que getch() bloque la boucle
    //keypad(stdscr, TRUE); // pour les touches spécials (flèches)


    //start_color();
    //init_pair(1, COLOR_BLUE, COLOR_BLACK);
    //init_pair(2, COLOR_GREEN, COLOR_BLACK);

    //premiere carte avec le curseur de 1
    //defineCard(deck[0],LARGEUR_CARTE,LONGUEUR_CARTE,1,'C',0,1,1);

    //ligne de carte 1
    for(int i=0 ; i<6 ; i++) {
        defineCard(deck[i], LARGEUR_CARTE, LONGUEUR_CARTE, 0, 'D', 0, 5, space);
        space += 13;
    }

    space = 2;

    //ligne de carte 2
    for(int j=7 ; j <= 12 ; j++){
        defineCard(deck[j],LARGEUR_CARTE,LONGUEUR_CARTE,0,'G',0,14,space);
        space += 13;
    }

    int key;

    /*while(key != 'q' && key != 'Q')
    {
        //if(key == '1'){
        //    wattron(deck[0].carte, COLOR_PAIR(2));
        //}


        key = getch();



        usleep(10000);
    }*/

    refresh();

    endwin();
    return 0;
}

void defineCard(Carte c,int largeur,int longueur,int cursor,char var,bool etat,int posx,int posy)
{
    c.cursor = cursor;
    c.var = var;
    c.etat = etat;
    c.carte = subwin(stdscr,largeur,longueur,posx,posy);
    wborder(c.carte, '|', '|', '-', '-', '0', '0', '0', '0');
}



//gcc main.c - main.out -lncurses -I~/programme/carte.c