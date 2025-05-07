#include "combat.h"
#define NBFIGHTERS 3    //à augmenter avec d'autres combattants

Combattant stats(int i, int tmax){
    //Vérification
    if(i<0 || i>=tmax){
    	printf("Erreur indice stats");
    	exit(3);
    }
    Combattant n;
    int nb=0;
    char name[250];
    int tab[NBFIGHTERS];
    for (int i=0; i<NBFIGHTERS; i++){
        tab[i]=i+1;
    }
    FILE* fichier=NULL;
    selection(tab,NBFIGHTERS,"Entrez le numero du champion voulu : \n1 pour Lamda  \n2 pour Delta \n3 pour Omega:\n ");
    /*do{
    printf("Entrez le numero du champion voulu : \n1 pour Lamda  \n2 pour Delta \n3 pour Omega:\n ");
        scanf("%d",&nb);
    //if(scanf("%d",&nb)){
      //  printf("ERREUR SAISIE DES DONNEES\n");
        //exit(6);
    //}
    printf("nb=%d\n",nb);
    }while(nb<1 || nb>4);   //modifier la deuxième condition lors de l'ajout de personnage
    */
    switch(nb){
        case 1:
        	printf("Lambda a ete selectionne\n");
        	
		fichier=fopen("Lambda","r");
	break;
	case 2:
        	printf("Delta a ete selectionne\n");
        	
		fichier=fopen("Delta","r");
	break;
	case 3:
        	printf("Omega a ete selectionne\n");
        	
		fichier=fopen("Omega","r");
	break;
	default:
	    printf("Erreur de saisie de caractère\n");
	    fichier=NULL;
	break;
   }
		if(fichier==NULL){
			printf("Erreur récupération du fichier\n");
			exit(5);
		}
        	//récupération des données
        	if(fscanf(fichier,"%s",name)!=1){	//vérification format fichier et du nom
        		printf("Erreur récupération du nom\n");
        		exit(3);
        	}
        	n.base.nom=malloc(strlen(name)+1);	//création espace de stockage nom
        	if(n.base.nom==NULL){
        		printf("erreur malloc\n");
        	}
        	strcpy(n.base.nom,name);		//attribution nom
        	//printf("%s\n",n.base.nom);
        	if(fscanf(fichier,"%d %d %d %d %d %d %d %d",&(n.base.pid),&(n.base.pv),&(n.base.atk),&(n.base.def),&(n.base.vit),&(n.base.agl),&(n.base.dex),&(n.base.ndc))!=8){	//Attribution des valeurs	//à unifier?
        	    printf("Erreur récupération des données\n");
        	    exit(7);
        	}
        	//printf("ndc=%d\n",n.base.ndc);
        	n.base.capa=malloc(sizeof(Capacite)*n.base.ndc);
        	if(n.base.capa==NULL){
        		printf("Erreur malloc capacité\n");
        		exit(8);
        	}
        	for (int j=0; j<n.base.ndc; j++){
        		//printf("%d\n",j);
        		if(fscanf(fichier,"%d",&(n.base.capa[j].id))!=1){
        			printf("Erreur scanf\n");
        			exit(10);
        		}
        		//printf("%d\n",n.base.capa[j].id);
        	}
        	// valeurs de Combattant
        	n.ID=i;
        	n.pv=n.base.pv;
        	n.atk=n.base.atk;
        	n.def=n.base.def;
        	n.vit=n.base.vit;
        	n.agl=n.base.agl;
        	n.dex=n.base.dex;
        	n.act=0;
        	//printf("%d %d %d\n",n.base.capa[0].id,n.base.capa[1].id,n.base.capa[2].id);
        	//printf("Id=%d\n",n.base.pid);
        	displayfighter(n);
        	fclose(fichier);
    return n;
}



int main(){
// équipe 1
    int t1=1;
    Combattant equipe1[t1];
// équipe 2
    int t2=1;
    Combattant equipe2[t2];

    printf("Selection des champions de l'equipe 1\n\n");
    for(int i=0;i<t1;i++) {
        equipe1[i]=stats(i,t1+t2);
        equipe1[i].ID=i;
    }

    printf("Selection des champions de l'equipe 2\n\n");
    for(int i=0;i<t2;i++) {

        equipe2[i]=stats(i,t1+t2);
        equipe2[i].ID=i+t1;
    }

    combat(equipe1,equipe2,t1,t2);


    return 0;
}
