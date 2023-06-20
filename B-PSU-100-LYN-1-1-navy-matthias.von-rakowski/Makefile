##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    src/navy.c						\
	    src/valid_expression.c				\
	    src/valid_script.c					\
	    src/valid_buffer.c					\
	    src/valid_boats.c					\
	    src/player_1.c					\
	    src/player_2.c					\
	    src/start_game.c					\
	    src/init_map.c					\
	    src/send_pid.c					\
	    src/signal_pid.c					\
	    src/wait_pid.c					\
	    src/map_print.c					\
	    src/valid_code.c					\
	    src/shoot.c						\
	    src/signal_handling.c				\
	    src/protocol_signal.c				\
	    src/set_signal.c					\
	    src/answer.c					\
	    src/hit_or_miss.c					\
	    src/recieved_handler.c				\
	    src/signal_receiving.c				\
	    src/win_condition.c					\
	    src/valid_pid.c						\
	    src/valid_connection.c				\

TEST   =    src/map_print.c \
	    test/test_print.c

OBJ    =    $(SRC:.c=.o)

NAME    =    navy

CFLAGS    =     -L lib/ -I /lib/include -I include -lm -lmy

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
	gcc $(TEST) $(CFLAGS) -o unit_test --coverage -lcriterion -Wall

test_clean:
	rm -f *.gcno
	rm -f *.o
	rm -f *.gcda
	rm unit_test

test_run: test_build
	./unit_test
	make test_clean
