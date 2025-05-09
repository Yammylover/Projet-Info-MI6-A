#include "structure.h"
#include "windows.h"
#define SIZE 1

int main(){
    SetConsoleOutputCP(CP_UTF8); //ligne de code permettant l'utilisation de caractere unicode

// équipe 1
    Combattant equipe1[3];
// équipe 2
    Combattant equipe2[3];

    //code pour la selection des personnages de l'equipe 1
    printf("Selection des champions de l'equipe 1\n");
    for(int i=0;i<3;i++) {
        equipe1[i]=stats(i);
        equipe1[i].ID=i;
    }

    //code pour la selection des personnages de l'equipe 2
    printf("Selection des champions de l'equipe 2\n");
    for(int i=0;i<3;i++) {

        equipe2[i]=stats(i);
        equipe2[i].ID=i+3;
    }

affichage(equipe1,equipe2);

    return 0;
}

