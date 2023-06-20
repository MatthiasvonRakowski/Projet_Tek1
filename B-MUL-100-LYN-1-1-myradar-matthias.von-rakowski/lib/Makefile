##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    my_putchar.c \
	    my_putstr.c \
	    my_str_isnum.c \
	    my_strlen.c \
	    my_getnbr.c \
	    my_compute_power.c \
	    my_strcmp.c \
	    my_getnbr_i.c \
	    my_getline_in_array.c \
	    my_transform_float_in_str.c \
	    my_int_in_str.c \
	    my_strcat.c

OBJ    =    $(SRC:.c=.o)

NAME    =    libmy.a

#CFLAGS    =     -I ../include

all:     $(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	rm -f $(NAME)

re:	fclean all

test_build:
	gcc src/*.c test/*.c -o unit_test --coverage -lcriterion -Wall

test_run: test_build
	rm -f *.gcno
	rm -f *.o
	./unit_test
	rm -f *.gcda
	rm unit_test
