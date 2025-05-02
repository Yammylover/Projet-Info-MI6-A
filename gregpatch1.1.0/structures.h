#include "code.h"

typedef struct {
    int ID;
    int cib1[2]; //premier ID de ciblage, et quantité de cibles
    int cib2[2]; //2ème ID de ciblage, et quantité de cibles
    int ef1; //effet appliqué au 1er ciblage
    int ef2; //effet appliqué au 2ème ciblage
    int cd; //temps de refroidissement (cooldown) à ne pas modifier
    int bl; //temps de refroidissement actif
} Capacite; //structure définissant les caractéristiques d'une capacité

typedef struct {
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
} Combattant;
