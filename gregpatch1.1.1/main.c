#include "combat.h"
#define SIZE 1
int main(void)
{
    Combattant equipe1[2];
    Combattant equipe2[1];
    int t1=2;
    int t2=SIZE;
    //faire une f° capable de récupérer ttes les caractéristiques d'un héro dans le fichier
    IDperso n1;
    //placebo de création de combattant n1
    char string[11]="Lambda";
    n1.nom=string;
    //strcpy(n1.nom,"Phan");
    n1.pv=100;
    n1.atk=30;
    n1.def=20;
    n1.vit=45;
    n1.agl=10;
    n1.dex=5;
    n1.ndc=0;
    
    Combattant c1;
    c1.base=n1;
    c1.act=0;
    c1.pv=n1.pv;
    //fin du placebo combattant 1
    
    //placebo de création de combattant n2
    IDperso n2;
    char word[11]="Delta";
    n2.nom=word;
    //strcpy(n1.nom,"Phan");
    n2.pv=300;
    n2.atk=60;
    n2.def=10;
    n2.vit=49;
    n2.agl=30;
    n2.dex=10;
    n2.ndc=0;
    
    Combattant c2;
    c2.base=n2;
    c2.act=0;
    c2.pv=n2.pv;
    //fin du placebo combattant 2
    
    //début placebo combattant 3
    IDperso n3;
    char word2[11]="Omega";
    n3.nom=word2;
    //strcpy(n1.nom,"Phan");
    n3.pv=150;
    n3.atk=15;
    n3.def=50;
    n3.vit=32;
    n3.agl=0;
    n3.dex=1;
    n3.ndc=0;
    
    Combattant c3;
    c3.base=n3;
    c3.act=0;
    c3.pv=n3.pv;
    //fin placebo combattant 3
    
    equipe1[0]=c1;
    equipe1[1]=c3;
    equipe2[0]=c2;
    //attribution des ID
    for(int i=0; i<t1; i++){
        equipe1[i].ID=i;
    }
    for(int i=0; i<t2; i++){
        equipe2[i].ID=i+t1;
    }

    combat(equipe1,equipe2,t1,t2);
    
    
    return 0;
}
