#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

#include "menu.h"

int menu()
{
    WINDOW *mainContainer;

    initscr();
    int height = 30;
    int width = 100;
    resize_term(height, width);
    char saisie[20];

    do{
        clear();
        wclear(mainContainer);

        //déclare taille et position des boites
        mainContainer = subwin(stdscr, height, width, 0, 0);


        //création des boites
        box(mainContainer, 0, 0);


        //affichage d'un cadre blanc autour de mainContainer
        chtype ulcorner = ACS_ULCORNER;
        chtype urcorner = ACS_URCORNER;
        chtype llcorner = ACS_LLCORNER;
        chtype lrcorner = ACS_LRCORNER;
        chtype hline = ACS_HLINE;
        chtype vline = ACS_VLINE;

        mvwaddch(mainContainer, 0, 0, ulcorner);
        mvwaddch(mainContainer, 0, width - 1, urcorner);
        mvwaddch(mainContainer, height - 1, 0, llcorner);
        mvwaddch(mainContainer, height - 1, width - 1, lrcorner);
        mvwhline(mainContainer, 0, 1, hline, width - 2);
        mvwhline(mainContainer, height - 1, 1, hline, width - 2);
        mvwvline(mainContainer, 1, 0, vline, height - 2);
        mvwvline(mainContainer, 1, width - 1, vline, height - 2);


        //affichage du text
        mvwprintw(mainContainer, LINES/3, 5, "MENU");
        mvwprintw(mainContainer, LINES/3+3, 5, "1. Un joueur");
        mvwprintw(mainContainer, LINES/3+5, 5, "2. Autoplayer");
        mvwprintw(mainContainer, LINES/3+8, 5, "Entrez votre choix :");

        mvwgetstr(mainContainer, LINES/3+10, 5, saisie);

        switch (saisie[0]) {
            case '1':
                return 1;
            case '2':
                return 2;
            case 'q':
            case 'Q':
                endwin();
                return 0;

            default:
                mvwprintw(mainContainer, LINES/3+12, 5, "Erreur de saisie");
        }

        //refresh
        refresh();
        wrefresh(mainContainer);


    } while (saisie[0] != '1' && saisie[0] != '2');

    endwin();
}