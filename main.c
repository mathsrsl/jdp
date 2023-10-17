#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //pour usleep

#include "menu.h"

#include <ncurses.h>

int main(void) {

    initscr();

    int height = 30;
    int width = 100;
    int rows, cols;
    int menuChoice;

    //Erreur terminal trop petit
    getmaxyx(stdscr, rows, cols); //taille du terminal
    if(rows < height || cols < width){
        endwin();
        printf("Erreur, terminal trop petit\n");
        return -1;
    }

    //Afficher le menu du jeu
    menuChoice = menu(height, width);

    if(menuChoice == -1){ //Si touche q pressee
        endwin();
        printf("Au revoir\n");
        return 0;
    }

    /* ------------------ Affichage du jeu ------------------ */

    clear();
    cbreak(); //evite de d'attendre une nouvelle ligne pour getch()
    noecho(); //desactive l'echo automatique des caracteres entréees
    nodelay(stdscr, TRUE); //eviter que getch() bloque la boucle 
    keypad(stdscr, TRUE); // pour les touches spécials (flèches)

    WINDOW *titleBox, *chronoBox, *resultBox;

    int key;
    struct timespec start_time, current_time;
    double elapsed_time;

    //obtenir le temps au début de l'exec
    clock_gettime(CLOCK_REALTIME, &start_time);


    //déclare taille et position des boites
    titleBox = subwin(stdscr, 4, width/1.5, 0, 0);
    chronoBox = subwin(stdscr, 4, width/3+1, 0, width/1.5);

    //création des boites
    box(titleBox, ACS_VLINE, ACS_HLINE);
    box(chronoBox, ACS_VLINE, ACS_HLINE);

    //affichage du text
    mvwprintw(titleBox, 1, 1, "Jeu des paires");
    mvwprintw(titleBox, 2, 1, "Trouver les paires en un minimum de temps");
    

    //affichage du cadre
    //wborder(resultBox, '|', '|', '-', '-', '+', '+', '+', '+');


    while(key != 'q' && key != 'Q'){
        clock_gettime(CLOCK_REALTIME, &current_time); // obtenir temps actuel

        // calculer le temps ecoule (en sec + nanoseconde)
        elapsed_time = (double)(current_time.tv_sec - start_time.tv_sec) +
                       (double)(current_time.tv_nsec - start_time.tv_nsec) / 1.0e9;

        mvwprintw(chronoBox, 1, 1, "chrono : %.1fs", elapsed_time);
        mvwprintw(chronoBox, 2, 1, "KEY DETECT : %c", key);


        //refresh
        wrefresh(chronoBox);

        key = getch();

        usleep(100000); // arret de 100ms pour alléger le processeur
    }  

    nodelay(stdscr, FALSE); // permettre de bloquer le prog tant que la touche 'q' n'est pas pressee

    // affichage des meilleurs scores
    resultBox = subwin(stdscr, 7, width, 23, 0);
    box(resultBox, ACS_VLINE, ACS_HLINE);
    mvwprintw(resultBox, 1, 1, "Meilleur chrono :"); 
    wrefresh(resultBox);

    // si touche 'q' pressee : arret du jeu
    key = ' ';
    while(key != 'q' && key != 'Q')
        key = getch();


    delwin(titleBox);
    delwin(chronoBox);
    delwin(resultBox);

    endwin();
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>

// #include <ncurses.h>
// #include <stdbool.h>
// #include <unistd.h>
// //#include "carte.h"

// #define LARGEUR_CARTE 10
// #define LONGUEUR_CARTE 10
// #define NB_CARD 12

// typedef struct Carte Carte;

// struct Carte{
//     WINDOW *carte;
//     unsigned int cursor;
//     char var;
//     bool etat;
// };



// void defineCard(Carte c,int largeur,int longueur,int cursor,char var,bool etat,int posx,int posy);

// int main()
// {
//     //Definition des cartes et ajouts des cartes dans le tableau
//     Carte c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12 = {NULL};
//     Carte deck[NB_CARD] = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12};
//     int cursorPos = 0,space = 12;
//     Carte * currentCardptr = deck;
    

//     //Struct pour les stats du jeu ?

//     //initalisation de l'ecran de base
//     initscr();
    

//     /*c1.carte = subwin(stdscr,LARGEUR_CARTE,LONGUEUR_CARTE,2,1);
//     box(c1.carte,ACS_VLINE,ACS_HLINE);
//     test*/

//     //premiere carte avec le curseur de 1
//     defineCard(deck[0],LARGEUR_CARTE,LONGUEUR_CARTE,1,'C',0,1,1);

//     //ligne de carte 1
//     for(int i = 1;i<=6;i++)
//     {
//         defineCard(deck[i],LARGEUR_CARTE,LONGUEUR_CARTE,0,'D',0,1,space);
//         space += 11;
//     }

//     space = 1;

//     //ligne de carte 2
//     for(int j = 6;j <= 12;j++)
//     {
//         defineCard(deck[j],LARGEUR_CARTE,LONGUEUR_CARTE,0,'G',0,13,space);
//         space += 11;
//     }
    

//     while(1)
//     {

//         for(int k = 0;k < 12;k++)
//         {
//             if(deck[k].cursor == 1)
//             {
//                 wattron(deck[k].carte,COLOR_GREEN);
//             }
//         }

//         refresh();

//         if (getch() != 410)
//             break;

//         usleep(10000);
        
//     }
    
//     endwin();
//     return 0;
// }

// void defineCard(Carte c,int largeur,int longueur,int cursor,char var,bool etat,int posx,int posy)
// {
//     c.cursor = cursor;
//     c.var = var;
//     c.etat = etat;
//     c.carte = subwin(stdscr,largeur,longueur,posx,posy);
//     box(c.carte,ACS_VLINE,ACS_HLINE);
// }
