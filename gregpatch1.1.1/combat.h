#include "af2.h"
#define SIZE 1

void deathmodif(Combattant* tab, int ID, int* t1, int* t2, int* tmax){
    //verification
    if(tab==NULL || t1==NULL || t2==NULL || tmax==NULL || ID<0 || ID>=*tmax){
        printf("erreur deathmodif\n");
        exit(3);
    }
    //process
    //si dans l'équipe 1
    if(ID<*t1){
        *t1=*t1-1;
        printf("t1=%d ",*t1);
    }
    //si dans l'équipe 2
    else if(ID>=*t1){
        *t2=*t2-1;
        printf("t2=%d ",*t2);
    }
    for(int i=ID+1; i<*tmax; i++){
        tab[i].ID--;
    }
    for(int i=ID; i<*tmax-1; i++){
        tab[i]=tab[i+1];
    }
    *tmax=*t1+*t2;
    printf("tmax=%d\n",*tmax);
}
    
    
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
	int rd1=0,rd2=0;
	int atk=tab[IDatk].atk*matk/100;
	int def=tab[IDdef].def;
	int crit=tab[IDatk].dex*mdex/100;
	rd1=rand()%101;
	rd2=rand()%101;
	printf("rd1=%d rd2=%d\n",rd1,rd2);
	if (rd1<=tab[IDdef].agl){
		printf("%s évite l'attaque !\n",tab[IDdef].base.nom);
	} else if(rd2<=crit){
		printf("C'est un coup critique!\n");
		dg=(atk*(100-def)/100)*150/100;		//coup critique
	} else {
		dg=atk*(100-def)/100;
	}
	printf("%s subit %d dégâts!\n",tab[IDdef].base.nom,dg);
	tab[IDdef].pv-=dg;
}

void action(Combattant* tab, int aID, int* tmax, int* t1, int* t2){
    //vérification
    if(*tmax==0 || *t1==0 || *t2==0 || tab==NULL || aID<0 || aID>=*tmax || tmax==NULL || t1==NULL || t2==NULL){
    	printf("ERREUR FONCTION ACTION");
    	exit(1);
    }
    //début fonction
    printf("C'est le tour de %s!\n",tab[aID].base.nom);
    int cible,min,max;
    if(aID<*t1){
        min=*t1;
        max=*tmax-1;
    	cible=rand()%(max-min+1)+min;
    	attaque(tab,aID,cible,100,100);
    } else if(aID>=*t1){
        min=0;
        max=*t1-1;
        cible=rand()%(max+1)+min;
        attaque(tab,aID,cible,100,0);
    }
    if(deathcheck(tab,cible)){
		printf("%s est mort!\n", tab[cible].base.nom);
		deathmodif(tab,cible,t1,t2,tmax);
	}
}

void combat(Combattant* e1, Combattant* e2,int t1, int t2){
    srand(time(NULL));
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
    int tmax=t1+t2;
    Combattant ee[tmax];
    for (int i=0; i<t1; i++){
        ee[i]=e1[i];
    }
    for (int i=0; i<t2; i++){
        ee[i+t1]=e2[i];
    }
    //répétition à chaque tours:
    while(t1!=0 && t2!=0){
    	//calcul des stats
    	for(int i=0; i<tmax; i++){
        	ee[i].atk=ee[i].base.atk;
        	ee[i].def=ee[i].base.def;   // ajouter: modifs de stats
        	ee[i].vit=ee[i].base.vit;
        	ee[i].dex=ee[i].base.dex;
        	ee[i].agl=ee[i].base.agl;
        	displayfighter(ee[i]);
    	}
    	//régulation des actions
    	int tabact[tmax]; //contient les jauges d'actions de tous les combattants
    	for(int i=0; i<tmax; i++){
        	ee[i].act+=ee[i].vit;
        	tabact[i]=ee[i].act;
    	}
    	int j=IDmax(tabact,tmax);
    	if(ee[j].act>=100){   //définition de la c° d'action
        	ee[j].act=0;
        	action(ee,j,&tmax,&t1,&t2);
    	}
        sleep(1);
    }
}
