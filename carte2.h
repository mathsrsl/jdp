#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Carte Carte;

struct Carte
{
    WINDOW *carte;
    unsigned int etat;    //0 si rien, 1 si focus, 2 si trouver paires
    char  var;
};

//deux fonction differente, une pour l'initialisation de la carte attributs
//l'autre pour le display (check les attributs pour des displays differents

//Donne une valeur a tout les attributs d'une carte
void AttributsInit(Carte c,unsigned int etat);
//Affiche les cartes avec leurs bordure
void DisplayCard(Carte c,int longeur,int largeur,unsigned int etat,int numCard);
//donne la position x de la carte n (n etant entre 0 et 11)
int PosCardX(int numCard);
//pareil mais avec y
int PosCardY(int numCard);
//renvoie une lettre aleatoire
void LettreAlea(Carte * deck,char * lettre,int taille);

#endif // CARTE_H_INCLUDED
