
#include "structure.h"


void affichage(Combattant* equipe,int tmax,int t1,int t2,int aID) {
    if(equipe==NULL,tmax<6,t1!=t2,aID<0) {
        exit(1);
    }
    char pvaffichage[6][20];
    int indice[6];//tableau d'indice pour les combattants
    int str;
    int indiceact[6];
    char actaffichage[6][20];//meme chose que les pv mais pour l'action
    int espace;//entier permettant de determiner les espaces entre les effets de 2 agents

    //debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 20 les pv des champions
    for(int j=0;j<tmax;j++) {
        indice[j]=(equipe[j].pv)*20/(equipe[j].base.pv);//calcul permettant la mise a echelle
        for(int i=0;i<20;i++) {
            if(i<indice[j]){
                pvaffichage[j][i]='#'; //on print le caractère si c'est possible
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
                actaffichage[j][i]='>'; //on print le caratère si c'est possible
            }
            else {
                actaffichage[j][i]=' ';
            }
        }
    }


    //debut du print du tableau

    printf("┌─[Equipe 1]───────────────────────────────────────────────────────────────┒\n"
                 "│                                                                          │\n");//2 premières lignes de l'interface
    printf("│   ");

    //bloc de code permettant l'affichage du nom
    for (int j=0; j<t1;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<20) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
                for(int i=str+3;i<20;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
                for(int i=str+4;i<20;i++) {
                    printf(" ");
                }
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

    printf("│   ");
    //bloc de code permettant l'affichage des différents effets qui affecte le perso
    for(int j=0;j<t1;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else{
        for(int i=0;i<equipe[j].ne;i++) {
            if(i*4<=20) {
                switch(equipe[j].effets[i].type) {
                    case 1:
                        printf("(♥)");
                    break;
                    case 2:
                        printf("(⚔)");
                    break;
                    case 3:
                        printf("(🛡)");
                    break;
                    case 4:
                        printf("(⚡)");
                    break;
                    case 5:
                        printf("(👟)");
                    break;
                    case 6:
                        printf("(🧤)");
                    break;
                    case -1:
                        printf("(💜)");
                    break;
                    case -2:
                        printf("(🗡)");
                    break;
                    case -3:
                        printf("(💔)");
                    break;
                    case -4:
                        printf("(⛓)");
                    break;
                    case -5:
                        printf("(🦴)");
                    break;
                    case -6:
                        printf("(🪨)");
                    break;
                }

            }
        }
            espace=20-(equipe[j].ne*4);
            if(espace>0) {
                for(int k=0;k<espace;k++) {
                    printf(" ");
                }
            }
    }

        if(j!=4-1){
            printf("   ");
        }

     }
    printf("  │\n");

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
    //bloc de code intégrant toutes les possibilités pour l'affichage des techniques spéciales
        printf("│ TECHNIQUES SPECIALES                                                     │\n");
switch(equipe[aID].base.pid) {
        case 1001:
        printf("│                                                                          │\n");
        if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Position Offensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ d'attaque                                 │\n");
        }
        else {
        printf("│ |-| Position Offensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ d'attaque                                 │\n");
        }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Position Defensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ de defense                                │\n");
    }
    else {
        printf("│ |-| Position Defensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ de defense                                │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Repos | Recharge : 3                                                 │\n");
        printf("│     ◎ Se soigne de 30 PV                                                 │\n");
    }
    else {
        printf("│ |-| Repos | Recharge : 3                                                 │\n");
        printf("│     ◎ Se soigne de 30 PV                                                 │\n");
    }

        break;
        case 1002:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Percée │ Recharge : 3                                                │\n");
        printf("│     ◎ +20٪ de chances de critiques. Vide la jauge d'action de la cible.  │\n");
    }
    else {
        printf("│ |-| Percée │ Recharge : 3                                                │\n");
        printf("│     ◎ +20٪ de chances de critiques. Vide la jauge d'action de la cible.  │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Aiguisage| Durée : 6 tours / Recharge : 3                            │\n");
        printf("│     ◎ Confère un boost de 25٪ d'attaque et + 100٪ de dextérité           │\n");
    }
    else {
        printf("│ |-| Aiguisage | Durée : 6 tours / Recharge : 3                           │\n");
        printf("│     ◎ Confère un boost de 25٪ d'attaque et + 100٪ de dextérité           │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Etirement | Durée : 3 / Recharge : 3                                 │\n");
        printf("│     ◎ Confère un boost de 50٪ de vitesse et + 100٪ d'agilité             │\n");
    }
    else {
        printf("│ |-| Etirement | Durée : 3 / Recharge : 3                                 │\n");
        printf("│     ◎ Confère un boost de 50٪ de vitesse et + 100٪ d'agilité             │\n");
    }
    break;
        case 1003:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Affaiblissement │ Durée  : 6 / Recharge : 3                          │\n");
        printf("│     ◎ Un ennemi perd 50٪ d'attaque                                       │\n");
    }
    else {
        printf("│ |-| Affaiblissement │ Durée  : 6 / Recharge : 3                          │\n");
        printf("│     ◎ Un ennemi perd 50٪ d'attaque                                       │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Bouclier | Durée : 3 tours / Recharge : 3                            │\n");
        printf("│     ◎ Boost de 200٪ de defense a un membre de l'équipe                   │\n");
    }
    else {
        printf("│ |-| Bouclier | Durée : 3 tours / Recharge : 3                            │\n");
        printf("│     ◎ Boost de 200٪ de defense a un membre de l'équipe                   │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Soin groupe | Recharge : 3                                           │\n");
        printf("│     ◎ Toute l'équipe se soigne de 20 PV                                  │\n");
    }
    else {
        printf("│ |-| Soin groupe | Recharge : 3                                           │\n");
        printf("│     ◎ Toute l'équipe se soigne de 20 PV                                  │\n");
    }
    break;
        case 1004:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Elan │ Durée  : 3 / Recharge : 3                                     │\n");
        printf("│     ◎ +100٪ de vitesse à un allié                                        │\n");
    }
    else {
        printf("│ |-| Elan │ Durée  : 3 / Recharge : 3                                     │\n");
        printf("│     ◎ +100٪ de vitesse à un allié                                        │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Soin | Recharge : 3                                                  │\n");
        printf("│     ◎ Soigne 40 PV à un allié                                            │\n");
    }
    else {
        printf("│ |-| Soin | Recharge : 3                                                  │\n");
        printf("│     ◎ Soigne 40 PV à un allié                                            │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Ralentissement | Durée : 3 / Recharge : 3                            │\n");
        printf("│     ◎ -50٪ de vitesse à un ennemi                                        │\n");
    }
    else {
        printf("│ |-| Ralentissement | Durée : 3 / Recharge : 3                            │\n");
        printf("│     ◎ -50٪ de vitesse à un ennemi                                        │\n");
    }
    break;
        case 1005:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Vampire │ Recharge : 3                                               │\n");
        printf("│     ◎ Attaque et soigne 100٪ des dégâts infligés                         │\n");
    }
    else {
        printf("│ |-| Vampire │ Recharge : 3                                               │\n");
        printf("│     ◎ Attaque et soigne 100٪ des dégâts infligés                         │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Commandement | Durée : 5 / Recharge : 3                              │\n");
        printf("│     ◎ Tous les alliés ont +50٪ d'attaque                                 │\n");
    }
    else {
        printf("│ |-| Commandement | Durée : 5 / Recharge : 3                              │\n");
        printf("│     ◎ Tous les alliés ont +50٪ d'attaque                                 │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Inspiration | Durée : 1 / Recharge : 3                               │\n");
        printf("│     ◎ +100 de vitesse, +100 d'agilité, +100 de dextérité                 │\n");
    }
    else {
        printf("│ |-| Inspiration | Durée : 1 / Recharge : 3                               │\n");
        printf("│     ◎ +100 de vitesse, +100 d'agilité, +100 de dextérité                 │\n");
    }
    break;
        case 1006:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Coup violent │ Recharge : 3                                          │\n");
        printf("│     ◎ Attaque avec 120٪ de son attaque                                   │\n");
    }
    else {
        printf("│ |-| Coup violent │ Recharge : 3                                          │\n");
        printf("│     ◎ Attaque avec 120٪ de son attaque                                   │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Barricade | Durée : 2 / Recharge : 3                                 │\n");
        printf("│     ◎ Soigne 30 PV et gagne 50 de defense                                │\n");
    }
    else {
        printf("│ |-| Barricade | Durée : 2 / Recharge : 3                                 │\n");
        printf("│     ◎ Soigne 30 PV et gagne 50 de defense                                │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Trépignement | Recharge : 3                                          │\n");
        printf("│     ◎ Attaque 2 ennemis aléatoire avec 80٪ de l'attaque                  │\n");
    }
    else {
        printf("│ |-| Trépignement | Recharge : 3                                          │\n");
        printf("│     ◎ Attaque 2 ennemis aléatoire avec 80٪ de l'attaque                  │\n");
    }
    break;


    }


    printf("│                                                                          │\n");
    printf("└──────────────────────────────────────────────────────────────────────────┘\n");

