#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enregisterScore(char place, char nom[6], char score[10]);
void switchTableau(char tab1[6], char tab2[6]);

void *resultats(float temps){
    FILE *fichier = NULL;
    char n[100];

    fichier = fopen("jeuhighscore.txt","r");

    if (fichier == NULL){
        fichier = fopen("jeuhighscore.txt","w+");
        fclose(fichier);
    } else {
        char c = fgetc(fichier);
        char nom1[6];
        char nom2[6];
        char nom3[6];
        char score1[10];
        char score2[10];
        char score3[10];
        int espace = 0;
        int i = 1;
        int ligne = 1;

        while(c != EOF){
            switch (c) {
                case ' ' :
                    espace+=1;
                    break;
                case '\n' :
                    i+=1;
                    espace = 0;
                    ligne+=1;
                    break;
                default :
                    break;
            }
            if (espace == 1) {
                if (c != ' '){
                    if (ligne == 1){
                        strncat(nom1, &c, 1);
                    }else if (ligne == 2){
                        strncat(nom2, &c, 1);
                    }else if (ligne == 3){
                        strncat(nom3, &c, 1);
                    }
                }
            }
            if (espace == 2) {
                if (c != ' '){
                    if (ligne == 1){
                        strncat(score1, &c, 1);
                    }else if (ligne == 2){
                        strncat(score2, &c, 1);
                    }else if (ligne == 3){
                        strncat(score3, &c, 1);
                    }
                }
            }
            c = fgetc(fichier);
        }
        
        if (atoi(score3)>temps){
            char nomJoueur[6];
            printf("Entrer votre nom en 4 lettres :\n");
            scanf("%s", nomJoueur);
            char tempsJoueur[6];
            snprintf(tempsJoueur, sizeof(tempsJoueur), "%.1f", temps);
            /*if ((atoi(score1))<temps){
                score3=switchTableau(score3,score2);
                nom3=switchTableau(nom3,nom2);
                score2=switchTableau(score2,score1);
                nom2=switchTableau(nom2,nom1);
                score1=temps;
                nom1=switchTableau(nom1;nomJoueur);
            }else if((atoi(score1))>temps && (atoi(score2))<temps){
                score3=switchTableau(score3,score2);
                nom3=switchTableau(nom3,nom2);
                score2=temps;
                nom2=switchTableau(nom2;nomJoueur);
            }else {
                score3=temps;
                nom3=switchTableau(nom3,nomJoueur);
            }*/
            if ((atoi(score1))>temps){
                for (i=0;i<5;i++){
                    score3[i]=score2[i];
                }
                for (i=0;i<5;i++){
                    nom3[i]=nom2[i];
                }
                for (i=0;i<5;i++){
                    score2[i]=score1[i];
                }
                for (i=0;i<5;i++){
                    nom2[i]=nom1[i];
                }
                for (i=0;i<5;i++){
                    score1[i]=tempsJoueur[i];
                }
                for (i=0;i<5;i++){
                    nom1[i]=nomJoueur[i];
                }
            }else if((atoi(score1))<temps && (atoi(score2))>temps){
                for (i=0;i<5;i++){
                    score3[i]=score2[i];
                }
                for (i=0;i<5;i++){
                    nom3[i]=nom2[i];
                }
                for (i=0;i<5;i++){
                    score2[i]=tempsJoueur[i];
                }
                for (i=0;i<5;i++){
                    nom2[i]=nomJoueur[i];
                }
            }else {
                for (i=0;i<5;i++){
                    score3[i]=tempsJoueur[i];
                }
                for (i=0;i<5;i++){
                    nom3[i]=nomJoueur[i];
                }
            }
        }
        
        FILE *fichier2 = NULL;
        fichier2 = fopen("jeuhighscoreNEW.txt", "w+");
        fputs("1", fichier2);
        fputs(" ", fichier2);
        fputs(nom1, fichier2);
        fputs(" ", fichier2);
        fputs(score1, fichier2);
        fputs("\n", fichier2);
        fputs("2", fichier2);
        fputs(" ", fichier2);
        fputs(nom2, fichier2);
        fputs(" ", fichier2);
        fputs(score2, fichier2);
        fputs("\n", fichier2);
        fputs("3", fichier2);
        fputs(" ", fichier2);
        fputs(nom3, fichier2);
        fputs(" ", fichier2);
        fputs(score3, fichier2);
        
        fclose(fichier2);
        
        enregisterScore('1', nom1, score1);

        fclose(fichier);
    }
}

void switchTableau(char tab1[6], char tab2[6]){
    int i;
    for (i=0;i<5;i++){
        tab1[i]=tab2[i];
    }
}

void enregisterScore(char place, char nom[6], char score[10]){
    FILE *fichier2 = NULL;
    fichier2 = fopen("jeuhighscoreNEW.txt", "a+");
    fputs(&place, fichier2);
    fputs(" ", fichier2);
    fputs(nom, fichier2);
    fputs(" ", fichier2);
    fputs(score, fichier2);
    fputs("\n", fichier2);
    fclose(fichier2);
}




int main()
{
    
    resultats(75);

    return 0;
}
