#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

int main(void) {
    WINDOW *titleBox, *chronoBox, *resultBox;

    initscr();
    resize_term(100, 40);

    while(1){
        titleBox= subwin(stdscr, LINES / 4, COLS/1.5, 0, 0);
        chronoBox= subwin(stdscr, LINES / 4, COLS/3, 0, COLS-(COLS/3));
        resultBox= subwin(stdscr, LINES / 4, COLS, LINES-(LINES/4), 0);

        box(titleBox, ACS_VLINE, ACS_HLINE);
        box(chronoBox, ACS_VLINE, ACS_HLINE);
        box(resultBox, ACS_VLINE, ACS_HLINE);


        clear();
        mvwprintw(titleBox, 1, 1, "Jeu des paires\nTrouver les paires en un minimum de temps");
        mvwprintw(chronoBox, 1, 1, "chrono");
        mvwprintw(resultBox, 1, 1, "Ceci est la fenetre du bas");

        wborder(titleBox, '|', '|', '-', '-', '+', '+', '+', '+');
        wborder(chronoBox, '|', '|', '-', '-', '+', '+', '+', '+');
        wborder(resultBox, '|', '|', '-', '-', '+', '+', '+', '+');


        wrefresh(titleBox);
        wrefresh(chronoBox);
        wrefresh(resultBox);


        if(getch() != 410)
            break;
    }

    endwin();

    //free(titleBox);
    //free(resultBox);

    return 0;
}