//bloc de code reprennant le meme principe que celui de l'équipe 1, mis a part que les techniques spéciales ne sont pas affichées
    printf("┌─[Equipe 2]───────────────────────────────────────────────────────────────┒\n"
                     "│                                                                          │\n");//2 premières lignes de l'interface
    printf("│   ");
    //print de la 3eme ligne avec les noms et ID des agents
    for (int j=t1; j<tmax;j++) {
        str=strlen(equipe[j].base.nom);
        if(str<20) {
            if(equipe[j].pv>0) {
                printf("%s|%d|",equipe[j].base.nom,equipe[j].ID+1);
                for(int i=str+3;i<20;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);
                for(int i=str+4;i<20;i++) {
                    printf(" ");
                }
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
    printf("│   ");
    for(int j=t1;j<tmax;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else{
            for(int i=0;i<equipe[j].ne;i++) {
                if(i*4<=20) {
                    switch(equipe[j].effets[i].type) {
                        case 1:
                            printf("(♥)");
                        break;
                        case 2:
                            printf("(⚔)");
                        break;
                        case 3:
                            printf("(🛡)");
                        break;
                        case 4:
                            printf("(⚡)");
                        break;
                        case 5:
                            printf("(👟)");
                        break;
                        case 6:
                            printf("(🧤)");
                        break;
                        case -1:
                            printf("(💜)");
                        break;
                        case -2:
                            printf("(🗡)");
                        break;
                        case -3:
                            printf("(💔)");
                        break;
                        case -4:
                            printf("(⛓)");
                        break;
                        case -5:
                            printf("(🦴)");
                        break;
                        case -6:
                            printf("(🪨)");
                        break;
                    }

                }
            }
            espace=20-(equipe[j].ne*4);
            if(espace>0) {
                for(int k=0;k<espace;k++) {
                    printf(" ");
                }
            }
           
        }

        if(j!=7-1){
            printf("   ");
        }

    }
    printf("  │\n");
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
//le bloc de code affichage2 reprends le meme principe que affichage 1, sauf que ici c'est l'équipe 2 qui se voit afficher les techniques spéciales
void affichage2(Combattant* equipe,int tmax,int t1,int t2,int aID) {
    char pvaffichage[6][20];
    int indice[6];//tableau d'indice pour les combattants
    int str;
    int indiceact[6];
    char actaffichage[6][20];//meme chose que les pv mais pour l'action
    int espace;

    //debut du code pour l'affichage utilisateur, ici on print sur une echelle de 0 à 20 les pv des champions
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

                for(int i=str+3;i<20;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);

                for(int i=str+4;i<20;i++) {
                    printf(" ");
                }
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
    printf("│   ");
    for(int j=0;j<t1;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else{
            for(int i=0;i<equipe[j].ne;i++) {
                if(i*4<=20) {
                    switch(equipe[j].effets[i].type) {
                        case 1:
                            printf("(♥)");
                        break;
                        case 2:
                            printf("(⚔)");
                        break;
                        case 3:
                            printf("(🛡)");
                        break;
                        case 4:
                            printf("(⚡)");
                        break;
                        case 5:
                            printf("(👟)");
                        break;
                        case 6:
                            printf("(🧤)");
                        break;
                        case -1:
                            printf("(💜)");
                        break;
                        case -2:
                            printf("(🗡)");
                        break;
                        case -3:
                            printf("(💔)");
                        break;
                        case -4:
                            printf("(⛓)");
                        break;
                        case -5:
                            printf("(🦴)");
                        break;
                        case -6:
                            printf("(🪨)");
                        break;
                    }

                }
            }
            espace=20-(equipe[j].ne*4);
            if(espace>0) {
                for(int k=0;k<espace;k++) {
                    printf(" ");
                }
            }
        }

        if(j!=4-1){
            printf("   ");
        }

    }
    printf("  │\n");
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

                for(int i=str+3;i<20;i++) {
                    printf(" ");
                }
            }
            else {
                printf("%s|💀|",equipe[j].base.nom);

                for(int i=str+4;i<20;i++) {
                    printf(" ");
                }
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
    printf("│   ");
    for(int j=t1;j<tmax;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else{
            for(int i=0;i<equipe[j].ne;i++) {
                if(i*4<=20) {
                    switch(equipe[j].effets[i].type) {
                        case 1:
                            printf("(♥)");
                        break;
                        case 2:
                            printf("(⚔)");
                        break;
                        case 3:
                            printf("(🛡)");
                        break;
                        case 4:
                            printf("(⚡)");
                        break;
                        case 5:
                            printf("(👟)");
                        break;
                        case 6:
                            printf("(🧤)");
                        break;
                        case -1:
                            printf("(💜)");
                        break;
                        case -2:
                            printf("(🗡)");
                        break;
                        case -3:
                            printf("(💔)");
                        break;
                        case -4:
                            printf("(⛓)");
                        break;
                        case -5:
                            printf("(🦴)");
                        break;
                        case -6:
                            printf("(🪨)");
                        break;
                    }
                }

            }
            espace=20-(equipe[j].ne*4);
            if(espace>0) {
                for(int k=0;k<espace;k++) {
                    printf(" ");
                }
            }

        }

        if(j!=7-1){
            printf("   ");
        }


    }
    printf("  │\n");
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
        if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Position Offensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ d'attaque                                 │\n");
        }
        else {
        printf("│ |-| Position Offensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ d'attaque                                 │\n");
        }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Position Defensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ de defense                                │\n");
    }
    else {
        printf("│ |-| Position Defensive | Durée : 6 tours / Recharge : 3                  │\n");
        printf("│     ◎ Confère un boost de 100٪ de defense                                │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Repos | Recharge : 3                                                 │\n");
        printf("│     ◎ Se soigne de 30 PV                                                 │\n");
    }
    else {
        printf("│ |-| Repos | Recharge : 3                                                 │\n");
        printf("│     ◎ Se soigne de 30 PV                                                 │\n");
    }

        break;
        case 1002:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Percée │ Recharge : 3                                                │\n");
        printf("│     ◎ +20٪ de chances de critiques. Vide la jauge d'action de la cible.  │\n");
    }
    else {
        printf("│ |-| Percée │ Recharge : 3                                                │\n");
        printf("│     ◎ +20٪ de chances de critiques. Vide la jauge d'action de la cible.  │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Aiguisage| Durée : 6 tours / Recharge : 3                            │\n");
        printf("│     ◎ Confère un boost de 25٪ d'attaque et + 100٪ de dextérité           │\n");
    }
    else {
        printf("│ |-| Aiguisage | Durée : 6 tours / Recharge : 3                           │\n");
        printf("│     ◎ Confère un boost de 25٪ d'attaque et + 100٪ de dextérité           │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Etirement | Durée : 3 / Recharge : 3                                 │\n");
        printf("│     ◎ Confère un boost de 50٪ de vitesse et + 100٪ d'agilité             │\n");
    }
    else {
        printf("│ |-| Etirement | Durée : 3 / Recharge : 3                                 │\n");
        printf("│     ◎ Confère un boost de 50٪ de vitesse et + 100٪ d'agilité             │\n");
    }
    break;
        case 1003:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Affaiblissement │ Durée  : 6 / Recharge : 3                          │\n");
        printf("│     ◎ Un ennemi perd 50٪ d'attaque                                       │\n");
    }
    else {
        printf("│ |-| Affaiblissement │ Durée  : 6 / Recharge : 3                          │\n");
        printf("│     ◎ Un ennemi perd 50٪ d'attaque                                       │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Bouclier | Durée : 3 tours / Recharge : 3                            │\n");
        printf("│     ◎ Boost de 200٪ de defense a un membre de l'équipe                   │\n");
    }
    else {
        printf("│ |-| Bouclier | Durée : 3 tours / Recharge : 3                            │\n");
        printf("│     ◎ Boost de 200٪ de defense a un membre de l'équipe                   │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Soin groupe | Recharge : 3                                           │\n");
        printf("│     ◎ Toute l'équipe se soigne de 20 PV                                  │\n");
    }
    else {
        printf("│ |-| Soin groupe | Recharge : 3                                           │\n");
        printf("│     ◎ Toute l'équipe se soigne de 20 PV                                  │\n");
    }
    break;
        case 1004:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Elan │ Durée  : 3 / Recharge : 3                                     │\n");
        printf("│     ◎ +100٪ de vitesse à un allié                                        │\n");
    }
    else {
        printf("│ |-| Elan │ Durée  : 3 / Recharge : 3                                     │\n");
        printf("│     ◎ +100٪ de vitesse à un allié                                        │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Soin | Recharge : 3                                                  │\n");
        printf("│     ◎ Soigne 40 PV à un allié                                            │\n");
    }
    else {
        printf("│ |-| Soin | Recharge : 3                                                  │\n");
        printf("│     ◎ Soigne 40 PV à un allié                                            │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Ralentissement | Durée : 3 / Recharge : 3                            │\n");
        printf("│     ◎ -50٪ de vitesse à un ennemi                                        │\n");
    }
    else {
        printf("│ |-| Ralentissement | Durée : 3 / Recharge : 3                            │\n");
        printf("│     ◎ -50٪ de vitesse à un ennemi                                        │\n");
    }
    break;
        case 1005:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Vampire │ Recharge : 3                                               │\n");
        printf("│     ◎ Attaque et soigne 100٪ des dégâts infligés                         │\n");
    }
    else {
        printf("│ |-| Vampire │ Recharge : 3                                               │\n");
        printf("│     ◎ Attaque et soigne 100٪ des dégâts infligés                         │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Commandement | Durée : 5 / Recharge : 3                              │\n");
        printf("│     ◎ Tous les alliés ont +50٪ d'attaque                                 │\n");
    }
    else {
        printf("│ |-| Commandement | Durée : 5 / Recharge : 3                              │\n");
        printf("│     ◎ Tous les alliés ont +50٪ d'attaque                                 │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Inspiration | Durée : 1 / Recharge : 3                               │\n");
        printf("│     ◎ +100 de vitesse, +100 d'agilité, +100 de dextérité                 │\n");
    }
    else {
        printf("│ |-| Inspiration | Durée : 1 / Recharge : 3                               │\n");
        printf("│     ◎ +100 de vitesse, +100 d'agilité, +100 de dextérité                 │\n");
    }
    break;
        case 1006:
            printf("│                                                                          │\n");
    if(equipe[aID].base.capa[0].bl==0){
        printf("│ |1| Coup violent │ Recharge : 3                                          │\n");
        printf("│     ◎ Attaque avec 120٪ de son attaque                                   │\n");
    }
    else {
        printf("│ |-| Coup violent │ Recharge : 3                                          │\n");
        printf("│     ◎ Attaque avec 120٪ de son attaque                                   │\n");
    }
    if(equipe[aID].base.capa[1].bl==0){
        printf("│ |2| Barricade | Durée : 2 / Recharge : 3                                 │\n");
        printf("│     ◎ Soigne 30 PV et gagne 50 de defense                                │\n");
    }
    else {
        printf("│ |-| Barricade | Durée : 2 / Recharge : 3                                 │\n");
        printf("│     ◎ Soigne 30 PV et gagne 50 de defense                                │\n");
    }
    if(equipe[aID].base.capa[2].bl==0){
        printf("│ |3| Trépignement | Recharge : 3                                          │\n");
        printf("│     ◎ Attaque 2 ennemis aléatoire avec 80٪ de l'attaque                  │\n");
    }
    else {
        printf("│ |-| Trépignement | Recharge : 3                                          │\n");
        printf("│     ◎ Attaque 2 ennemis aléatoire avec 80٪ de l'attaque                  │\n");
    }
    break;


    }
    printf("│                                                                          │\n");
    printf("└──────────────────────────────────────────────────────────────────────────┘\n");

}

