#ifndef CIBLAGE_H

#define CIBLAGE_H
#include "combat.h"

int rando(int min, int max){
	if (min>max){
		printf("Erreur ciblage3\n");
		exit(3);
	}
	return (rand()%(max-min+1)+min);
}
		
int cible(Combattant* tab, int t1, int tmax, int ID, int ecible, int tcible){	//ecible est l'équipe visée typecible est le type de ciblage
	//vérification
	if(tab==NULL || t1==0 || tmax==0 || ID<0 || ID>=tmax || ecible<=0 || ecible >2){
		printf("erreur ciblage1\n");
		exit(1);
	}
	//locals
	int a=0,b=0;
	srand(time(NULL));
	switch(ecible){
		case 1:		//combattant vise l'équipe 1
			switch(tcible){
				case 1:		//sélection aléatoire
					do{
						b=rando(0,t1-1);
					}while(tab[b].pv<=0 || b<0 || b>=tmax);
				break;
				case 2:		//a finir
				break;
			}
		break;
		case 2:		//combattant vise l'équipe 2
		       switch(tcible){
		           case 1:
                     do{
		                b=rando(t1,tmax-1);
					}while(tab[b].pv<=0 || b<0 || b>=tmax);
					break;
					case 2:
					break;
		        }
		break;
		case 0:
			printf("Erreur ciblage2\n");
			exit(2);
		break;
		return b;
	}
}
#endif
