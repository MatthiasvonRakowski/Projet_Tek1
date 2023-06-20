##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC    =    $(shell find -name "*.c")

OBJ    =    $(SRC:.c=.o)

USE    =    my_ls

NAME    =    libmy.a

CFLAGS    =     -Lmylib/ -I/mylib/include -lmy

#LDLIBS    =    -lmy

all:     $(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:		clean
	rm -f $(NAME)

re:	fclean	all
