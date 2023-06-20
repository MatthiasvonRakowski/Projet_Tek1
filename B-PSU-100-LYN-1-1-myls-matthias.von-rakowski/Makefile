##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##
#include <stdlib.h>
SRC    =    flag_d.c \
	    flag_not_a.c \
	    init_info_s.c \
	    last_file_i_hope.c \
	    my_ls.c \
	    the_l_flag.c \
	    last_on_i_know.c \

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

NAME    =    my_ls

CFLAGS    =     -L mylib/ -I/mylib/include -I include -lmy

#LDLIBS    =    -lmy

all:     $(NAME)

$(NAME):	$(OBJ)
	@make -C mylib
	gcc -o $(NAME) -g3 $(OBJ) $(CFLAGS)
	echo -e "compilation complite"
clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	make fclean -C mylib
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
