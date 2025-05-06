#include "combat.h"

Combattant stats(int i, int tmax){
    //Vérification
    if(i<0 || i>=tmax){
    	printf("Erreur indice stats");
    	exit(3);
    }
    Combattant n;
    int nb=0;
    char name[250];
    
    FILE* fichier=NULL;
    printf("Entrez le numero correspondant au champion : \n1 pour Lamda  \n2 pour Delta \n3 pour Omega:\n ");
    scanf("%d",&nb);

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
        	printf("%s\n",n.base.nom);
        	fscanf(fichier,"%d",&(n.base.pid));	//à unifier?
        	fscanf(fichier,"%d",&(n.base.pv));
        	fscanf(fichier,"%d",&(n.base.atk));
        	fscanf(fichier,"%d",&(n.base.def));
        	fscanf(fichier,"%d",&(n.base.vit));
        	fscanf(fichier,"%d",&(n.base.agl));
        	fscanf(fichier,"%d",&(n.base.dex));
        	fscanf(fichier,"%d",&(n.base.ndc));
        	n.base.capa=malloc(sizeof(Capacite)*n.base.ndc);
        	if(n.base.capa==NULL){
        		printf("Erreur malloc capacité\n");
        	}
        	for (int j=0; j<n.base.ndc; j++){
        		printf("%d\n",j);
        		fscanf(fichier,"%d",&(n.base.capa[j]));
        		printf("%d\n",n.base.capa[j]);
        	}
        	// valeur de Combattant
        	n.ID=i;
        	n.pv=n.base.pv;
        	n.atk=n.base.atk;
        	n.def=n.base.def;
        	n.vit=n.base.vit;
        	n.agl=n.base.agl;
        	n.dex=n.base.dex;
        	n.act=0;
        	printf("%d %d %d\n",n.base.capa[0],n.base.capa[1],n.base.capa[2]);
        	printf("Id=%d\n",n.base.pid);
        	displayfighter(n);
        	fclose(fichier);
    return n;
}



int main(){
// équipe 1
    int t1=3;
    Combattant equipe1[t1];
// équipe 2
    int t2=3;
    Combattant equipe2[t2];

    printf("Selection des champions de l'equipe 1\n\n");
    for(int i=0;i<3;i++) {
        equipe1[i]=stats(i,t1+t2);
        equipe1[i].ID=i;
    }

    printf("Selection des champions de l'equipe 2\n\n");
    for(int i=0;i<3;i++) {

        equipe2[i]=stats(i,t1+t2);
        equipe2[i].ID=i+t1;
    }



    printf("%d\n",equipe1[0].ID);
    printf("%d\n",equipe1[1].ID);
    printf("%d\n",equipe1[2].ID);
    printf("%d\n",equipe2[0].ID);
    printf("%d\n",equipe2[1].ID);
    printf("%d\n\n",equipe2[2].ID);
    
    combat(equipe1,equipe2,3,3);


    return 0;
}
