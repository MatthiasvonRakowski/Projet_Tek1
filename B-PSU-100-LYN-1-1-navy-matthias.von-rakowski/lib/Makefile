##
## EPITECH PROJECT, 2022
## makefile
## File description:
## a short file description
##

SRC     =   my_putstr.c 					\
			my_strlen.c 					\
			my_strcmp.c 					\
			my_put_nbr.c					\
			my_str_to_word_array.c			\
			my_strncpy.c					\
			char_is_valid.c					\
			str_is_number.c					\
			my_atoi.c						\
    		my_printf.c						\
			char_is_number.c				\
            display_space_flt.c				\
            display_space_hexa.c			\
            display_space_int.c				\
			display_space_oct.c				\
            display_space_str.c				\
            display_zero_float.c			\
			flags.c							\
			flag1.c							\
			flag2.c							\
			flag3.c							\
			flag4.c							\
			flags_functions.c				\
			flags_functions2.c				\
			get_every_flag.c				\
			my_compute_power_rec.c			\
			my_evil_str.c					\
			my_putchar.c					\
			my_put_float.c					\
			my_put_float_hexa.c				\
			my_put_hexa.c					\
			my_put_nbr.c					\
			my_put_oct.c					\
			my_str2dlen.c					\
			my_put_scientific.c				\
			my_reputstr.c					\
			my_strlen.c						\
			my_strncpy.c					\
			my_put_adress.c    				\
			my_put_fltg.c    				\
			my_put_g.c    					\
			my_put_sctg.c    				\
			size_flt.c						\

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all : $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
