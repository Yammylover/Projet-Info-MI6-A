#ifndef STR_H
#define STR_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct {    //structure contenant les effets spéciaux
    int type;
    int puissance;
    int duree;
} Effet;

typedef struct {
    int id; //ID de la capacité, ELLES COMMENCENT A 5001.
    int nom[20];
    int cib1[2]; //premier ID de ciblage, et quantité de cible (a ne pas definir)
    int ef1; //effet appliqué au 1er ciblage
    int cd; //temps de refroidissement (cooldown) à ne pas modifier
    int bl; //temps de refroidissement actif
    int cde;
} Capacite; //structure définissant les caractéristiques d'une capacité

typedef struct{
    int pid; // ID du personnage pour remplacer le nom, COMMENCE A 1001.
    char* nom; //nom du personnage qui set à identifier son fichier
    int pv; //base de PV
    int atk; //base d'atk
    int def; //base de def
    int vit; //base de vit
    int agl; //base d'agilité
    int dex; //base de dextérité
    int ndc; //nombre de capacités       //à vérifier pour éviter les fuites de données
    Capacite *capa; //pointeur du tableau de taille ndc
} IDperso; //défini l'identité du perso, qui sert à définir et redéfinir ses stats en cas de modifications

typedef struct {
    int ID; //id du personnage dans le terrain (placement)
    int pv; //pv modifiés activement, le personnage meurt s'ils atteignent 0
    int atk; //atk modifiée activement en se basant sur la stat de base et les modificateurs actuels
    int def; //idem
    int vit; //idem, défini la fréquence d'action
    int agl; //idem, défini les chances d'esquiver les attaques
    int dex; //idem, défini les chances de coup critique (150% de dégâts, ignorants les modifs de stats [à la pokémon])
    IDperso base; //base du perso permettant de savoir les stats de base du perso
    int act; //jauge d'action du personnage (pour l'instant, sur 10)
    Effet* effets;  //tableau contenant les effets subis par le personnage
    int ne; //quantité d'effets subis et taille du tableau effets
} Combattant;

void affichage(Combattant* equipe,int tmax,int t1,int t2);
int deathcheck(Combattant* tab, int ID);
void appliquedegats(Combattant* tab, int ID, int dg, int t1, int t2, int tmax);
int calcdegats(int atk, int def,int matk);
int attaque(Combattant* tab, int IDatk, int IDdef, int mdex);
void action(Combattant* tab, int aID, int* tmax, int* t1, int* t2);
int combat(Combattant* e1, Combattant* e2,int t1, int t2);
void soin(Combattant* tab, int ID, int soin);
void addeffect(Effet e, Combattant* tab, int ID);
void capacite(Combattant* tab, int n, int c, int t1, int t2, int tmax);
int IDmax(int* tab,int taille);
int selection(int* tab,int size, char* phrase);
void updeffect(Combattant* tab, int ID);
int IDmax(int* tab,int taille);
int selection(int* tab,int size, char* phrase);
int rando(int min, int max);
int cible(Combattant* tab, int t1, int tmax, int ID, int ecible, int tcible);

#endif
