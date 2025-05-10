Projet: CY-fighters
Principe: un jeu de combat d'équipes tour par tour utilisant le système d'actions de raid shadow legend.
Compilation : main.c code.c structure.h ciblage.c capacites.c combat.c
Mettre les fichiers Alpha jusqu'à Lambda dans le même dossier que l'executable.
Utilisation : Rentrez des valeurs numériques correspondant aux choix disponibles. Rentrer un caractère non numérique vous éjectera du programme.
Description: En lançant le programme, le joueur pourra constituer son équipe avec les combattants présents à l'écran, chacun étant attribué à une classe.
Lorsque 6 combattants auront été choisis (il est possible de choisir des doublons) le combat se lançera automatiquement. La jauge d'actions des personnages se remplit progressivement. Quand elle est pleine le personnage peut agir. Le joueur pourra alors le faire attaquer un combattant dans l'équipe adverse, ou utiliser une capacité spéciale pouvant modifier les statistiques, soigner les alliés, ou autre (notez que le programme vous demandera souvent d'indiquer une cible à cette capacité).
Lorsque tous les combattants de l'une des équipes sont tombés, la partie est finie, et l'équipe survivante gagne.
Il est conseillé de jouer à deux joueurs, chacun donnant les instructions aux joueurs de son équipe (reconnaissable avec le numéro à coté d'eux).



A faire:
-message de victoire (redémarrage programme?)
-update la bibli struture.h avec les nouvelles fonctions
-commentaires
-Securisation
-Rapport sous format pdf
-choix aléatoire de l'attaquant quand même action


liste du descriptif des personnages :


Lambda : 
-PV=100
-Atk=30
-Def=20
-Vit=35
-Agl=10
-Dex=10

5001- position offensive: +100% atk (+30) pendant 6 tours. CD=3
5002- position deffensive: +100% def (+20) pendant 6 tours. CD=3
5003- Repos : Se soigne de 50 PV ; Cd = 3 tours.

Delta : 
- Pv : 80
- Atk : 40
- def : 10
- vit : 42
- agl : 20
- dext : 10
  - Capacités : 
5004- Percée: Attaque avec +20% de chances de critiques. Vide la jauge d'action de la cible. CD=3
5005  - Aiguisage : +25% atk (+10), +100% dex (+5) pendant 6 tours. CD=3
5006  - Etirement : +50% vit (+21) +100% agl (+20), pendant 3 tours. Cd = 3.

Oméga : 
- Pv : 150
- atk : 20
- def : 40
- vit : 20
- agi : 0 
- dext : 1
  - Capacités : 
5007  - Affaiblissement : Un ennemi perd 50% atk pendant 6 tours. CD = 3.
5008  - Bouclier : +200% def à un membre de l'équipe pendant 3 tours. CD = 3.
5009  - Soin groupé : Toute l'équipe se soigne de 20 PV. CD=3
 
  Epsilon
- Pv : 120
- atk : 20
- def : 20
- vit : 43
- agi : 15 
- dext : 15
  - Capacités:
5010  - Elan : +100% vit à un allié pendant 3 tours. CD=3
5011  - Soin : Soigne 40 PV à un allié. CD=3
5012  - Ralentissement : -50% vit à un ennemi pendant 3 tours. CD=3

  Alpha
- Pv : 100
- atk : 50
- def : 7
- vit : 30
- agi : 5 
- dext : 20
    - Capacités:
5013 - Vampire: Attaque et soigne 100% des dégâts infligés. CD=3
5014 - Commandement : Tous les alliés ont +50% atk pendant 5 tours. CD=3
5015 - Inspiration: +100 vit, +100 agl, +100 dex pendant 1 tour. CD=3

  Beta
- Pv : 200
- atk : 50
- def : 0
- vit : 18
- agi : 0 
- dext : 10
    - Capacités:
5016 - Coup violent: Attaque avec 120% atk. CD=3
5017 - Barricade : Soigne 30 PV et gagne 50 def pendant 2 tours. CD=3
5018 - Trépignement : Attaque 2 ennemis aléatoire avec 80% atk. CD=3
