#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

typedef struct{
	float atk;
	float def;
	float agl;
	float hp;
	char name[32];
} Ninja;

Ninja createFighter(){
	Ninja n;
	n.atk=rand()%6+5;
	n.def=rand()%3+2;
	n.agl=(rand()%11+10)/100.0;
	n.hp=rand()%21+80;
	printf("\nRentrez le nom du combattant: \n");
	scanf("%s",n.name);
	return n;
}

void displayfighter(Ninja n){
	printf("\n%s\n-ATK:%f\n-DEF:%f\n-Agilité:%f\n-HP:%f\n",n.name,n.atk,n.def,n.agl,n.hp);

}
	
void FIGHT(Ninja a, Ninja b){
	float dodge;
	float damage=0;
	float critical;
	while(a.hp>0 && b.hp>0){
		dodge=(rand()%101)/100.0;
		critical=(rand()%101)/100.0;
		if (dodge>b.agl){
			if(a.agl>=critical){
				damage=a.atk*2;
				b.hp-=damage;
				printf("%s takes a strong hit from %s for %f damages!\n",b.name,a.name,damage);
			} else{			
				damage=a.atk-b.def;
				if(damage<0){
					damage=0;
				}
				b.hp-=damage;
				printf("%s takes %f damages from %s.\n",b.name,damage,a.name);
			}
		}
		else {
			printf("%s dodges attack from %s!\n",b.name,a.name);
		}
		dodge=(rand()%101)/100.0;
		critical=(rand()%101)/100.0;
		if (dodge>a.agl){
			if(b.agl>=critical){
				damage=b.atk*2;
				a.hp-=damage;
				printf("%s takes a strong hit from %s for %f damages!\n",a.name,b.name,damage);
			} else{			
				damage=a.atk-b.def;
				if(damage<0){
					damage=0;
				}
				a.hp-=damage;
				printf("%s takes %f damages from %s.\n",a.name,damage,b.name);
			}
		}
		else {
			printf("%s dodges attack from %s!\n",a.name,b.name);
		}
		sleep(1);
	}
//check result
	if (a.hp<=0 && b.hp<=0){
		printf("Ex-equo\n");
	}
	else if("a.hp<=0"){
		printf("%s gagne!\n", b.name);
	}
	else ("%s gagne!\n",a.name);
}

int main(){
	srand(time(NULL));
	Ninja Nikoli;
	Ninja Carey;
	Nikoli=createFighter(Nikoli);
	displayfighter(Nikoli);
	Carey=createFighter(Carey);
	displayfighter(Carey);
	sleep(1);
	FIGHT(Nikoli, Carey);
return 0;
}
