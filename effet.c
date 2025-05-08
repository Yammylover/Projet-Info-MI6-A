#include "structures.h"

void effet (Combattant patk, Combattant *tab, int t1, int tmax) {

    if (choixcapa( patk) == 5001 ){
        int k=0;
        for (int i=0; i<=2; i++) {
            if(patk.efet[i][3]==0 && i<5) {
                patk.effet[i][0]=4;
                patk.effet[i][1]=-15;
                patk.effet[i][2]=3;
                i=i+1;
                k=k+1;
            }
            for (int j=i; j<5; j++) {
                if(patk.efet[j][3]==0 && i<5) {
                    patk.effet[j][0]=5;
                    patk.effet[j][1]=patk.agl*0.15;
                    patk.effet[j][2]=3;
                    j=i+1;
                    k=k+1;
                }
                for (int h=j; h<5; h++) {
                    if(patk.efet[h][3]==0 && i<5) {
                        patk.effet[h][0]=3;
                        patk.effet[h][1]=patk.def*0.5;
                        patk.effet[h][2]=3;
                        k=k+1;
                    }
                }
            }
            if (k==3) {
                exit(0);
            }
        }
    }
    else if (choixcapa( patk) == 5002 ) {
        int k=0;
        for (int i=0; i<=2; i++) {
            if(patk.efet[i][3]==0) {
                patk.effet[i][0]=2;
                patk.effet[i][1]=patk.atk*0.25;
                patk.effet[i][2]=3;
                i=i+1;
                k=k+1;
            }
            for (int j=i; j<5; j++) {
                if(patk.efet[j][3]==0 && i<5) {
                    patk.effet[j][0]=4;
                    patk.effet[j][1]=patk.vit*0.25;
                    patk.effet[j][2]=3;
                    j=j+1;
                    k=k+1;
                }
                for (int h=j; h<5; h++) {
                    if(patk.efet[h][3]==0 && i<5) {
                        patk.effet[h][0]=6;
                        patk.effet[h][1]=patk.dext*0.25;
                        patk.effet[h][2]=3;
                        h=h+1;
                        k=k+1;
                    }
                    if (k==3) {
                        exit(0);
                    }
                }
            }
        }
    }
    else if (choixcapa( patk) == 5003 ) {
        int n=0;
        int k=0;
        for (int i=0; i<5; i++) {
            if(patk.efet[i][3]==0 && i<5){
                patk.effet[i][0]=2;
                patk.effet[i][1]=patk.atk*1.2 + patk.atk*(rand()%21);
                patk.effet[i][2]=1;
                k=k+1;
                if (k==1) {
                i=5;
                }
            }
        }
        if(IDmax(tab[6], 6)<3) {
            n = choixcible(tab, t1, tmax, patk,2, 2 )-1;
            tab[n].effet[3][0]=-20;

            for (int i=0; i<5; i++) {
                if(tab[n].efet[i][3]==0 && i<5){
                   tab[n].effet[i][0]=4;
                   tab[n].effet[i][1]=-20;
                   tab[n].effet[i][2]=1;
                   j=j+1;
                   exit(0);
                }
            }
        }
        else if(IDmax(tab[6], 6)>=3) {
            n = choixcible(tab, t1, tmax, patk, 2, 1)-1;
            tab[n].effet[3][0]=-20;
            for (int i=0; i<5; i++) {
                if(tab[n].efet[i][3]==0 && i<5){
                    tab[n].effet[i][0]=4;
                    tab[n].effet[i][1]=-20;
                    tab[n].effet[i][2]=1;
                    exit(0);
                }
            }
        }
    }
    if (choixcapa( patk) == 5004) {
        if(IDmax(tab[6], 6)<3) {
            n = choixcible(tab, t1, tmax, patk,2, 1 )-1;
            for (int i=0; i<5; i++) {
                if(tab[n].efet[i][3]==0 && i<5){
                    tab[n].effet[i][0]=1;
                    tab[n].effet[i][1]=50;
                    tab[n].effet[i][2]=1;
                    exit(0);
                }
            }
        }
        else if(IDmax(tab[6], 6)>=3) {
            n = choixcible(tab, t1, tmax, patk, 2, 2)-1;
            for (int i=0; i<5; i++) {
                if(tab[n].efet[i][3]==0 && i<5){
                    tab[n].effet[i][0]=1;
                    tab[n].effet[i][1]=50;
                    tab[n].effet[i][2]=1;
                    exit(0);
                }
            }
        }
    }
    else if (choixcapa( patk) == 5005) {
        if(IDmax(tab[6], 6)>=3) {
            if(IDmax(tab[6], 6)<3) {
                for(int j=0;j<t1;j++){
                    for (int i=0; i<5; i++) {
                        if(tab[j].efet[i][3]==0 && i<5){
                            tab[j].effet[i][0]=3;
                            tab[j].effet[i][1]=tab[j].def*0.6+tab[j].def*0.1*(rand()%11);
                            tab[j].effet[i][2]=2;
                            exit(0);
                        }
                    }
                }
            }
            else if(IDmax(tab[6], 6)>=3) {
                n = choixcible(tab, t1, tmax, patk, 2, 2)-1;
                for (int i=0; i<5; i++) {
                    if(tab[n].efet[i][3]==0 && i<5){
                        tab[n].effet[i][0]=3;
                        tab[n].effet[i][1]=tab[j].def*0.6+tab[j].def*0.1*(rand()%11);
                        tab[n].effet[i][2]=2;
                        exit(0);
                    }
                }
            }
        }
    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5006) {
        int c=0;
        int m=0;
        if(IDmax(tab[6], 6)>=3) {
            c = choixcible(tab, t1, tmax, patk, 2, 1)-1;
            for (int i=0; i<5; i++) {
                if(tab[c].efet[i][3]==0 && i<5){
                    tab[c].effet[i][0]=4;
                    tab[c].effet[i][1]=-(tab[c].vit*0.2);
                    tab[c].effet[i][2]=3;
                    i=i+1;
                    m=m+1;
                }
                for (int j=i; j<5; j++) {
                    if(tab[c].efet[j][3]==0 && i<5){
                        tab[c].effet[j][0]=2;
                        tab[c].effet[j][1]=-(tab[c].atk*0.2);
                        tab[c].effet[j][2]=3;
                        m=m+1;
                    }
                    if (m==2) {
                        exit(0);
                    }
                }
            }
        }

        else if(IDmax(tab[6], 6)<3) {
            c = choixcible(tab, t1, tmax, patk, 2, 2)-1;
            for (int i=0; i<5; i++) {
                if(tab[c].efet[i][3]==0 && i<5){
                    tab[c].effet[i][0]=4;
                    tab[c].effet[i][1]=-(tab[c].vit*0.2);
                    tab[c].effet[i][2]=3;
                    i=i+1;
                    m=m+1;
                }
                for(int j=i; j<5; j++) {
                    if(tab[c].efet[j][3]==0 && i<5){
                        tab[c].effet[j][0]=2;
                        tab[c].effet[j][1]=-(tab[c].atk*0.2);
                        tab[c].effet[j][2]=3;
                        m=m+1;
                    }
                    if (m==2) {
                        exit(0);
                    }
                }
            }
        }
    }
    if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5007)  {
        for (int i=0; i<=2; i++) {
            if(patk.efet[i][3]==0 && i<5) {
                patk.effet[i][0]=1;
                patk.effet[i][1]=30;
                patk.effet[i][2]=1;
                i=i+1;
                k=k+1;
            }
            if(k==1) {
                exit(0);
            }
        }
    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5008) {
        int position;
        printf("veuillez entrer 1 pour selectionner le mode defensif, 2 pour selectionner le mode offensif");
        scanf("%d", &position);
        if(position==1) {
            for (int j=i; j<5; j++) {
                if(patk.efet[j][3]==0 && i<5) {
                    patk.effet[j][0]=3;
                    patk.effet[j][1]=patk.def*0.2;
                    patk.effet[j][2]=3;
                    j=i+1;
                    k=k+1;
                }
                for (int h=j; h<5; h++) {
                    if(patk.efet[h][3]==0 && i<5) {
                        patk.effet[h][0]=2;
                        patk.effet[h][1]=-(patk.atk*0.2);
                        patk.effet[h][2]=3;
                        k=k+1;
                    }
                }
            }
        }
        else if(position==2) {
            for (int j=i; j<5; j++) {
                if(patk.efet[j][3]==0 && i<5) {
                    patk.effet[j][0]=3;
                    patk.effet[j][1]=-(patk.def*0.2);
                    patk.effet[j][2]=3;
                    j=i+1;
                    k=k+1;
                }
                for (int h=j; h<5; h++) {
                    if(patk.efet[h][3]==0 && i<5) {
                        patk.effet[h][0]=2;
                        patk.effet[h][1]=patk.atk*0.2;
                        patk.effet[h][2]=3;
                        k=k+1;
                    }
                }
            }
        }
    }
}
