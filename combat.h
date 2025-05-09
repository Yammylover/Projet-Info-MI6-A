
#include "structure.h"
#include "ciblage.h"

void updeffect(Combattant* tab, int ID){
    //check params
    if(tab==NULL || ID<0){
        printf("Erreur updeffect...What have you done?\n");
        exit(6);
    }
    //nettoyage du tableau
    //locals
    Effet* temp;
    int size=0,c=0;
    //taille du nv tableau et creation temp
    for(int i=0; i<tab[ID].ne;i++){
        if(tab[ID].effets[i].duree==0){
            size++;
        }
    }
    temp=malloc(sizeof(Effet)*size);
    if(temp==NULL){
        printf("Erreur malloc effect\n");
        exit(90);
    }
    //copie ancien tab dans temp
    for(int i=0; i<tab[ID].ne;i++){
        if(tab[ID].effets[i].duree!=0){
            temp[c]=tab[ID].effets[i];
            c++;
        }
    }
    //copie et nettoyage des tableaux
    free(tab[ID].effets);
    tab[ID].effets=temp;
    tab[ID].ne=c;
    //application des effets
    tab[ID].atk=tab[ID].base.atk;   //réinitialisation des stats
    tab[ID].def=tab[ID].base.def;
    tab[ID].vit=tab[ID].base.vit;
    tab[ID].dex=tab[ID].base.dex;
    tab[ID].agl=tab[ID].base.agl;
    for(int i=0;i<tab[ID].ne;i++){   //modification des stats
        switch(tab[ID].effets[i].type){
            case 1 :
            case -1 :
                tab[ID].pv+=tab[ID].effets[i].puissance;
            break;
            case 2 :
            case -2 :
                tab[ID].atk+=tab[ID].effets[i].puissance;
            break;
            case 3 :
            case -3 :
                tab[ID].def+=tab[ID].effets[i].puissance;
            break;
            case 4 :
            case -4 :
                tab[ID].vit+=tab[ID].effets[i].puissance;
            break;
            case 5 :
            case -5 :
                tab[ID].agl+=tab[ID].effets[i].puissance;
            break;
            case 6 :
            case -6 :
                tab[ID].dex+=tab[ID].effets[i].puissance;
            break;
        }
        //décompte
        tab[ID].effets[i].duree--;
    }
    
}

/*void deathmodif(Combattant* tab, int ID, int* t1, int* t2, int* tmax){
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
}*/

void capacite(Combattant* tab, int n, int c){
    printf("Mais rien ne se passe! (pour l'instant)\n");
}

int deathcheck(Combattant* tab, int ID){
    if(tab==NULL || ID<0){
        printf("Erreur deathcheck\n");
        exit(8);
    }
    if(tab[ID].pv<=0){
        tab[ID].pv=0;
        return 1;
    }
    return 0;
}

void appliquedegats(Combattant* tab, int ID, int dg, int*t1, int* t2, int* tmax){
    if(tab==NULL || ID<0 || ID>=*tmax || dg<0){
        printf("Erreur application des dégâts\n");
        exit(3);
    }
    printf("%s subit %d dégâts!\n",tab[ID].base.nom,dg);
	tab[ID].pv-=dg;
    if(deathcheck(tab,ID)){
		printf("%s est mort!\n", tab[ID].base.nom);
		//deathmodif(tab,ID,t1,t2,tmax);
	}
}

int calcdegats(Combattant* tab, int IDatk, int IDdef,int matk){
    if(tab==NULL || IDatk<0 || IDdef<0 || matk<0){
        printf("Erreur calcul de dégâts\n");
        exit(78);
    }
    int atk=tab[IDatk].atk*matk/100;
    int def=tab[IDdef].def;
    int dg=(atk*(100-def)/100);
    if(dg<=0){
        dg=1;
    }
    return dg;
}

int attaque(Combattant* tab, int IDatk, int IDdef, int mdex){
	//vérification
	if(tab==NULL || IDatk<0 || IDdef<0 || mdex <0){
		printf("erreur opérandes f° attaque\n");
		exit(1);
	}
	printf("%s attaque %s !\n",tab[IDatk].base.nom,tab[IDdef].base.nom);
	int rd1=0,rd2=0;
	int crit=tab[IDatk].dex+mdex;
	rd1=rand()%101;
	rd2=rand()%101;
	//printf("rd1=%d rd2=%d\n",rd1,rd2);
	if (rd1<=tab[IDdef].agl){
		printf("%s évite l'attaque !\n",tab[IDdef].base.nom);
		return 0;
	} else if(rd2<=crit){
		printf("C'est un coup critique!\n");
		return 2;
	} else {
		return 1;
	}
	return -1;
}

