##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    src/append_element.c		\
			src/a_star.c				\
			src/apply_a_star.c			\
			src/count_line.c			\
			src/free_list.c				\
			src/free_maze.c				\
			src/get_maze.c 				\
			src/init_global.c			\
			src/main.c 					\
			src/pop_element.c			\
			src/print_list.c			\
			src/struct_from_maze.c		\
			src/victoire.c				\

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

NAME    =    solver

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
