#include "structure.h"

int IDmax(int* tab,int taille){
    int max=0;
    int id;
    for (int i=0; i<taille; i++){
        if (tab[i]>max){
            max=tab[i];
            id=i;
        }
    }
    return id;
}

int selection(int* tab,int size, char* phrase){
    //vérification
    if(tab==NULL){
        printf("ERREUR FONCTION SELECTION");
    }
    /*for(int i=0;i<size;i++){  //vérification des entrés dipsonibles
        printf("%d/",tab[i]);
    }*/
    //process
    int a=0,b=0;
    do{
        printf("%s\n",phrase);
        if(scanf("%d",&a)!=1){
            printf("Erreur saisie des données\n");
            exit(8);
        }
        for(int  i=0; i<size; i++){
            if(a==tab[i]){
                b=1;
            }
        }
    } while(b!=1);
    return a;
}
