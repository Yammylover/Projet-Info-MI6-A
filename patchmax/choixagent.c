#include "structure.h"
#define SIZE 1
Combattant stats(int i){
    Combattant n;
    int nb=0;
    printf("Entre le numero correspondant au champion : \n1 pour Lamda  \n2 pour Delta \n3 pour Omega:\n ");
    scanf("%d",&nb);

    if(nb==1) {
        printf("Lamda a ete selectionne\n");

        // valeur de IDperso
        n.base.pv=100;
        n.base.atk=20;
        n.base.def=20;
        n.base.vit=45;
        n.base.agl=10;
        n.base.dex=5;
        n.base.ndc=3;
        n.base.capa[0].id=1;
        n.base.capa[1].id=2;
        n.base.capa[2].id=3;


        // valeur de Combattant
        n.ID=i+1;
        n.pv=100;
        n.atk=20;
        n.def=20;
        n.vit=45;
        n.agl=10;
        n.dex=5;
        n.act=0;
    }
    else if(nb==2) {
        printf("Delta a ete choisi !\n");
        n.base.pv=80;
        n.base.atk=40;
        n.base.def=10;
        n.base.vit=49;
        n.base.agl=30;
        n.base.dex=10;
        n.base.ndc=3;
        n.base.capa[0].id=4;
        n.base.capa[1].id=5;
        n.base.capa[2].id=6;


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
        n.base.pv=150;
        n.base.atk=10;
        n.base.def=40;
        n.base.vit=32;
        n.base.agl=0;
        n.base.dex=1;
        n.base.ndc=3;
        n.base.capa[0].id=7;
        n.base.capa[1].id=8;
        n.base.capa[2].id=9;

        n.ID=i+1;
        n.pv=150;
        n.atk=10;
        n.def=40;
        n.vit=32;
        n.agl=0;
        n.dex=1;
        n.act=0;

    }
    return n;
}



int main(){
// équipe 1
    Combattant equipe1[3];
// équipe 2
    Combattant equipe2[3];

    printf("Selection des champions de l'equipe 1\n");
    for(int i=0;i<3;i++) {
        equipe1[i]=stats(i);
        equipe1[i].ID=i;
    }

    printf("Selection des champions de l'equipe 2\n");
    for(int i=0;i<3;i++) {

        equipe2[i]=stats(i);
        equipe2[i].ID=i+3;
    }



    printf("%d\n",equipe1[0].ID);
    printf("%d\n",equipe1[1].ID);
    printf("%d\n",equipe1[2].ID);
    printf("%d\n",equipe2[0].ID);
    printf("%d\n",equipe2[1].ID);
    printf("%d\n",equipe2[2].ID);


    return 0;
}

