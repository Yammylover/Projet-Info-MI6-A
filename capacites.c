#include "structure.h"

void soin(Combattant* tab, int ID, int soin){    //soigne un combattant en ne dépassant pas les points de vie de base
    //check params
    if(tab==NULL || ID <0 || soin <0){
        printf("erreur soin\n");
        exit(89);
    }
    //process
    tab[ID].pv+=soin;
    printf("%s|%d| récupère %d pv!\n",tab[ID].base.nom,tab[ID].ID+1,soin);
    if(tab[ID].pv > tab[ID].base.pv){
        tab[ID].pv = tab[ID].base.pv;
    }
}

void addeffect(Effet e, Combattant* tab, int ID){    //augmente de 1 la taille du tableau effet et y ajoute un effet
    //locals
    Effet* temp;
    //process
    temp=malloc((tab[ID].ne+1)*sizeof(Effet));    //création tableau temporaire
    if(temp==NULL){
        printf("Erreur malloc addeffect\n");
        exit(65);
    }
    for(int i=0; i<tab[ID].ne;i++){    //copie ancien tableau dans le temporaire
        temp[i]=tab[ID].effets[i];
        //("copie du %dème effet réussie!\n",i);
    }
    temp[tab[ID].ne]=e;    //le dernier effet du temporaire devient l'effet ajouté
    tab[ID].ne++;
    if(tab[ID].effets!=NULL){    //free ancien tableau
        free(tab[ID].effets);
    }
    tab[ID].effets=temp;    //copie temp dans nouveau tableau
}

