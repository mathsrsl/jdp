#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

#include "menu.h"

void menu()
{
    WINDOW *mainContainer;

    initscr();
    resize_term(30, 100);

    while(1){
        //déclare taille et position des boites
        mainContainer = subwin(stdscr, LINES, COLS, 0, 0);

        //création des boites
        box(mainContainer, 0, 0);

        //affichage du text
        clear();
        mvwprintw(mainContainer, 1, 1, "wqt");

        //affichage du cadre
        wborder(mainContainer, '|', '|', '-', '-', '+', '+', '+', '+');

        //refresh
        refresh();
        wrefresh(mainContainer);


        if(getch() != 410)
            break;
    }

    endwin();
}