#include "structure.h"
#include "windows.h"
#define SIZE 1


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
        n.act=0;
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
        n.pv=80;
        n.atk=40;
        n.def=10;
        n.vit=49;
        n.agl=30;
        n.dex=10;
        n.act=0;

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
        n.act=0;

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
        n.act=0;

    }
    return n;
}



int main(){
    SetConsoleOutputCP(CP_UTF8); //ligne de code permettant l'utilisation de caractere unicode

// équipe 1
    Combattant equipe1[3];
// équipe 2
    Combattant equipe2[3];

//tableau utiliser pour l'affichage des pv dans l'interface utilisateur
    char pvaffichage[3][10];
    strlen(pvaffichage);
    int indice1[3];//tableau d'indice pour equipe 1
    int indice2[3];//tableau d'indice pour equipe 2
    int str;
    char actaffichage[3][10];//meme chose que les pv mais pour l'action
    strlen(actaffichage);
    int indiact1[3];//tableau d'indice act pour equipe 1
    int indiact2[3];//tableau d'indice act pour equipe 2


    //code pour la selection des personnages de l'equipe 1
    printf("Selection des champions de l'equipe 1\n");
    for(int i=0;i<3;i++) {
        equipe1[i]=stats(i);
        equipe1[i].ID=i;
    }

    //code pour la selection des personnages de l'equipe 2
    printf("Selection des champions de l'equipe 2\n");
    for(int i=0;i<3;i++) {

        equipe2[i]=stats(i);
        equipe2[i].ID=i+3;
    }

//debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 10 les pv des champions
for(int j=0;j<3;j++) {
    indice1[j]=(equipe1[j].pv)*10/(equipe1[j].base.pv);//calcul permettant la mise a echelle
    for(int i=0;i<10;i++) {
        if(i<indice1[j]){
            pvaffichage[j][i]='#';
        }
        else {
            pvaffichage[j][i]=' ';
        }
    }
}
//mise en place du calcul pour la mise en echelle de l'action
    for(int j=0;j<3;j++) {
        for(int i=0;i<10;i++) {
            if(i<equipe1[j].act) {
                actaffichage[j][i]='>';
            }
            else {
                actaffichage[j][i]=' ';
            }
        }
    }




    //debut du print du tableau, on part du principe que c'est l'equipe 2 qui commence
    printf("┌─[Equipe 1]─────────────────────────────┒\n"
                 "│                                        │\n");//2 premières lignes de l'interface
    printf("│   ");
    //print de la 3eme ligne avec les noms et ID des agents
    for (int j=0; j<3;j++) {
        str=strlen(equipe1[j].base.nom);
        if(str<10) {
            printf("%s|%d|",equipe1[j].base.nom,equipe1[j].ID);
            for(int i=str+3;i<10;i++) {
                    printf(" ");
            }
        }
        else {
            printf("%s",equipe1[j].base.nom);
        }
        if(j!=3-1){
            printf("  ");
        }
    }
    printf("   │\n");
    printf("│                                        │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=0;i<3;i++) {
        printf("[");
        for(int j=0;j<10;j++) {
            printf("%c",pvaffichage[i][j]);
        }
        printf("]");
    }
    printf("  │\n");
//6eme ligne pour l'act
    printf("│  ");
    for(int i=0;i<3;i++) {
        printf("[");
        for(int j=0;j<10;j++) {
            printf("%c",actaffichage[i][j]);
        }
        printf("]");
    }
    printf("  │\n");

    printf("│                                        │\n");
    printf("└────────────────────────────────────────┘\n");













//code a refaire en reprennant le model juste au dessus pour l'affichage des pv de l'equipe 2
    for(int j=0;j<3;j++) {
        indice2[j]=(equipe2[j].pv)*10/(equipe2[j].base.pv);
        for(int i=0;i<10;i++) {
            if(i<indice2[j]){
                pvaffichage[j][i]='#';
            }
            else {
                pvaffichage[j][i]=' ';
            }
        }
    }




    //brouillon
printf("┌─[Equipe 1]─────────────────────────────┒\n"
             "│                                        │\n"
             "│ %s│%d│     %s│%d│     %s│%d│           │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "└────────────────────────────────────────┘\n",equipe1[0].base.nom,equipe1[0].ID,equipe1[1].base.nom,equipe1[1].ID,equipe1[2].base.nom,equipe1[2].ID);
printf("┌─[Equipe 2]─────────────────────────────┒\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "│                                        │\n"
             "└────────────────────────────────────────┘\n");




    return 0;
}