void action(Combattant* tab, int aID, int* tmax, int* t1, int* t2){
    //vérification
    if(*tmax==0 || *t1==0 || *t2==0 || tab==NULL || aID<0 || aID>=*tmax || tmax==NULL || t1==NULL || t2==NULL){
    	printf("ERREUR FONCTION ACTION");
    	exit(1);
    }
    //début fonction
    //affichage(tab,*tmax,*t1,*t2);
    printf("C'est le tour de %s! (ID=%d)\n",tab[aID].base.nom,tab[aID].ID);
    int cib,r,m=1,c=0;
    int array[tab[aID].base.ndc+1];
    array[0]=0;
    for(int i=0;i<tab[aID].base.ndc;i++){
        if(tab[aID].base.capa[i].bl==0){
            array[m]=i+1;
            m++;
        }
    }
    c=selection(array,m,"Rentrez le nombre de l'action voulue (0 pour attaquer, ou le numéro de la capacité)\n");
    switch(c){
        case 0:
            if(aID<*t1){    //combattant appatient à l'équipe 1
            	cib=cible(tab,*t1,*tmax,aID,2,2);   //2 car cible l'équipe 2
            } else if(aID>=*t1){    //combattant appartient à l'équipe 2
                cib=cible(tab,*t1,*tmax,aID,1,2);   //1 car attaque l'équipe 1
            }
            r=attaque(tab,aID,cib,0);
            switch (r){
                case 1:
                    appliquedegats(tab,cib,calcdegats(tab,aID,cib,100),t1,t2,tmax);    //dégâts standards
                break;
                case 2:
                    appliquedegats(tab,cib,calcdegats(tab,aID,cib,150),t1,t2,tmax);    //coup critique
                break;
                case -1:
                    printf("Erreur fonction attaque\n");
                    exit(5);
                break;
            }
        break;
        default:
            if(c>=4 || c<=0){
                printf("Erreur selection action\n");
                exit(6);
            }
            capacite(tab,aID,tab[aID].base.capa[c].id);
        break;
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
	//procedure fusionnant les 2 tableaux
    for (int i=0; i<t1; i++){
        ee[i]=e1[i];
    }
    for (int i=0; i<t2; i++){
        ee[i+t1]=e2[i];
    }
    //répétition à chaque tours:
    int a=0,b=0;	//a et b vont compter le nombre de morts dans chaque équipe. Lorsque l'une des deux équipes a autant de morts que de membres d'équipes, le combat s'arrête
    while(a!=t1 && b!=t2){
    	//calcul des stats
    	for(int i=0; i<tmax; i++){
        	if(ee[i].pv>0 && ee[i].ne>0){
                updeffect(ee,i);
        	}
        	for(int j=0;j<ee[i].base.ndc;j++){
        	    if(ee[i].base.capa[j].bl>0){
    		        ee[i].base.capa[j].bl--;
    		    }
            }
        	affichage(ee,tmax,t1,t2);
        }
    	//régulation des actions
    	int tabact[tmax]; //contient les jauges d'actions de tous les combattants
    	for(int i=0; i<tmax; i++){
        	if(ee[i].pv>0){
        		ee[i].act+=ee[i].vit;
        	}
        	if(ee[i].pv<=0){
        	    ee[i].pv=0;
        		ee[i].act=0;
        		ee[i].atk=0;
        	    ee[i].base.atk=0;
                ee[i].def=0;
                ee[i].base.def=0;
                ee[i].vit=0;
                ee[i].base.vit=0;
                ee[i].dex=0;
                ee[i].base.dex=0;
                ee[i].agl=0;
                ee[i].base.agl=0;
        	}
        	tabact[i]=ee[i].act;
    	}
    	
    	int j=IDmax(tabact,tmax);
    	if(ee[j].act>=100){   //définition de la c° d'action
        	ee[j].act=0;
        	action(ee,j,&tmax,&t1,&t2);
    	}
        sleep(1);
        a=0;
        b=0;
        for(int i=0;i<t1;i++){
        	if(deathcheck(ee,i)){
        		a++;
        	}
        }
        for(int i=t1;i<tmax;i++){
        	if(deathcheck(ee,i)){
        		b++;
        	}
        }

    }
}
