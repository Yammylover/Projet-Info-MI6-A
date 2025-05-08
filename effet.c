#include "effet.h"

void effet (Combattant patk, Combattant *equipe1, Combattant *equipe2,Combattant *tab, int t1, int t2, int tmax) {
    int n=0;
    equipe1 = malloc(t1*(sizeof(Combattant)));
    equipe2 = malloc(t2*(sizeof(Combattant)));
    if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5001 ){
        patk.effet[4].[0]=-15;
        patk.effet[5][1]=patk.agl*0.15;
        patk.effet[3][1]=patk.def*0.5;
    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5002 ){
        patk.effet[1].[1]=patk.atk*0.25;
        patk.effet[3].[1]=patk.vit*0.25;
        patk.effet[5].[1]=patk.dext*0.25;
    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5003 ) {
        int n=0;
        patk.effet[1][1]=patk.atk*1.2 + patk.atk*(rand()%21);
        if(IDmax(tab[6], 6)<3) {
            n = choixcible(tab, t1, tmax, patk,equipe2, ? );
            tab[n].effet[3][0]=-20;
        }
        else if(IDmax(tab[6], 6)>=3) {
            n = choixcible(tab, t1, tmax, patk,equipe1, ? );
            tab[n].effet[3][0]=-20;

        }
    }
    if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5004) {
        int k=0;
        if(IDmax(tab[6], 6)>=3) {
            k = choixcible(tab, t1, tmax, patk,equipe2, ? );
            tab[k].effet[0][1]=50;
        }
        else if(IDmax(tab[6], 6)<3) {
            k = choixcible(tab, t1, tmax, patk,equipe1, ? );
            tab[k].effet[0][1]=50;
        }

    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5005) {
        if(IDmax(tab[6], 6)>=3) {
            for(int i=t1,i< tmax; i++) {
                tab[i].effet[2][1]=tab[i].def*0.6+tab[i].def*0.1*(rand()%11);
            }
        }
        else if(IDmax(tab[6], 6)<3) {
            for(int i=0, i<t1; i++) {
                tab[i].effet[2][1]=tab[i].def*0.6+tab[i].def*0.1*(rand()%11);
            }
        }
    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5006) {
        int c=0;
        if(IDmax(tab[6], 6)<3) {
            c = choixcible(tab, t1, tmax, patk,equipe2, ? );
            tab[c].effet[1][0]=-(tab[c].atk*0.2);
            tab[c].effet[1][0]=-(tab[c].vit*0.2);
        }
        else if(IDmax(tab[6], 6)>=3) {
            c = choixcible(tab, t1, tmax, patk,equipe1, ? );
            tab[c].effet[3][0]=-(tab[c].atk*0.2);
            tab[c].effet[3][0]=-(tab[c].vit*0.2);
        }
    }
    if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5007)  {
        patk.effet[0][1]=30;
    }
    else if (choixcapa( patk, equipe1, equipe2, t1, t2) == 5008) {
        int position;
        printf("veuillez entrer 1 pour selectionner le mode defensif, 2 pour selectionner le mode offensif");
        scanf("%d", &position);
        if(position==1){
            patk.effet[0][2]=patk.def*0.2;
            patk.effet[0][1]=-(patk.atk*0.2);
        }
        else if(position==2){
            patk.effet[0][2]=-(patk.def*0.2);
            patk.effet[0][1]=patk.atk*0.2;
        }
    }
}
