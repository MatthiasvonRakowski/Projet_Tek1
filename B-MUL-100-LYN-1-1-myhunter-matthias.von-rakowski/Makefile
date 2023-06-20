##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    hunt.c \
	    init.c \
	    init_dino.c \
	    init_dino_fly.c \
	    init_menu.c \
	    init_lifes.c \
	    main_event.c \
	    event_menu.c \
	    event_game.c \
	    event_resized.c \
	    update_manager.c \
	    update_dino.c \
	    update_dino_fly.c \
	    draw_manager.c \
	    destroy.c \
	    draw_game.c \
	    draw_menu.c \
	    draw_life.c \
	    music_change.c \
	    loose_life_amo.c

TEST    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

NAME    =    my_hunter

CFLAGS    =     -L mylib/ -I/mylib/include -I include -fsanitize=address \
		-lmy -lcsfml-system -lcsfml-audio
#LDLIBS    =    -lmy

all:     $(NAME)

$(NAME):	$(OBJ)
	@make -C mylib
	gcc -o $(NAME) -g3 $(OBJ) $(CFLAGS) -lcsfml-graphics -lcsfml-window

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
