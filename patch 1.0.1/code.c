#include "structure.h"


void affichage(Combattant* equipe1,Combattant* equipe2) {
    char pvaffichage1[3][10];

    strlen(pvaffichage1);//
    char pvaffichage2[3][10];
    strlen(pvaffichage2);
    int indice1[3];//tableau d'indice pour equipe 1
    int indice2[3];//tableau d'indice pour equipe 2
    int str;
    char actaffichage1[3][10];//meme chose que les pv mais pour l'action
    strlen(actaffichage1);
    char actaffichage2[3][10];//meme chose que les pv mais pour l'action
    strlen(actaffichage2);
    int tmax=0;//ligne temporaire

//debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 10 les pv des champions
for(int j=0;j<3;j++) {
    indice1[j]=(equipe1[j].pv)*10/(equipe1[j].base.pv);//calcul permettant la mise a echelle
    for(int i=0;i<10;i++) {
        if(i<indice1[j]){
            pvaffichage1[j][i]='#';
        }
        else {
            pvaffichage1[j][i]=' ';
        }
    }
}
    for(int j=0;j<3;j++) {
        indice2[j]=(equipe2[j].pv)*10/(equipe2[j].base.pv);//calcul permettant la mise a echelle
        for(int i=0;i<10;i++) {
            if(i<indice2[j]){
                pvaffichage2[j][i]='#';
            }
            else {
                pvaffichage2[j][i]=' ';
            }
        }
    }


//mise en place du calcul pour la mise en echelle de l'action
    for(int j=0;j<3;j++) {
        for(int i=0;i<10;i++) {
            if(i<equipe1[j].act) {
                actaffichage1[j][i]='>';
            }
            else {
                actaffichage1[j][i]=' ';
            }
        }
    }

    for(int j=0;j<3;j++) {
        for(int i=0;i<10;i++) {
            if(i<equipe2[j].act) {
                actaffichage2[j][i]='>';
            }
            else {
                actaffichage2[j][i]=' ';
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
            if(equipe1[j].pv>0) {
                printf("%s|%d|",equipe1[j].base.nom,equipe1[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe1[j].base.nom);
            }
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
        if(equipe1[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",pvaffichage1[i][j]);
            }
            printf("]");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=0;i<3;i++) {
        if(equipe1[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",actaffichage1[i][j]);
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
    for (int j=0; j<3;j++) {
        str=strlen(equipe2[j].base.nom);
        if(str<10) {
            if(equipe2[j].pv>0) {
                printf("%s|%d|",equipe2[j].base.nom,equipe2[j].ID+1);
            }
            else {
                printf("%s|💀|",equipe2[j].base.nom);
            }
            for(int i=str+3;i<10;i++) {
                printf(" ");
            }
        }
        else {
            printf("%s",equipe2[j].base.nom);
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
        if(equipe2[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",pvaffichage2[i][j]);
            }
            printf("]");
        }
    }
    printf("  │\n");
    //6eme ligne pour l'act
    printf("│  ");
    for(int i=0;i<3;i++) {
        if(equipe2[i].pv<=0) {
            printf("            ");
        }
        else {
            printf("[");
            for(int j=0;j<10;j++) {
                printf("%c",actaffichage2[i][j]);
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
        for (int j=0; j<3;j++) {
            str=strlen(equipe1[j].base.nom);
            if(str<10) {
                if(equipe1[j].pv>0) {
                    printf("%s|%d|",equipe1[j].base.nom,equipe1[j].ID+1);
                }
                else {
                    printf("%s|💀|",equipe1[j].base.nom);
                }
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
            if(equipe1[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",pvaffichage1[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");
        //6eme ligne pour l'act
        printf("│  ");
        for(int i=0;i<3;i++) {
            if(equipe1[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",actaffichage1[i][j]);
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
        for (int j=0; j<3;j++) {
            str=strlen(equipe2[j].base.nom);
            if(str<10) {
                if(equipe2[j].pv>0) {
                    printf("%s|%d|",equipe2[j].base.nom,equipe2[j].ID+1);
                }
                else {
                    printf("%s|💀|",equipe2[j].base.nom);
                }
                for(int i=str+3;i<10;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s",equipe2[j].base.nom);
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
            if(equipe2[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",pvaffichage2[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");
        //6eme ligne pour l'act
        printf("│  ");
        for(int i=0;i<3;i++) {
            if(equipe2[i].pv<=0) {
                printf("            ");
            }
            else {
                printf("[");
                for(int j=0;j<10;j++) {
                    printf("%c",actaffichage2[i][j]);
                }
                printf("]");
            }
        }
        printf("  │\n");

        printf("│                                        │\n");
        printf("└────────────────────────────────────────┘\n");






}
