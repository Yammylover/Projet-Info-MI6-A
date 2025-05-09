
#include "structure.h"
#include "combat.h"
#include "code.h"
/*#define WINDOWS 1
#define LINUX 2
#define OS LINUX //WINDOWS
#if OS==WINDOWS
#include "windows.h"
#endif*/
#define NBFIGHTERS 3    //à augmenter avec d'autres combattants

Combattant stat1(int i){
    Combattant n; //variable utilisé pour ecrire les valeurs de chacuns des combattans
    int nb=0; //nombre entier permettant de choisir quel agent on va selectionner



    printf("┌─[Selection personnage]─────────────────┒\n"
                 "│                                        │\n"
                 "│ Lamda│1│    Delta│2│    Omega│3│       │\n"
                 "│ Polyvalent  Attaquant   Soutien        │\n"
                 "│                                        │\n"
                 "│ Epsilon|4|  Alpha|5|    Beta|6|        │\n"
                 "│ Soutien     Attaquant   Brute          │\n"
                 "│                                        │\n"
                 "└────────────────────────────────────────┘\n"); //tableau affichant les possibilités d'agents
    printf("Entre le numero correspondant au champion : ");
    scanf("%d",&nb);
    if(nb>4) {
        printf("Agent inconnu");
        exit(1);
    } //verification, si le nombre choisi depasse le nombre d'agent disponible, exit du code


    if(nb==1) {
        printf("Lamda a ete selectionne\n");
        printf(     "┌─[Lamda]────────────────────────────────────┒\n"
                          "│                                            │\n"
                          "│  Pv:100 Atk:20 Def:20 Vit:45 Agi:10 Dex:5  │\n"
                          "│  Compétences :                             │\n"
                          "│       -blabla                              │\n"
                          "│       -ceci                                │\n"
                          "│       -cela                                │\n"
                          "│                                            │\n"
                          "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

        // valeur de IDperso
        n.base.nom="Lambda";
        n.base.pv=100;
        n.base.atk=20;
        n.base.def=20;
        n.base.vit=45;
        n.base.agl=10;
        n.base.dex=5;
        n.base.ndc=3;
        n.base.pid=1001;
        n.base.capa[0].id=50001;
        n.base.capa[1].id=50002;
        n.base.capa[2].id=50003;


        // valeur de Combattant
        n.ID=i+1;
        n.pv=50;
        n.atk=20;
        n.def=20;
        n.vit=45;
        n.agl=10;
        n.dex=5;
        n.act=6;
    }
    else if(nb==2) {
        printf("Delta a ete choisi !\n");
        n.base.nom="Delta";
        n.base.pv=80;
        n.base.atk=40;
        n.base.def=10;
        n.base.vit=49;
        n.base.agl=30;
        n.base.dex=10;
        n.base.ndc=3;
        n.base.pid=1002;
        n.base.capa[0].id=5004;
        n.base.capa[1].id=5005;
        n.base.capa[2].id=5006;


        n.ID=i+1;
        n.pv=0;
        n.atk=40;
        n.def=10;
        n.vit=49;
        n.agl=30;
        n.dex=10;
        n.act=1;

    }
    else if(nb==3) {
        printf("Omega a ete choisi !\n");
        n.base.nom="Omega";
        n.base.pv=150;
        n.base.atk=10;
        n.base.def=40;
        n.base.vit=32;
        n.base.agl=0;
        n.base.dex=1;
        n.base.ndc=3;
        n.base.pid=1003;
        n.base.capa[0].id=5007;
        n.base.capa[1].id=5008;
        n.base.capa[2].id=5009;

        n.ID=i+1;
        n.pv=150;
        n.atk=10;
        n.def=40;
        n.vit=32;
        n.agl=0;
        n.dex=1;
        n.act=9;

    }
    else if(nb==4) {
        printf("Epsilon a ete choisi !\n");
        n.base.nom="Epsilon";
        n.base.pv=120;
        n.base.atk=28;
        n.base.def=20;
        n.base.vit=36;
        n.base.agl=12;
        n.base.dex=12;
        n.base.ndc=3;
        n.base.pid=1004;
        n.base.capa[0].id=5010;
        n.base.capa[1].id=5011;
        n.base.capa[2].id=5012;

        n.ID=i+1;
        n.pv=120;
        n.atk=28;
        n.def=20;
        n.vit=36;
        n.agl=12;
        n.dex=12;
        n.act=4;

    }
    for(int j=0; j<n.nde;j++){
        n.capa[j].cd=3;
        n.capa[j].bl=0;
    }
    return n;
}

Combattant stat2(int i, int tmax){
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
    nb=selection(tab,NBFIGHTERS,"Entrez le numero du champion voulu : \n1 pour Lamda  \n2 pour Delta \n3 pour Omega:\n ");

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
        	n.ne=0;
        	for(int j=0; j<n.nde;j++){
        	    n.capa[j].cd=3;
        	    n.capa[j].bl=0;
        	}
        	//printf("%d %d %d\n",n.base.capa[0].id,n.base.capa[1].id,n.base.capa[2].id);
        	//printf("Id=%d\n",n.base.pid);
        	fclose(fichier);
    return n;
}



int main(){
	//SetConsoleOutputCP(CP_UTF8); //ligne de code permettant l'utilisation de caractere unicode
// équipe 1
    int t1=3;
    Combattant equipe1[t1];
// équipe 2
    int t2=3;
    Combattant equipe2[t2];

    printf("Selection des champions de l'equipe 1\n\n");
    for(int i=0;i<t1;i++) {
        equipe1[i]=stat2(i,t1+t2);
        equipe1[i].ID=i;
    }

    printf("Selection des champions de l'equipe 2\n\n");
    for(int i=0;i<t2;i++) {

        equipe2[i]=stat2(i,t1+t2);
        equipe2[i].ID=i+t1;
    }

    combat(equipe1,equipe2,t1,t2);


    return 0;
}
