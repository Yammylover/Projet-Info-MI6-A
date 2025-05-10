#ifndef AF2
#define AF2
#include "structure.h"


void displayfighter(Combattant n){
	printf("\n%s\n-ID:%d\n-HP:%d\n-ATK:%d\n-DEF:%d\n-Agilité:%d\n-Dextérité:%d\n-Action:%d\n-Nbreffets:%d\n",n.base.nom,n.ID,n.pv,n.atk,n.def,n.agl,n.dex,n.act,n.ne);

}

void displaybase(Combattant n){
    printf("\n%s\n-ID:%d\n-PV:%d\n-ATK:%d\n-DEF:%d\n-Agilité:%d\n-Dextérité:%d\n",n.base.nom,n.base.pid,n.base.pv,n.base.atk,n.base.def,n.base.agl,n.base.dex);
}
#endif
