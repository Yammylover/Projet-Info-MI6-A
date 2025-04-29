#include "af2.h"
#define SIZE 1

void attaque(Combattant* tab, int IDatk, int IDdef, int matk, int mdex){
	printf("%s attaque %s !\n");
}

void action(int aID, int tailles[3], Combattant* tab){
    //vérification
    if(tailles==NULL || tab==NULL || aID<tailles[0] || aID>tailles[2]){
    	printf("ERROR FONCTION ACTION");
    }
    //début fonction
    printf("C'est le tour de %s",tab[aID].base.nom);
    int cible;
    if(aID<tailles[0]){
    	cible=rand()%(tailles[2]-tailles[0]+1)+tailles[0]-1;
    	attaque(tab,aID,cible,100,0);
    }
}

void combat(Combattant* e1, Combattant* e2,int t1, int t2){
    //vérifications
    if(e1==NULL || e2==NULL){
    	printf("Erreur pointeurs d'équipes\n");
    	exit(1);
    }
    if(t1<=0 || e2<=0){
    	printf("Erreur tailles d'équipes\n");
    	exit(1);
    }
    //création du tableau terrain, contenant tous les combattants
    int taille=t1+t2;
    Combattant ee[taille];
    int tailles[3];
    tailles[0]=t1;
    tailles[1]=t2;
    tailles[2]=taille;
    for (int i=0; i<t1; i++){
        ee[i]=e1[i];
    }
    for (int i=0; i<t2; i++){
        ee[i+t1]=e2[i];
    }
    //répétition à chaque tours:
    int a=0;
    while(a<10){
    	//calcul des stats
    	for(int i=0; i<taille; i++){
        	ee[i].atk=ee[i].base.atk;
        	ee[i].def=ee[i].base.def;   //) ajouter: modifs de stats
        	ee[i].vit=ee[i].base.vit;
        	displayfighter(ee[i]);
    	}
    	//régulation des actions
    	int tabact[taille]; //contient les jauges d'actions de tous les combattants
    	for(int i=0; i<taille; i++){
        	ee[i].act+=ee[i].vit;
        	tabact[i]=ee[i].act;
    	}
    	int j=IDmax(tabact,taille);
    	printf("\nj=%d\n",j);
    	if(ee[j].act>=100){   //définition de la c° d'action
        	ee[j].act=0;
        	action(j,tailles,ee);	//erreur de segmentation dans action
    	}
    	a++;
    }
}
