#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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