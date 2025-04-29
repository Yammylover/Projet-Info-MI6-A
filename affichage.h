#include "structures.h"

void afficheplateau(Combattant* tab, int t1, int t2){
	printf("Equipe1\n");
	int len1=2+(12+2)*t1;
	int p=0,str=0;
	for (int i=0; i<8; i++){
		switch (i) {
			case 0:		//écrit Equipe1
				printf("Equipe1\n");
			break;
			case 1:
			case 8:		//écrit  __________ 
				printf(" ");
				for(int j=0; j<len1-2;j++){
					printf("_");
				}
				printf(" \n");
			break;
			case 2:
			case 4:
			case 7:		//écrit |       |
				printf("|");
				for(int j=0; j<len1-2;j++){
					printf(" ");
				}
				printf("|\n");
			break;
			case 3:		//écrit |  name1        name2       name3     |
				printf("| ");
				for (int j=0; j<t1;j++){
					str=strlen(tab[j].base.nom);
					printf(" ");
					if(str>10){
						for(int h=0; i<10;i++){
							printf("%c",tab[j].base.nom[h]);
						}
					} else {
						printf("%s",tab[j].base.nom);
					}
					printf(" ");
					if(j!=t1-1){
						printf("  ");
					}
				}
				printf(" |\n");
			break;
			case 5:		//barre de vie
				printf("| ");
				for (int j=0; j<t1;j++){
					p=(tab[i].pv*10)/tab[i].base.pv;
					printf("[");
					for (int h=0; h<10; h++){
						printf("#");
					}
					printf("]");
					if(j!=t1-1){
						printf("  ");
					}
				}
				printf(" |\n");
			break;
			case 6:	//barre d'action
				printf("| ");
				for (int j=0; j<t1;j++){
					p=(tab[i].act)/100;
					printf("[");
					for (int h=0; h<10; h++){
						printf("#");
					}
					printf("]");
					if(j!=t1-1){
						printf("  ");
					}
				}
				printf(" |\n");
			break;
		}
	}
}
