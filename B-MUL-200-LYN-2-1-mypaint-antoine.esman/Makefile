##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my cat
##

SRC=	$(shell find ./src -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

CFLAGS	=	-g -Wall -Wextra -I./include

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lm

all:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) main.c $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
