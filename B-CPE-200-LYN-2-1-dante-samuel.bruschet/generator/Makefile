##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    src/generator.c \
	    src/array_manager.c \
	    src/generator_manager.c \
	    src/create_maze.c

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

NAME    =    generator

CFLAGS    =     -I include

#LDLIBS    =    -lmy

NEWLIB    =    -fsanitize=address

all:     $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -Wall
	echo -e "compilation complite"

valgrind: allclean
	gcc src/*.c $(CFLAGS) -o $(NAME) -g3

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:    clean
	rm -f $(NAME)

allclean: fclean
	rm -f $(USE)

g3: allclean
	gcc src/*.c lib/*.c $(CFLAGS) -o $(NAME) -g3


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
