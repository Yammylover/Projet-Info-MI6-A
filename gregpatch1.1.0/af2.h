#include "structures.h"


void displayfighter(Combattant n){
	printf("\n%s\n-HP:%d\n-ATK:%d\n-DEF:%d\n-Agilité:%d\n-Dextérité:%d\n-Action:%d\n",n.base.nom,n.pv,n.atk,n.def,n.agl,n.dex,n.act);

}
