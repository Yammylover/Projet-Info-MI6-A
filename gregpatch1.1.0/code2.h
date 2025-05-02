#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int max(int* tab,int taille){
    int max=0;
    for (int i=0; i<taille; i++){
        if (tab[i]>max){
            max=tab[i];
        }
    }
    return max;
}

int* findID(int* tab,int taille, int statID, int value,int* pnbsel){		//ne pas oublier de FREE!!!!!
    	int j=0;
    	int* tabreturn=calloc(taille, sizeof(int));
   	switch(statID){
    		case 7:		//act
    			for(int i=0; i<taille; i++){
    				if(tab[i]==value){
    					tabreturn[j]=i;
    					j++;
    				}
    			}
    		break;
    		*pnbsel=j;
    	}
    	return 	tabreturn;
}

int selection(int* tab,int size, char* phrase){
	//vérification
	if(tab==NULL){
		printf("ERREUR FONCTION SELECTION");
	}
	//process
	int a,b;
	do{
		printf("%s",phrase);
		scanf("%d",&a);
		for(int  i=0; i<size; i++){
			if(a==tab[i]){
				b=1;
			}
		}
	} while(b!=1);
}
