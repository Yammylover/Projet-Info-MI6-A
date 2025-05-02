#include "af2.h"
#define SIZE 1

int deathcheck(Combattant* tab, int ID){
    if(tab[ID].pv<=0){
        tab[ID].pv=0;
        return 1;
    }
    return 0;
}

void attaque(Combattant* tab, int IDatk, int IDdef, int matk, int mdex){
	//vérification
	if(tab==NULL || IDatk<0 || IDdef<0 || matk<0 || mdex <0){
		printf("erreur opérandes f° attaque\n");
		exit(1);
	}
	printf("%s attaque %s !\n",tab[IDatk].base.nom,tab[IDdef].base.nom);
	int dg=0;
	int rd=0;
	int atk=tab[IDatk].atk;
	int def=tab[IDdef].def;
	srand(time(NULL));
	rd=rand()%101;
	if (rd<=tab[IDdef].agl){
		printf("%s évite l'attaque !\n",tab[IDdef].base.nom);
	} else if(rd<=tab[IDatk].dex){
		printf("C'est un coup critique!");
		dg=(atk*(100-def)/100)*150/100;		//coup critique
	} else {
		dg=atk*(100-def)/100;
	}
	printf("%s subit %d dégâts!\n",tab[IDdef].base.nom,dg);
	tab[IDdef].pv-=dg;
	if(deathcheck(tab,IDdef)){
		printf("%s est mort!\n", tab[IDdef].base.nom);
	}
}

void action(int aID, int tmax, int t, Combattant* tab){
    //vérification
    if(tmax==0 || t==0 || tab==NULL || aID<0 || aID>=tmax){
    	printf("ERREUR FONCTION ACTION");
    	exit(1);
    }
    //début fonction
    printf("C'est le tour de %s!\n",tab[aID].base.nom);
    int cible,min,max;
    if(aID<t){
        min=t;
        max=tmax-1;
    	cible=rand()%(max-min+1)+min;
    	attaque(tab,aID,cible,100,0);
    } else if(aID>=t){
        min=0;
        max=t-1;
        cible=rand()%(max+1)+min;
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
    for (int i=0; i<t1; i++){
        ee[i]=e1[i];
    }
    for (int i=0; i<t2; i++){
        ee[i+t1]=e2[i];
    }
    //répétition à chaque tours:
    int a=0,b=0;
    while(a<t1 && b<t2){
    	//calcul des stats
    	for(int i=0; i<taille; i++){
        	ee[i].atk=ee[i].base.atk;   //erreur dans displayfighter ou calcul de stats-->voir attribution ee
        	ee[i].def=ee[i].base.def;   // ajouter: modifs de stats
        	ee[i].vit=ee[i].base.vit;
        	ee[i].dex=ee[i].base.dex;
        	ee[i].agl=ee[i].base.agl;
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
        	action(j,taille,t1,ee);
    	} 
    	//vérification intégrité personnages
        a=0;
        b=0;
        for(int i=0; i<t1; i++){
    		a+=deathcheck(ee,i);
    	}
    	for(int i=t1; i<taille; i++){
    		b+=deathcheck(ee,i);
    	}
    }
}
