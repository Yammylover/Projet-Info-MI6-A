#include "combat.h"
#define SIZE 1
int main(void)
{
    Combattant equipe1[SIZE];
    Combattant equipe2[SIZE];
    int t1=SIZE;
    int t2=SIZE;
    //faire une f° capable de récupérer ttes les caractéristiques d'un héro dans le fichier
    IDperso n1;
    /*char string[5]="phan";
    phan.nom=string;*/
    //placebo de création de combattant
    strcpy(n1.nom,"Phan");
    n1.pv=100;
    n1.atk=50;
    n1.def=30;
    n1.vit=4;
    n1.agl=1;
    n1.dex=1;
    n1.ndc=0;
    
    Combattant phan;
    phan.base=n1;
    phan.act=0;
    phan.pv=n1.pv;
    //fin du placebo combattant
    
    equipe1[0]=phan;
    equipe2[0]=phan;
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
