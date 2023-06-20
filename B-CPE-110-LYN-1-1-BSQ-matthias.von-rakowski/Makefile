##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    bsq.c \
	    bsq_solver.c \
	    init.c \

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

USE    =    bsq

NAME    =    libmy.a

#LDLIBS    =    -lmy

CFLAGS    =    -g3

all:     $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(USE) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	rm -f $(NAME)

allclean: fclean
	rm -f $(USE)

re:	fclean	all

test_build:
	gcc $(TEST) -o unit_test --coverage -lcriterion -Wall

test_clean:
	rm -f *.gcno
	rm -f *.o
	rm -f *.gcda
	rm unit_test

test_run: test_build
	./unit_test
	make test_clean
