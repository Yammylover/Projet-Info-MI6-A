#include "structure.h"

Combattant stats(int i){
    Combattant n; //variable utilisé pour ecrire les valeurs de chacuns des combattans
    int nb=0; //nombre entier permettant de choisir quel agent on va selectionner



    printf("┌─[Selection personnage]─────────────────┒\n"
                 "│                                        │\n"
                 "│ Lamda│1│    Delta│2│    Omega│3│       │\n"
                 "│ Poly        Dealer      Tank           │\n"
                 "│                                        │\n"
                 "│ Epsilon|4|                             │\n"
                 "│ Buffer                                 │\n"
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
        n.base.petid=1001;
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
        n.base.petid=1002;
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
        n.base.petid=1003;
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
        n.base.petid=1004;
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
    return n;
}

