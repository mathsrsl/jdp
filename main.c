#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <ncurses.h>

#include "menu.h"

int main(void) {

    initscr();

    int height = 30;
    int width = 100;
    int rows, cols;

    getmaxyx(stdscr, rows, cols); // Obtenez la taille du terminal dans rows et cols
    if(rows < height || cols < width){
        endwin();
        printf("Terminal trop petit, veuillez l'agrandir\n");
        return 0;
    }

    int menuChoice = menu(height, width);

    if(menuChoice == 0){
        endwin();
        printf("Au revoir\n");
        return 0;
    }

    clear();
    cbreak();
    noecho();
    WINDOW *titleBox, *chronoBox, *resultBox;

    //time_t start = time (NULL);
    clock_t temps;
    srand(time(NULL));

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
        char key = getch();

        temps=clock();
        mvwprintw(chronoBox, 1, 1, "chrono : %f\nblbl : %c", (double)temps/CLOCKS_PER_SEC, key);
        wborder(chronoBox, '|', '|', '-', '-', '+', '+', '+', '+');

        //refresh
        wrefresh(chronoBox);
        //wrefresh(titleBox);
        //wrefresh(resultBox);


        if(key == 'q' || key == 'Q') {
            endwin();
            return 0;
        }
    }

    endwin();

    return 0;
}