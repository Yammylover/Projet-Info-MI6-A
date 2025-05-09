
#include "structure.h"


void affichage(Combattant* equipe,int tmax,int t1,int t2) {
    char pvaffichage[6][10];
    int indice[6];//tableau d'indice pour les combattants
    int indiceact[6];
    int str;
    char actaffichage[6][10];//meme chose que les pv mais pour l'action

//debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 10 les pv des champions
for(int j=0;j<tmax;j++) {
    indice[j]=(equipe[j].pv)*10/(equipe[j].base.pv);//calcul permettant la mise a echelle
    for(int i=0;i<10;i++) {
        if(i<indice[j]){
            pvaffichage[j][i]='#';
        }
        else {
            pvaffichage[j][i]=' ';
        }
    }
}

//mise en place du calcul pour la mise en echelle de l'action
   for(int j=0;j<tmax;j++) {
        indiceact[j]=(equipe[j].act)*10/100;
        for(int i=0;i<10;i++) {
            if(i<indiceact[j]) {
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
    for (int j=0; j<t1;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<10) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
            }
            for(int i=str+3;i<10;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe[j].base.nom);
        }
        if(j!=3-1){
            printf("  ");
        }
    }
    printf("   │\n");
    printf("│                                        │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=0;i<t1;i++) {
        if(equipe[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",pvaffichage[i][j]);
            }
            printf("]");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=0;i<t1;i++) {
        if(equipe[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",actaffichage[i][j]);
            }
            printf("]");
        }
    }
    printf("  │\n");

    printf("│                                        │\n");
    printf("└────────────────────────────────────────┘\n");


    printf("┌─[Equipe 2]─────────────────────────────┒\n"
                 "│                                        │\n");//2 premières lignes de l'interface
    printf("│   ");
    for (int j=t1; j<tmax;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<10) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
            }
            for(int i=str+3;i<10;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe[j].base.nom);
        }
        if(j!=3-1){
            printf("  ");
        }
    }
    printf("   │\n");
    printf("│                                        │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=t1;i<tmax;i++) {
        if(equipe[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",pvaffichage[i][j]);
            }
            printf("]");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=t1;i<tmax;i++) {
        if(equipe[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",actaffichage[i][j]);
            }
            printf("]");
        }
    }
    printf("  │\n");

    printf("│                                        │\n");
    printf("│ TECHNIQUES SPECIALES                   │\n");
    printf("│                                        │\n");
    printf("└────────────────────────────────────────┘\n");


        printf("┌─[Equipe 1]─────────────────────────────┒\n"
                      "│                                        │\n");//2 premières lignes de l'interface
        printf("│   ");
        for (int j=0; j<t1;j++) {
            str=strlen(equipe[j].base.nom);
            if(str<10) {
                if(equipe[j].pv>0) {
                    printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
                }
                else {
                    printf("%s|💀|",equipe[j].base.nom);
                }
                for(int i=str+3;i<10;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s",equipe[j].base.nom);
            }
            if(j!=3-1){
                printf("  ");
            }
        }
        printf("   │\n");
        printf("│                                        │\n");
        //5eme ligne avec les pv des agents
        printf("│  ");
        for(int i=0;i<t1;i++) {
            if(equipe[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",pvaffichage[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");
        //6eme ligne pour l'act
        printf("│  ");
        for(int i=0;i<t1;i++) {
            if(equipe[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",actaffichage[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");

        printf("│                                        │\n");
        printf("│ TECHNIQUES SPECIALES                   │\n");
        printf("│                                        │\n");
        printf("└────────────────────────────────────────┘\n");


        printf("┌─[Equipe 2]─────────────────────────────┒\n"
                         "│                                        │\n");//2 premières lignes de l'interface
        printf("│   ");
        //print de la 3eme ligne avec les noms et ID des agents
        for (int j=t1; j<tmax;j++) {
            str=strlen(equipe[j].base.nom);
            if(str<10) {
                if(equipe[j].pv>0) {
                    printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
                }
                else {
                    printf("%s|💀|",equipe[j].base.nom);
                }
                for(int i=str+3;i<10;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s",equipe[j].base.nom);
            }
            if(j!=3-1){
                printf("  ");
            }
        }
        printf("   │\n");
        printf("│                                        │\n");
        //5eme ligne avec les pv des agents
        printf("│  ");
        for(int i=t1;i<tmax;i++) {
            if(equipe[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",pvaffichage[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");
        //6eme ligne pour l'act
        printf("│  ");
        for(int i=t1;i<tmax;i++) {
            if(equipe[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",actaffichage[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");

        printf("│                                        │\n");
        printf("└────────────────────────────────────────┘\n");






}
