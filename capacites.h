#include "structure.h"
#include "ciblage.h"
#include "combat.h"

void soin(Combattant* tab, int ID, int soin){
    //check params
    if(tab==NULL || ID <0 || soin <0){
        printf("erreur soin\n");
        exit(89);
    }
    //process
    tab[ID].pv+=soin;
    printf("%s récupère %d pv!\n",tab[ID].base.nom,soin);
    if(tab[ID].pv > tab[ID].base.pv){
        tab[ID].pv = tab[ID].base.pv;
    }
}

void addeffect(Effet e, Combattant* tab, int ID){
    //locals
    Effet* temp;
    //process
    temp=malloc((tab[ID].ne+1)*sizeof(Effet));
    if(temp==NULL){
        printf("Erreur malloc addeffect\n");
        exit(65);
    }
    for(int i=0; i<tab[ID].ne;i++){
        temp[i]=tab[ID].effets[i];
        //("copie du %dème effet réussie!\n",i);
    }
    temp[tab[ID].ne]=e;
    tab[ID].ne++;
    if(tab[ID].effets!=NULL){
        free(tab[ID].effets);
    }
    tab[ID].effets=temp;
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
    switch (c){
        default:
            printf("ID de capacité non valide...Rien ne se passe!\n");
        break;
        
        case 5001:  //capacités de lambda
            printf("%s utilise pose offensive!\n",tab[n].base.nom);
            e.type=2;
            e.puissance=tab[n].base.atk;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s gagne %d atk!\n",tab[n].base.nom,e.puissance);
        break;
        case 5002:
            printf("%s utilise pose deffensive!\n",tab[n].base.nom);
            e.type=3;
            e.puissance=tab[n].base.def;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s gagne %d def!\n",tab[n].base.nom,e.puissance);
        break;
        case 5003:
            printf("%s utilise repos!\n",tab[n].base.nom);
            soin(tab,n,50);
        break;
        
        case 5004:  //capacités de delta
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s utilise percée!\n",tab[n].base.nom);
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
        case 5005:
            printf("%s utilise aiguisage!\n",tab[n].base.nom);
            e.type=2;
            e.puissance=tab[n].base.atk*25/100;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s gagne %d atk!\n",tab[n].base.nom,e.puissance);
            e.type=6;
            e.puissance=tab[n].base.dex;
            e.duree=6;
            addeffect(e,tab,n);
            printf("%s gagne %d dex!\n",tab[n].base.nom,e.puissance);
        break;
        case 5006:
            printf("%s utilise étirement!\n",tab[n].base.nom);
            e.type=4;
            e.puissance=tab[n].base.vit*50/100;
            e.duree=3;
            addeffect(e,tab,n);
            printf("%s gagne %d vit!\n",tab[n].base.nom,e.puissance);
            e.type=5;
            e.puissance=tab[n].base.agl;
            e.duree=3;
            addeffect(e,tab,n);
            printf("%s gagne %d agl!\n",tab[n].base.nom,e.puissance);
        break;
        
        case 5007:  //capacités d'omega
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s utilise affaiblissement sur %s !\n",tab[n].base.nom,tab[cib].base.nom);
            e.type=-2;
            e.puissance=-tab[cib].base.atk*50/100;
            e.duree=6;
            addeffect(e,tab,cib);
            printf("%s perd %d atk!\n",tab[cib].base.nom,-e.puissance);
        break;
        case 5008:
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,1,2);
            } else {
                cib=cible(tab,t1,tmax,n,2,2);
            }
            printf("%s utilise bouclier sur %s !\n",tab[n].base.nom,tab[cib].base.nom);
            e.type=3;
            e.puissance=tab[cib].base.def*200/100;
            e.duree=3;
            addeffect(e,tab,cib);
            printf("%s gagne %d def!\n",tab[cib].base.nom,e.puissance);
        break;
        case 5009:
            printf("%s utilise soin de groupe!\n",tab[n].base.nom);
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
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,1,2);
            } else {
                cib=cible(tab,t1,tmax,n,2,2);
            }
            printf("%s utilise élan sur %s !\n",tab[n].base.nom,tab[cib].base.nom);
            e.type=4;
            e.puissance=tab[cib].base.vit;
            e.duree=3;
            addeffect(e,tab,cib);
            printf("%s gagne %d vit!\n",tab[cib].base.nom,e.puissance);
        break;
        case 5011:
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,1,2);
            } else {
                cib=cible(tab,t1,tmax,n,2,2);
            }
            printf("%s utilise soin sur %s !\n",tab[n].base.nom,tab[cib].base.nom);
            soin(tab,cib,40);
        break;
        case 5012:
            printf("%s utilise ralentissement!\n",tab[n].base.nom);
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s utilise ralentissement sur %s !\n",tab[n].base.nom,tab[cib].base.nom);
            e.type=-4;
            e.puissance=-tab[cib].base.vit*50/100;
            e.duree=3;
            addeffect(e,tab,cib);
            printf("%s perd %d vit!\n",tab[cib].base.nom,-e.puissance);
        break;
        
        case 5013:  //capacités de alpha
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s utilise vampire!\n",tab[n].base.nom);
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
        
        case 5014:
            printf("%s utilise commandement!\n",tab[n].base.nom);
            e.type=2;
            e.duree=5;
            if(tab[n].ID<t1){
                for (int i=0;i<t1;i++){
                    if(tab[i].pv>0){
                        e.puissance=tab[i].base.atk*50/100;
                        addeffect(e,tab,i);
                        printf("%s gagne %d atk!\n",tab[i].base.nom,e.puissance);
                    }
                }
            } else {
                for (int i=t1;i<tmax;i++){
                    if(tab[i].pv>0){
                        e.puissance=tab[i].base.atk*50/100;
                        addeffect(e,tab,i);
                        printf("%s gagne %d atk!\n",tab[i].base.nom,e.puissance);
                    }
                }
            }
        break;
        case 5015:
            printf("%s utilise inspiration!\n",tab[n].base.nom);
            e.type=4;
            e.puissance=tab[n].base.vit;
            e.duree=1;
            addeffect(e,tab,n);
            printf("%s gagne %d vit!\n",tab[n].base.nom,e.puissance);
            e.type=5;
            e.puissance=100;
            e.duree=1;
            addeffect(e,tab,n);
            printf("%s gagne %d agl!\n",tab[n].base.nom,e.puissance);
            e.type=6;
            e.puissance=100;
            e.duree=1;
            addeffect(e,tab,n);
            printf("%s gagne %d dex!\n",tab[n].base.nom,e.puissance);
        break;
        //capacités beta
        case 5016:
            if(tab[n].ID<t1){
                cib=cible(tab,t1,tmax,n,2,2);
            } else {
                cib=cible(tab,t1,tmax,n,1,2);
            }
            printf("%s utilise coup violent!\n",tab[n].base.nom);
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
        case 5017: 
            printf("%s utilise barricade!\n",tab[n].base.nom);
            e.type=3;
            e.puissance=50;
            e.duree=2;
            addeffect(e,tab,n);
            printf("%s gagne %d def!",tab[n].base.nom,e.puissance);
            soin(tab,n,30);
        break;
        case 5018:
            printf("%s utilise trépignement!\n",tab[n].base.nom);
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
