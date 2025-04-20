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
    for(int i=0; i<SIZE; i++) {
        if(equipe1[i].vit>=100) {
            equipe1[i].vit=equipe1[i].vit-100;
        }
        if(equipe2[i].vit>=100) {
            equipe2[i].vit=equipe1[i].vit-100;
        }
    }
    do {
        Combattant1.vit= Combattan1.vit+ ID1.vit/10;
        Combattant2.vit= Combattan2.vit+ ID2.vit/10;
        Combattant3.vit= Combattan3.vit+ ID3.vit/10;
        Combattant4.vit= Combattan4.vit+ ID4.vit/10;
        Combattant5.vit= Combattan5.vit+ ID5.vit/10;
        Combattant6.vit= Combattan6.vit+ ID6.vit/10;

    }while(equipe1[0].vit<100 ||equipe1[1].vit<100 || equipe1[2].vit<100 || equipe2[0].vit<100 ||equipe2[1].vit<100 || equipe2[2].vit<100);
    // on tri le tableau qui contient les combattants ranger selon leur vitesse
    Combattant tabvit[6];
    trivit(equipe1[SIZE], equipe2[SIZE], tabvit[6]);
    return 1;
}
//permet d'attaquer quand la jauge de vitesse est pleine
void attack(Combattant equipe1[SIZE], Combattant equipe2[SIZE], Combattant Combattant1, Combattant Combattant2, Combattant Combattant3, Combattant Combattant4, Combattant Combattant5, Combattant Combattant6) {
    if(vitesse(equipe1[SIZE], equipe2[SIZE], combattant, Combattant, Combattant3, Combattant, Combattant, Combattant )==1  ) {
        for(int i=0; i<SIZE; i++) {
            if(equipe1[i].vit>=100){
                choixcapacite(equipe1[SIZE], equipe2[SIZE], Combattant1, Combattant2, Combattant3, Combattant4, Combattant5, Combattant6);
            }

        }
    }
}

//permet de choisir une capacité
void choixcapacite(Combattant equipe1[SIZE], Combattant equipe2[SIZE], Combattant Combattant1, Combattant Combattant2, Combattant Combattant3, Combattant Combattant4, Combattant Combattant5, Combattant Combattant6) {
    int i;
    int choix;
    printf("veuillez choisir une capacité : \n");
}

int choixcible(Combattant equipe1[SIZE], Combattant equipe2[SIZE], Combattant Combattant1, Combattant Combattant2, Combattant Combattant3, Combattant Combattant4, Combattant Combattant5, Combattant Combattant6) {
    int choix=-1;
    printf("veuillez choisir une cible : \n");
    printf("veuillez entrer 0 pour choisir %s, 1 pour %s, 2 pour %s", equipe1[0].IDpeso.nom, equipe1[1].IDperso.nom, equipe1[2].IDperso.nom);
    scanf("%d", %choix);
    return choix;
}
//permet de ranger le tableau de vitesse dans l'ordre décroissant grace à un tri par selection
void trivit(Combattant equipe1[SIZE], Combattant equipe2[SIZE], tab[6] ) {
    for(int i=0; i<SIZE; i++) {
        tab[i]=equipe1[i];
    }
    for (int i=0; i<SIZE; i++) {
        tab[i+3]=equipe2[i];
    }
    for(int i=0; i<SIZE*2; i++) {
        for(int j=i+1; j<SIZE*2; j++) {
            if(tab[i].vit<tab[j].vit) {
                Combattant temp=tab[i];
                tab[i]=tb[j];
                tab[j]=temp;
            }
        }
    }
}
