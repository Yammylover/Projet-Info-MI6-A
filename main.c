
#include "structure.h"
/*#define WINDOWS 1
#define LINUX 2
#define OS LINUX //WINDOWS
#if OS==WINDOWS
#include "windows.h"
#endif*/
#define NBFIGHTERS 6    //à augmenter avec d'autres combattants

Combattant stat1(int i){
    Combattant n; //variable utilisé pour ecrire les valeurs de chacuns des combattans
    int nb=0; //nombre entier permettant de choisir quel agent on va selectionner



    printf("┌─[Selection personnage]─────────────────┒\n"
                 "│                                        │\n"
                 "│ Lambda│1│   Delta│2│    Omega│3│       │\n"
                 "│ Polyvalent  Attaquant   Soutien        │\n"
                 "│                                        │\n"
                 "│ Epsilon|4|  Alpha|5|    Beta|6|        │\n"
                 "│ Soutien     Attaquant   Brute          │\n"
                 "│                                        │\n"
                 "└────────────────────────────────────────┘\n"); //tableau affichant les possibilités d'agents
    printf("Entre le numero correspondant au champion : ");
    scanf("%d",&nb);
    if(nb>NBFIGHTERS) {
        printf("Agent inconnu");
        exit(1);
    } //verification, si le nombre choisi depasse le nombre d'agent disponible, exit du code


    switch(nb) {
    case 1:
        printf("Lambda a ete selectionne\n");
        printf(     "┌─[Lambda]───────────────────────────────────┒\n"
                          "│                                            │\n"
                          "│  Pv:100 Atk:30 Def:20 Vit:35 Agi:10 Dex:10 │\n"
                          "│  Compétences :                             │\n"
                          "│       -Pose offensive                      │\n"
                          "│       -Pose deffensive                     │\n"
                          "│       -Repos                               │\n"
                          "│                                            │\n"
                          "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

        // valeur de IDperso
        n.base.nom="Lambda";
        n.base.pv=100;
        n.base.atk=30;
        n.base.def=20;
        n.base.vit=35;
        n.base.agl=10;
        n.base.dex=10;
        n.base.ndc=3;
        n.base.pid=1001;
        n.base.capa[0].id=5001;
        n.base.capa[1].id=5002;
        n.base.capa[2].id=5003;


        // valeur de Combattant
        n.ID=i;
        n.pv=50;
        n.atk=30;
        n.def=20;
        n.vit=35;
        n.agl=10;
        n.dex=10;
        n.act=0;
    break;
    case 2:
        printf("Delta a ete choisi !\n");
    	printf(     "┌─[Delta]────────────────────────────────────┒\n"
						  "│                                            │\n"
						  "│  Pv:80 Atk:40 Def:10 Vit:42 Agi:20 Dex:10  │\n"
						  "│  Compétences :                             │\n"
						  "│       -Percée                              │\n"
						  "│       -Aiguisage                           │\n"
						  "│       -Etirement                           │\n"
						  "│                                            │\n"
						  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi
        n.base.nom="Delta";
        n.base.pv=80;
        n.base.atk=40;
        n.base.def=10;
        n.base.vit=42;
        n.base.agl=20;
        n.base.dex=10;
        n.base.ndc=3;
        n.base.pid=1002;
        n.base.capa[0].id=5004;
        n.base.capa[1].id=5005;
        n.base.capa[2].id=5006;


        n.ID=i;
        n.pv=80;
        n.atk=40;
        n.def=10;
        n.vit=42;
        n.agl=20;
        n.dex=10;
        n.act=0;

    break;
    case 3:
        printf("Omega a ete choisi !\n");
    	printf(     "┌─[Omega]────────────────────────────────────┒\n"
						  "│                                            │\n"
						  "│  Pv:150 Atk:20 Def:40 Vit:20 Agi:0 Dex:1   │\n"
						  "│  Compétences :                             │\n"
						  "│       -Affaiblissement                     │\n"
						  "│       -Bouclier                            │\n"
						  "│       -Soin groupé                         │\n"
						  "│                                            │\n"
						  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

        n.base.nom="Omega";
        n.base.pv=150;
        n.base.atk=20;
        n.base.def=40;
        n.base.vit=20;
        n.base.agl=0;
        n.base.dex=1;
        n.base.ndc=3;
        n.base.pid=1003;
        n.base.capa[0].id=5007;
        n.base.capa[1].id=5008;
        n.base.capa[2].id=5009;

        n.ID=i;
        n.pv=150;
        n.atk=20;
        n.def=40;
        n.vit=20;
        n.agl=0;
        n.dex=1;
        n.act=0;

    break;
    case 4:
        printf("Epsilon a ete choisi !\n");
    	printf(     "┌─[Epsilon]──────────────────────────────────┒\n"
						  "│                                            │\n"
						  "│  Pv:120 Atk:20 Def:20 Vit:43 Agi:15 Dex:15 │\n"
						  "│  Compétences :                             │\n"
						  "│       -Elan                                │\n"
						  "│       -Soin                                │\n"
						  "│       -Ralentissement                      │\n"
						  "│                                            │\n"
						  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

        n.base.nom="Epsilon";
        n.base.pv=120;
        n.base.atk=20;
        n.base.def=20;
        n.base.vit=43;
        n.base.agl=15;
        n.base.dex=15;
        n.base.ndc=3;
        n.base.pid=1004;
        n.base.capa[0].id=5010;
        n.base.capa[1].id=5011;
        n.base.capa[2].id=5012;

        n.ID=i;
        n.pv=120;
        n.atk=20;
        n.def=20;
        n.vit=43;
        n.agl=15;
        n.dex=15;
        n.act=0;
    break;
    case 5:
    printf("Alpha a ete choisi !\n");
    	printf( "┌─[Alpha]────────────────────────────────────┒\n"
					  "│                                            │\n"
					  "│  Pv:100 Atk:50 Def:7 Vit:30 Agi:5 Dex:20   │\n"
					  "│  Compétences :                             │\n"
					  "│       -Vampire                             │\n"
					  "│       -Commandement                        │\n"
					  "│       -Inspiration                         │\n"
					  "│                                            │\n"
					  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

        n.base.nom="Alpha";
        n.base.pv=100;
        n.base.atk=50;
        n.base.def=7;
        n.base.vit=30;
        n.base.agl=5;
        n.base.dex=20;
        n.base.ndc=3;
        n.base.pid=1005;
        n.base.capa[0].id=5013;
        n.base.capa[1].id=5014;
        n.base.capa[2].id=5015;

        n.ID=i;
        n.pv=n.base.pv;
        n.atk=n.base.atk;
        n.def=n.base.def;
        n.vit=n.base.vit;
        n.agl=n.base.agl;
        n.dex=n.base.dex;
        n.act=0;
    break;
    case 6:
    printf("Beta a ete choisi !\n");
    	printf( "┌─[Beta]─────────────────────────────────────┒\n"
					  "│                                            │\n"
					  "│  Pv:200 Atk:50 Def:0 Vit:18 Agi:0 Dex:10   │\n"
					  "│  Compétences :                             │\n"
					  "│       -Coup violent                        │\n"
					  "│       -Barricade                           │\n"
					  "│       -Trépignement                        │\n"
					  "│                                            │\n"
					  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

        n.base.nom="Beta";
        n.base.pv=200;
        n.base.atk=50;
        n.base.def=0;
        n.base.vit=18;
        n.base.agl=0;
        n.base.dex=10;
        n.base.ndc=3;
        n.base.pid=1006;
        n.base.capa[0].id=5016;
        n.base.capa[1].id=5017;
        n.base.capa[2].id=5018;

        n.ID=i;
        n.pv=n.base.pv;
        n.atk=n.base.atk;
        n.def=n.base.def;
        n.vit=n.base.vit;
        n.agl=n.base.agl;
        n.dex=n.base.dex;
        n.act=0;
    break;
    }
    n.effets=NULL;
    n.ne=0;
    for(int j=0; j<n.base.ndc;j++){
        n.base.capa[j].cd=3;
        n.base.capa[j].bl=0;
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
    printf("┌─[Selection personnage]─────────────────┒\n"
                 "│                                        │\n"
                 "│ Lambda│1│    Delta│2│    Omega│3│      │\n"
                 "│ Polyvalent  Attaquant   Soutien        │\n"
                 "│                                        │\n"
                 "│ Epsilon|4|  Alpha|5|    Beta|6|        │\n"
                 "│ Soutien     Attaquant   Brute          │\n"
                 "│                                        │\n"
                 "└────────────────────────────────────────┘\n"); //tableau affichant les possibilités d'agents
    nb=selection(tab,NBFIGHTERS,"Entrez le numero du champion voulu :\n ");

    switch(nb){
        case 1:
        	printf("Lambda a ete selectionne\n");
    	printf(     "┌─[Lambda]───────────────────────────────────┒\n"
						  "│                                            │\n"
						  "│  Pv:100 Atk:30 Def:20 Vit:35 Agi:10 Dex:10 │\n"
						  "│  Compétences :                             │\n"
						  "│       -Pose offensive                      │\n"
						  "│       -Pose deffensive                     │\n"
						  "│       -Repos                               │\n"
						  "│                                            │\n"
						  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi

		fichier=fopen("Lambda","r");
	break;
	case 2:
        	printf("Delta a ete selectionne\n");
    	printf(     "┌─[Delta]────────────────────────────────────┒\n"
						  "│                                            │\n"
						  "│  Pv:80 Atk:40 Def:10 Vit:42 Agi:20 Dex:10  │\n"
						  "│  Compétences :                             │\n"
						  "│       -Percée                              │\n"
						  "│       -Aiguisage                           │\n"
						  "│       -Etirement                           │\n"
						  "│                                            │\n"
						  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi


		fichier=fopen("Delta","r");
	break;
	case 3:
        	printf("Omega a ete selectionne\n");
    	printf(     "┌─[Omega]────────────────────────────────────┒\n"
						  "│                                            │\n"
						  "│  Pv:150 Atk:20 Def:40 Vit:20 Agi:0 Dex:1   │\n"
						  "│  Compétences :                             │\n"
						  "│       -Affaiblissement                     │\n"
						  "│       -Bouclier                            │\n"
						  "│       -Soin groupé                         │\n"
						  "│                                            │\n"
						  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi


		fichier=fopen("Omega","r");
	break;
	case 4:
        	printf("Epsilon a ete selectionne\n");
    	printf(     "┌─[Epsilon]──────────────────────────────────┒\n"
				  "│                                            │\n"
				  "│  Pv:120 Atk:20 Def:20 Vit:43 Agi:15 Dex:15 │\n"
				  "│  Compétences :                             │\n"
				  "│       -Elan                                │\n"
				  "│       -Soin                                │\n"
				  "│       -Ralentissement                      │\n"
				  "│                                            │\n"
				  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi


		fichier=fopen("Epsilon","r");
	break;
	case 5:
        	printf("Alpha a ete selectionne\n");
    	printf( "┌─[Alpha]────────────────────────────────────┒\n"
					  "│                                            │\n"
					  "│  Pv:100 Atk:50 Def:7 Vit:30 Agi:5 Dex:20   │\n"
					  "│  Compétences :                             │\n"
					  "│       -Vampire                             │\n"
					  "│       -Commandement                        │\n"
					  "│       -Inspiration                         │\n"
					  "│                                            │\n"
					  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi


		fichier=fopen("Alpha","r");
	break;
	case 6:
        	printf("Beta a ete selectionne\n");
    	printf( "┌─[Beta]─────────────────────────────────────┒\n"
					  "│                                            │\n"
					  "│  Pv:200 Atk:50 Def:0 Vit:18 Agi:0 Dex:10   │\n"
					  "│  Compétences :                             │\n"
					  "│       -Coup violent                        │\n"
					  "│       -Barricade                           │\n"
					  "│       -Trépignement                        │\n"
					  "│                                            │\n"
					  "└────────────────────────────────────────────┘\n"); //tableau pour afficher les stats de l'agent choisi


		fichier=fopen("Beta","r");
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
        	n.base.capa=malloc(sizeof(Capacite)*n.base.ndc);	//allocation du tableau de capacités
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
        	n.effets=NULL;
        	for(int j=0; j<n.base.ndc;j++){
        	    n.base.capa[j].cd=3;
        	    n.base.capa[j].bl=0;
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

    printf("Selection des champions de l'equipe 1\n\n");	//appel de chaque combattant de chaque équipe
    for(int i=0;i<t1;i++) {
        equipe1[i]=stat2(i,t1+t2);
        equipe1[i].ID=i;
    }

    printf("Selection des champions de l'equipe 2\n\n");
    for(int i=0;i<t2;i++) {

        equipe2[i]=stat2(i,t1+t2);
        equipe2[i].ID=i+t1;
    }

    if(combat(equipe1,equipe2,t1,t2)==1){
	    printf("Victoire de l'équipe 1!\n");
    } else {
	    printf("Victoire de l'équipe 2!\n");
    }

    return 0;
}