//affichage ne montrant pas les techniques spéciales
void affichagenormal(Combattant* equipe,int tmax,int t1,int t2) {
    char pvaffichage[6][20];
    int indice[6];//tableau d'indice pour les combattants
    int str;
    int indiceact[6];
    char actaffichage[6][20];//meme chose que les pv mais pour l'action
    int espace;

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
        printf("│   ");
    for(int j=0;j<t1;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else {
        for(int i=0;i<equipe[j].ne;i++) {
            if(i*4<=20) {
                switch(equipe[j].effets[i].type) {
                    case 1:
                        printf("(♥)");
                    break;
                    case 2:
                        printf("(⚔)");
                    break;
                    case 3:
                        printf("(🛡)");
                    break;
                    case 4:
                        printf("(⚡)");
                    break;
                    case 5:
                        printf("(👟)");
                    break;
                    case 6:
                        printf("🧤");
                    break;
                }

                espace=20-(equipe[j].ne*4);
                if(espace>0) {
                    for(int k=0;k<espace;k++) {
                        printf(" ");
                    }
                }
            }
        }
    }
        if(j!=4-1){
            printf("   ");
        }
}
    printf("  │\n");
    printf("│   ");
    for(int j=0;j<t1;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else{
            for(int i=0;i<equipe[j].ne;i++) {
                if(i*4<=20) {
                    switch(equipe[j].effets[i].type) {
                        case 1:
                            printf("(♥)");
                        break;
                        case 2:
                            printf("(⚔)");
                        break;
                        case 3:
                            printf("(🛡)");
                        break;
                        case 4:
                            printf("(⚡)");
                        break;
                        case 5:
                            printf("(👟)");
                        break;
                        case 6:
                            printf("(🧤)");
                        break;
                        case -1:
                            printf("(💜)");
                        break;
                        case -2:
                            printf("(🗡)");
                        break;
                        case -3:
                            printf("(💔)");
                        break;
                        case -4:
                            printf("(⛓)");
                        break;
                        case -5:
                            printf("(🦴)");
                        break;
                        case -6:
                            printf("(🪨)");
                        break;
                    }

                }
            }
            espace=20-(equipe[j].ne*4);
            if(espace>0) {
                for(int k=0;k<espace;k++) {
                    printf(" ");
                }
            }
        }

        if(j!=4-1){
            printf("   ");
        }

    }
    printf("  │\n");

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
printf("│   ");
    for(int j=t1;j<tmax;j++) {
        if(equipe[j].ne==0) {
            printf("                    ");
        }
        else{
            for(int i=0;i<equipe[j].ne;i++) {
                if(i*4<=20) {
                    switch(equipe[j].effets[i].type) {
                        case 1:
                            printf("(♥)");
                        break;
                        case 2:
                            printf("(⚔)");
                        break;
                        case 3:
                            printf("(🛡)");
                        break;
                        case 4:
                            printf("(⚡)");
                        break;
                        case 5:
                            printf("(👟)");
                        break;
                        case 6:
                            printf("(🧤)");
                        break;
                        case -1:
                            printf("(💜)");
                        break;
                        case -2:
                            printf("(🗡)");
                        break;
                        case -3:
                            printf("(💔)");
                        break;
                        case -4:
                            printf("(⛓)");
                        break;
                        case -5:
                            printf("(🦴)");
                        break;
                        case -6:
                            printf("(🪨)");
                        break;
                    }

                }
            }
            espace=20-(equipe[j].ne*4);
            if(espace>0) {
                for(int k=0;k<espace;k++) {
                    printf(" ");
                }
            }
        }

        if(j!=7-1){
            printf("   ");
        }

    }
    printf("  │\n");

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
