#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "structures.h"
#define SIZE 3

int fincombat(Combattant Combattant1, Combattant Combattant2, Combattant Combattant3, Combattant Combattant4, Combattant Combattant5, Combattant Combattant6) {
    //ID1, ID2, ID3 = ID des personnages de l'équipe 1
    //ID4, ID5, ID6 = ID des personnages de l'équipe 2
    //retourne 1 si l'équipe 1 a gagné, 2 si l'équipe 2 a gagné, et 0 si le combat est encore en cours
    if(Combattant1.pv==0 && Combattant2.pv==0 && Combattant3.pv==0){
        return 2;
    }
    else if(Combattant4.pv==0 && Combattant5.pv==0 && Combattant6.pv==0){
        return 1;
    }
    else{
        return 0;
    }
}
//qui attaque en premier ?
int vitesse(Combattant equipe1[SIZE], Combattant equipe2[SIZE], Combattant Combattant1, Combattant Combattant2, Combattant Combattant3, Combattant Combattant4, Combattant Combattant5, Combattant Combattant6) {
    do {




    }while(equipe1[0].vit<100 ||equipe1[1].vit<100 || equipe1[2].vit<100);
}
