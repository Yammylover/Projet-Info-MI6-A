#include "combat.h"
Combattant stats(int i, int tmax){
    //Vérification
    if(i<0 || i>=tmax){
    	printf("Erreur indice stats");
    	exit(3);
    }
    Combattant n;
    int nb=0;
    char name[10];
    int pv=0;
    int atk=0;
    int def=0;
    int vit=0;
    int agl=0;
    int dex=0;
    int ndc=0;
    int pID=0;
    FILE* fichier=NULL;
    printf("Entrez le numero correspondant au champion : \n1 pour Lamda  \n2 pour Delta \n3 pour Omega:\n ");
    scanf("%d",&nb);

    switch(nb){
        case 1:
        	printf("Lambda a ete selectionne\n");
        	
		fichier=fopen("Lambda","r");
		if(fichier==NULL){
			printf("Erreur récupération du fichier\n");
			exit(5);
		}
        	//récupération des valeurs
        	if(fscanf(fichier,"%s ",name)!=1){
        		printf("Erreur récupération du nom\n");
        		exit(3);
        	}
        	/*char c=0;
        	for(int i=0; i<11; i++){
        		c=fgetc(fichier);
        		if(c='#'){
        			i=12;
        		} else{ 
        			name[i]=c;
        		}
        	}
        	n.base.nom=name;
        	displayfighter(n);*/
        	//if(fscanf(fichier,"%d %d %d %d %d %d %d %d",&pID,&pv,&atk,&def,&vit,&agl,&dex,&ndc)!=8){
        	//	printf("Erreur récupération des données\n");
        	//	exit(3);
        	//}
        	fscanf(fichier,"%d",&atk);
	        n.base.pv=pv;
        	n.base.atk=atk;
        	n.base.def=def;
        	n.base.vit=vit;
        	n.base.agl=agl;
        	n.base.dex=dex;
        	n.base.ndc=ndc;
        	n.base.pid=pID;
        	n.base.capa[0].id=5001;
        	n.base.capa[1].id=5002;
        	n.base.capa[2].id=5003;


        	// valeur de Combattant
        	n.ID=i;
        	n.pv=n.base.pv;
        	n.act=0;
        	displayfighter(n);
        	fclose(fichier);
        break;

	case 2:

	break;
    
    	case 3:

	break;
    }
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
