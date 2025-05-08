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
		
int cible(Combattant* tab, int t1, int tmax, int ID, int ecible, int tcible){	//ecible est l'équipe visée typecible est le type de ciblage (1 pour aléatoire, 2 pour manuel)
	//vérification
	if(tab==NULL || t1==0 || tmax==0 || ID<0 || ID>=tmax || ecible<=0 || ecible >2){
		printf("erreur ciblage1\n");
		exit(1);
	}
	//locals
	int a=0,b=0,c=0;
	int array[tmax-1];
	srand(time(NULL));
	switch(ecible){
		case 1:		//combattant vise l'équipe 1
			switch(tcible){
				case 1:		//sélection aléatoire
					do{
						b=rando(0,t1-1);
					}while(tab[b].pv<=0 || b<0 || b>=tmax);
				break;
				case 2:		//sélection manuelle
				    for(int i=0;i<t1;i++){
				        if(tab[i].pv>0){
				            a++;
				            array[c]=i;
				            c++;
				        }
				    }
				    b=selection(array,a,"Rentrez un ID de cible valide:\n");
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
					case 2: //sélection manuelle
					for(int i=t1;i<tmax;i++){
				        if(tab[i].pv>0){
				            a++;
				            array[c]=i;
				            c++;
				        }
				    }
				    b=selection(array,a,"Rentrez un ID de cible valide:\n");
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
