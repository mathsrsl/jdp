#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

#include "menu.h"

int main(void) {

    int menuChoice = menu();

    if(menuChoice == 0){
        return 0;
    }

    WINDOW *titleBox, *chronoBox, *resultBox;

    initscr();
    resize_term(30, 100);

    while(1){
        //titleBox= subwin(stdscr, LINES / 4, COLS/1.5, 0, 0);
        //chronoBox= subwin(stdscr, LINES / 4, COLS/3, 0, COLS-(COLS/3));
        //resultBox= subwin(stdscr, LINES / 4, COLS, LINES-(LINES/4), 0);

        //déclare taille et position des boites
        titleBox = subwin(stdscr, 6, 66, 0, 0);
        chronoBox = subwin(stdscr, 6, 32, 0, 67);
        resultBox = subwin(stdscr, 7, 100, 23, 0);

        //création des boites
        box(titleBox, ACS_VLINE, ACS_HLINE);
        box(chronoBox, ACS_VLINE, ACS_HLINE);
        box(resultBox, ACS_VLINE, ACS_HLINE);

        //affichage du text
        clear();
        mvwprintw(titleBox, 1, 1, "Jeu des paires\nTrouver les paires en un minimum de temps");
        mvwprintw(chronoBox, 1, 1, "chrono");
        mvwprintw(resultBox, 1, 1, "Ceci est la fenetre du bas");

        //affichage du cadre
        wborder(titleBox, '|', '|', '-', '-', '+', '+', '+', '+');
        wborder(chronoBox, '|', '|', '-', '-', '+', '+', '+', '+');
        wborder(resultBox, '|', '|', '-', '-', '+', '+', '+', '+');

        //refresh
        wrefresh(titleBox);
        wrefresh(chronoBox);
        wrefresh(resultBox);


        if(getch() == 'q' || getch() == 'Q') {
            endwin();
            return 0;
        }
    }

    endwin();

    //free(titleBox);
    //free(resultBox);

    return 0;
}
