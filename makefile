# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c code.c ciblage.c capacites.c combat.c  
OBJ = $(SRC:.c=.o)
EXEC = CYfiiiii

# Règles
all: $(EXEC)

$(EXEC): $(OBJ)
    $(CC) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ)

mrproper: clean
    rm -f $(EXEC)

.PHONY: all clean mrproper