void capacite(Combattant* tab, int n, int c, int t1, int t2, int tmax){
    //check params
    if(tab==NULL || n<0 || c<0 || t1<0){
        printf("Erreur capacité\n");
        exit(8);
    }
    //locals
    Effet e;
    int dg=0,cib=0,r=0;
    //process
    switch (c){
        default:
            printf("ID de capacité non valide...Rien ne se passe!\n");
        break;
        
        case 5001:  //capacités de lambda
            printf("%s|%d| utilise pose offensive!\n",tab[n].base.nom,tab[n].ID+1);    //ajoute un effet d'attaque
            e.type=2;
            e.puissance=tab[n].base.atk;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d atk!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
        break;
        case 5002:    //ajoute un effet de defense
            printf("%s|%d| utilise pose defensive!\n",tab[n].base.nom,tab[n].ID+1);
            e.type=3;
            e.puissance=tab[n].base.def;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d def!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
        break;
        case 5003:    //soigne les pv
            printf("%s|%d| utilise repos!\n",tab[n].base.nom,tab[n].ID+1);
            soin(tab,n,50);
        break;
        
        case 5004:  //capacités de delta
            if(tab[n].ID<t1){    //cible un ennemi, l'attaque et met à 0 son action
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s|%d| utilise percée!\n",tab[n].base.nom,tab[n].ID+1);
            r=attaque(tab,n,cib,20);
            //printf("r=%d\n",r);
            switch(r){
                case 1: appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,100),t1,t2,tmax);
                        tab[cib].act=0;
                break;
                case 2: appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,150),t1,t2,tmax);
                    tab[cib].act=0;
                break;
                case -1:
                    printf("Erreur fonction attaque\n");
                    exit(5);
                break;
            }
        break;
        case 5005:    //gagne 2 effets
            printf("%s|%d| utilise aiguisage!\n",tab[n].base.nom,tab[n].ID+1);
            e.type=2;
            e.puissance=tab[n].base.atk*25/100;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d atk!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
            e.type=6;
            e.puissance=tab[n].base.dex;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d dex!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
        break;
        case 5006:    //gagne 2 effets
            printf("%s|%d| utilise étirement!\n",tab[n].base.nom,tab[n].ID+1);
            e.type=4;
            e.puissance=tab[n].base.vit*50/100;
            e.duree=3;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d vit!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
            e.type=5;
            e.puissance=tab[n].base.agl;
            e.duree=3;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d agl!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
        break;
        
        case 5007:  //capacités d'omega
            if(tab[n].ID<t1){    //cible un ennemi et lui inflige un effet
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s|%d| utilise affaiblissement sur %s|%d| !\n",tab[n].base.nom,tab[n].ID+1,tab[cib].base.nom,tab[cib].ID+1);
            e.type=-2;
            e.puissance=-tab[cib].base.atk*50/100;
            e.duree=6;
            addeffect(e,tab,cib);
            printf("%s|%d| perd %d atk!\n",tab[cib].base.nom,tab[cib].ID+1,-e.puissance);
        break;
        case 5008:        //cible un allié et lui inflige un effet
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,1,2);
            } else {
                cib=cible(tab,t1,tmax,n,2,2);
            }
            printf("%s|%d| utilise bouclier sur %s|%d| !\n",tab[n].base.nom,tab[n].ID+1,tab[cib].base.nom,tab[cib].ID+1);
            e.type=3;
            e.puissance=tab[cib].base.def*200/100;
            e.duree=3;
            addeffect(e,tab,cib);
            printf("%s|%d| gagne %d def!\n",tab[cib].base.nom,tab[cib].ID+1,e.puissance);
        break;
        case 5009:    //parcourt toute l'équipe vivante et soigne les alliés
            printf("%s|%d| utilise soin de groupe!\n",tab[n].base.nom,tab[n].ID+1);
            if(tab[n].ID<t1){
                for(int i=0;i<t1;i++){
                    if(tab[i].pv>0){
                        soin(tab,i,30);
                    }
                }
            } else {
                for(int i=t1;i<tmax;i++){
                   if(tab[i].pv>0){
                    soin(tab,i,30);
                   }
                }
            }
            
        break;
        
        case 5010:  //capacités d'epsilon
            if(tab[n].ID<t1){    //cible un allié et lui inflige un effet
                cib=cible(tab,t1,tmax,n,1,2);
            } else {
                cib=cible(tab,t1,tmax,n,2,2);
            }
            printf("%s|%d| utilise élan sur %s|%d| !\n",tab[n].base.nom,tab[n].ID+1,tab[cib].base.nom,tab[cib].ID+1);
            e.type=4;
            e.puissance=tab[cib].base.vit;
            e.duree=3;
            addeffect(e,tab,cib);
            printf("%s|%d| gagne %d vit!\n",tab[cib].base.nom,tab[cib].ID+1,e.puissance);
        break;
        case 5011:    //cible un allié et le soigne
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,1,2);
            } else {
                cib=cible(tab,t1,tmax,n,2,2);
            }
            printf("%s|%d| utilise soin sur %s|%d| !\n",tab[n].base.nom,tab[n].ID+1,tab[cib].base.nom,tab[cib].ID+1);
            soin(tab,cib,40);
        break;
        case 5012:    //cible un ennemi et le ralentit
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s|%d| utilise ralentissement sur %s|%d| !\n",tab[n].base.nom,tab[n].ID+1,tab[cib].base.nom,tab[cib].ID+1);
            e.type=-4;
            e.puissance=-tab[cib].base.vit*50/100;
            e.duree=3;
            addeffect(e,tab,cib);
            printf("%s|%d| perd %d vit!\n",tab[cib].base.nom,tab[cib].ID+1,-e.puissance);
        break;
        
        case 5013:  //capacités de alpha
            if(tab[n].ID<t1){    //cible un ennemi, calcule les dégâts, les applique, puis se soigne
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s|%d| utilise vampire!\n",tab[n].base.nom,tab[n].ID+1);
            r=attaque(tab,n,cib,100);
            //printf("r=%d\n",r);
            switch(r){
                case 1: dg=calcdegats(tab[n].atk,tab[cib].def,100);
                break;
                case 2: dg=calcdegats(tab[n].atk,tab[cib].def,150);
                break;
                case -1:
                    printf("Erreur fonction attaque\n");
                    exit(5);
                break;
            }
             appliquedegats(tab,cib,dg,t1,t2,tmax);
             if(dg!=0){
                 soin(tab,n,dg);
             }
        break;
        
        case 5014:    //parcourt l'équipe pour donner un effet
            printf("%s|%d| utilise commandement!\n",tab[n].base.nom,tab[n].ID+1);
            e.type=2;
            e.duree=5;
            if(tab[n].ID<t1){
                for (int i=0;i<t1;i++){
                    if(tab[i].pv>0){
                        e.puissance=tab[i].base.atk*50/100;
                        addeffect(e,tab,i);
                        printf("%s|%d| gagne %d atk!\n",tab[i].base.nom,tab[i].ID+1,e.puissance);
                    }
                }
            } else {
                for (int i=t1;i<tmax;i++){
                    if(tab[i].pv>0){
                        e.puissance=tab[i].base.atk*50/100;
                        addeffect(e,tab,i);
                        printf("%s|%d| gagne %d atk!\n",tab[i].base.nom,tab[i].ID+1,e.puissance);
                    }
                }
            }
        break;
        case 5015:    //donne 3 effets
            printf("%s|%d| utilise inspiration!\n",tab[n].base.nom,tab[n].ID+1);
            e.type=4;
            e.puissance=tab[n].base.vit;
            e.duree=1;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d vit!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
            e.type=5;
            e.puissance=100;
            e.duree=1;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d agl!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
            e.type=6;
            e.puissance=100;
            e.duree=1;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d dex!\n",tab[n].base.nom,tab[n].ID+1,e.puissance);
        break;
        //capacités beta
        case 5016:    //cible un ennemi et attaque avec une valeur différente de 100
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s|%d| utilise coup violent!\n",tab[n].base.nom,tab[n].ID+1);
            r=attaque(tab,n,cib,100);
            switch(r){
                case 1:
                    appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,120),t1,t2,tmax);
                break;
                case 2:
                    appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,180),t1,t2,tmax);
                break;
                case -1:
                    printf("Erreur fonction attaque\n");
                    exit(5);
                break;
            }
        break;
        case 5017: //applique un effet et se soigne
            printf("%s|%d| utilise barricade!\n",tab[n].base.nom,tab[n].ID+1);
            e.type=3;
            e.puissance=50;
            e.duree=2;
            addeffect(e,tab,n);
            printf("%s|%d| gagne %d def!",tab[n].base.nom,tab[n].ID+1,e.puissance);
            soin(tab,n,30);
        break;
        case 5018:    //2 fois, chercher une cible aléatoire et attaquer avec un modificateur inférieur à 100
            printf("%s|%d| utilise trépignement!\n",tab[n].base.nom,tab[n].ID+1);
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,1);
            } else {
                cib=cible(tab,t1,tmax,n,1,1);
            }
            r=attaque(tab,n,cib,100);
            switch(r){
                case 1:
                    appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,80),t1,t2,tmax);
                break;
                case 2:
                    appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,120),t1,t2,tmax);
                break;
                case -1:
                    printf("Erreur fonction attaque\n");
                    exit(5);
                break;
            }
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,1);
            } else {
                cib=cible(tab,t1,tmax,n,1,1);
            }
            r=attaque(tab,n,cib,100);
            switch(r){
                case 1:
                    appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,80),t1,t2,tmax);
                break;
                case 2:
                    appliquedegats(tab,cib,calcdegats(tab[n].atk,tab[cib].def,120),t1,t2,tmax);
                break;
                case -1:
                    printf("Erreur fonction attaque\n");
                    exit(5);
                break;
            }
        break;
    }
}
