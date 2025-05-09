
#include "structure.h"


void affichage(Combattant* equipe,int tmax,int t1,int t2,int aID) {
    char pvaffichage[6][20];
    int indice[6];//tableau d'indice pour les combattants
    int str;
    int indiceact[6];
    char actaffichage[6][20];//meme chose que les pv mais pour l'action

//debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 10 les pv des champions
for(int j=0;j<tmax;j++) {
    indice[j]=(equipe[j].pv)*20/(equipe[j].base.pv);//calcul permettant la mise a echelle
    for(int i=0;i<20;i++) {
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
        indiceact[j]=(equipe[j].act)*20/100;
        for(int i=0;i<20;i++) {
            if(i<indiceact[j]) {
                actaffichage[j][i]='>';
            }
            else {
                actaffichage[j][i]=' ';
            }
        }
    }


    //debut du print du tableau, on part du principe que c'est l'equipe 2 qui commence

    printf("┌─[Equipe 1]───────────────────────────────────────────────────────────────┒\n"
                 "│                                                                          │\n");//2 premières lignes de l'interface
    printf("│   ");
    for (int j=0; j<t1;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<20) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
            }
            for(int i=str+3;i<20;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe[j].base.nom);
        }
        if(j!=3-1){
            printf("    ");
        }
    }
    printf("   │\n");
    printf("│                                                                          │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=0;i<t1;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",pvaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=3-1){
            printf("  ");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=0;i<t1;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",actaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=3-1){
            printf("  ");
        }
    }
    printf("  │\n");

    printf("│                                                                          │\n");
    printf("│ ");
    str=strlen(equipe[aID].base.nom);
    if(str<10) {
        printf("%s|%d|",equipe[aID].base.nom,equipe[aID].ID+1);
        for(int i=str+3;i<10;i++) {
            printf(" ");
        }
    }
    printf("                                                               │\n");
    printf("│ TECHNIQUES SPECIALES                                                     │\n");
switch(equipe[aID].base.pid) {
    case 1001:
    printf("│                                                                          │\n");
    printf("│ |1|                                                                      │\n");
    printf("│ |2|                                                                      │\n");
    printf("│ |3|                                                                      │\n");
    break;


}


    printf("│                                                                          │\n");
    printf("└──────────────────────────────────────────────────────────────────────────┘\n");


    printf("┌─[Equipe 2]───────────────────────────────────────────────────────────────┒\n"
                     "│                                                                          │\n");//2 premières lignes de l'interface
    printf("│   ");
    //print de la 3eme ligne avec les noms et ID des agents
    for (int j=t1; j<tmax;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<20) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
            }
            for(int i=str+3;i<20;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe[j].base.nom);
        }
        if(j!=6-1){
            printf("    ");
        }
    }
    printf("   │\n");
    printf("│                                                                          │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=t1;i<tmax;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",pvaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=6-1){
            printf("  ");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=t1;i<tmax;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",actaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=6-1){
            printf("  ");
        }
    }
    printf("  │\n");

    printf("│                                                                          │\n");
    printf("└──────────────────────────────────────────────────────────────────────────┘\n");



}

void affichage2(Combattant* equipe,int tmax,int t1,int t2,int aID) {
    char pvaffichage[6][20];
    int indice[6];//tableau d'indice pour les combattants
    int str;
    int indiceact[6];
    char actaffichage[6][20];//meme chose que les pv mais pour l'action

    //debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 10 les pv des champions
    for(int j=0;j<tmax;j++) {
        indice[j]=(equipe[j].pv)*20/(equipe[j].base.pv);//calcul permettant la mise a echelle
        for(int i=0;i<20;i++) {
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
        indiceact[j]=(equipe[j].act)*20/100;
        for(int i=0;i<20;i++) {
            if(i<indiceact[j]) {
                actaffichage[j][i]='>';
            }
            else {
                actaffichage[j][i]=' ';
            }
        }
    }



    printf("┌─[Equipe 1]───────────────────────────────────────────────────────────────┒\n"
                 "│                                                                          │\n");//2 premières lignes de l'interface
    printf("│   ");
    //print de la 3eme ligne avec les noms et ID des agents
    for (int j=0; j<t1;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<20) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
            }
            for(int i=str+3;i<20;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe[j].base.nom);
        }
        if(j!=3-1){
            printf("    ");
        }
    }
    printf("   │\n");
    printf("│                                                                          │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=0;i<t1;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",pvaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=3-1){
            printf("  ");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=0;i<t1;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",actaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=3-1){
            printf("  ");
        }
    }
    printf("  │\n");

    printf("│                                                                          │\n");
    printf("└──────────────────────────────────────────────────────────────────────────┘\n");


    printf("┌─[Equipe 2]───────────────────────────────────────────────────────────────┒\n"
                 "│                                                                          │\n");//2 premières lignes de l'interface
    printf("│   ");
    for (int j=t1; j<tmax;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<20) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
            }
            for(int i=str+3;i<20;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe[j].base.nom);
        }
        if(j!=6-1){
            printf("    ");
        }
    }
    printf("   │\n");
    printf("│                                                                          │\n");
    //5eme ligne avec les pv des agents
    printf("│  ");
    for(int i=t1;i<tmax;i++) {
        if(equipe[i].pv<=0) {
            printf("                      ");
        }
        else {
            printf("[");
            for(int j=0;j<20;j++) {
                printf("%c",pvaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=6-1){
            printf("  ");
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
            for(int j=0;j<20;j++) {
                printf("%c",actaffichage[i][j]);
            }
            printf("]");
        }
        if(i!=6-1){
            printf("  ");
        }
    }
    printf("  │\n");
    printf("│                                                                          │\n");
    printf("│ ");
    str=strlen(equipe[aID].base.nom);
    if(str<10) {
        printf("%s|%d|",equipe[aID].base.nom,equipe[aID].ID+1);
        for(int i=str+3;i<10;i++) {
            printf(" ");
        }
    }
    printf("                                                               │\n");

    printf("│ TECHNIQUES SPECIALES                                                     │\n");
    switch(equipe[aID].base.pid) {
        case 1001:
            printf("│                                                                          │\n");
        printf("│ |1|                                                                      │\n");
        printf("│ |2|                                                                      │\n");
        printf("│ |3|                                                                      │\n");
        break;


    }
    printf("│                                                                          │\n");
    printf("└──────────────────────────────────────────────────────────────────────────┘\n");

}