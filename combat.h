#include "structures.h"
#define SIZE 1

void action(Combattant a){
    
}

void attaque(Combattant atk, Combattant def){
    
}

void combat(Combattant* e1, Combattant* e2,int t1, int t2){
    //création du tableau terrain, contenant tous les combattants
    int taille=t1+t2;
    Combattant ee[taille];
    for (int i=0; i<t1; i++){
        ee[i]=e1[i];
    }
    for (int i=0; i<t2; i++){
        ee[i+t1]=e2[i];
    }
    //répétition à chaque tours:
    //calcul des stats
    for(int i=0; i<taille; i++){
        ee[i].atk=ee[i].base.atk;
        ee[i].def=ee[i].base.def;   //) ajouter: modifs de stats
        ee[i].vit=ee[i].base.vit;
    }
    
    //régulation des actions
    int tabact[taille]; //contient les jauges d'actions de tous les combattants
    for(int i=0; i<taille; i++){
        ee[i].act+=ee[i].vit;
        tabact[i]=ee[i].act;
    }
    int j=IDmax(tabact,taille);
    if(ee[j].act>10){   //définition de la c° d'action
        action(ee[j]);
        ee[j].act=0;
    }

}