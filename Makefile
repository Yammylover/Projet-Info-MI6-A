exec: main.o selection.o combat.o code.o ciblage.o capacites.o
  gcc main.o selection.o combat.o code.o ciblage.o capacites.o exec

main.o: main.c structure.h
  gcc -c main.c

selection.o: selection.c structure.h
  gcc -c selection.c

combat.o: combat.c structure.h
  gcc -c combat.c

code.o: code.c structure.h
  gcc -c code.c

ciblage.o: ciblage.c structure.h
  gcc -c ciblage.c

capacites.o: capacites.c structure.h
  gcc -c capacites.c
