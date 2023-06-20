##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    src/radar.c \
	    src/destroy_manager.c \
	    src/draw_manager.c \
	    src/event_manager.c \
	    src/init_manager.c \
	    src/update_manager.c \
	    src/destroy_plane_tower_draw.c \
	    src/draw_plane.c \
	    src/init_datas.c \
	    src/init_draw_text.c \
	    src/update_list_plane.c \
	    src/update_plane.c \
	    src/update_place.c

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

NAME    =    my_radar

CFLAGS    =     -L lib/ -I/mylib/include -I include -lm\
		-lcsfml-system -lcsfml-graphics -lcsfml-window -lmy

#LDLIBS    =    -lmy

NEWLIB    =    -fsanitize=address

all:     $(NAME)

$(NAME):	$(OBJ)
	@make -C lib
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -Wall
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
