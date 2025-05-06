#ifndef CIBLAGE_H

#define CIBLAGE_H
#include "combat.h"

int rando(int min, int max){
	if (min>max){
		printf("Erreur ciblage3\n");
		exit(3);
	}
	return (rand()%(max+1-min)+min);
}
		
int cible(Combattant* tab,int t1, int tmax, int ID, int ecible, int typecible);//{	//ecible est l'équipe visée typecible est le type de ciblage
	//vérification
	if(tab==NULL || t1=0 || tmax==0 || ID<0 || ID>=tmax || int ecible<=0 || int ecible >2){
		printf("erreur ciblage1\n");
		exit(1);
	}
	//locals
	int a=0,b=0;
	srand(time(NULL));
	if(ID<t1){
		a=1;
	} else if(ID>=t1){
		a=2;
	}
	switch(a){
		case 1:		//combattant appartient à l'équipe 1
			switch(typecible){
				case 1:		//sélection aléatoire
					do{
						b=rando(t1,tmax-1);
					}while(tab[b].pv<=0);
				break;
				case 2:		//a finir
				break;
		break;
		case 2;		//combattant appartient à l'équipe 2
		break;
		case 0;
			printf("Erreur ciblage2\n");
			exit(2);
		break;
	}
#endif
