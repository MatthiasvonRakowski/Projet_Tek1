##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    src/game_begin.c \
	    src/game_init.c \
	    src/loose_or_win.c \
	    src/moove.c \
	    src/my_str_to_word_array_info.c \
	    src/press_space.c \
	    src/sokoban.c

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

NAME    =    my_sokoban

CFLAGS    =     -L lib/ -I/include

LDLIBS    =    -lmy

all:     $(NAME)

$(NAME):	$(OBJ)
	@make -C lib
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDLIBS) -Wall -lncurses
	echo -e "compilation complite"

valgrind:
	@make -C lib
	gcc src/*.c -g3

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	make fclean -C lib
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
