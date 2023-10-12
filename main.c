#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //pour usleep

#include <ncurses.h>

#include "menu.h"

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
    resultBox = subwin(stdscr, 7, width, 23, 0);

    //création des boites
    box(titleBox, ACS_VLINE, ACS_HLINE);
    box(chronoBox, ACS_VLINE, ACS_HLINE);
    box(resultBox, ACS_VLINE, ACS_HLINE);

    //affichage du text
    mvwprintw(titleBox, 1, 1, "Jeu des paires\nTrouver les paires en un minimum de temps");
    mvwprintw(resultBox, 1, 1, "Meilleur chrono : \n");

    //affichage du cadre
    wborder(titleBox, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(resultBox, '|', '|', '-', '-', '+', '+', '+', '+');


    while(1){
        key = getch();
        if(key == 'q' || key == 'Q') {
            endwin();
            return 0;
        }

        
        clock_gettime(CLOCK_REALTIME, &current_time); // obtenir temps actuel

        // calculer le temps ecoule (en sec + nanoseconde)
        elapsed_time = (double)(current_time.tv_sec - start_time.tv_sec) +
                       (double)(current_time.tv_nsec - start_time.tv_nsec) / 1.0e9;

        mvwprintw(chronoBox, 1, 1, "chrono : %.1fs\n Key : %c", elapsed_time, key);
        wborder(chronoBox, '|', '|', '-', '-', '+', '+', '+', '+');

        //refresh
        wrefresh(chronoBox);
        //wrefresh(resultBox);


        usleep(100000);
    }

    endwin();

    return 0;
}