##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile my files
##

NAME	=	lem_in
CC		=	gcc
CFLAGS	=	-Wall -Wextra -I./include/ -g3

SRCDIR	=	src
BUILDDIR=	build

SRC		=	main.c \
			lemin.c \
			room.c \
			graph.c \
			my_strtok.c \
			wstr_to_array.c \
			links.c \
			parse.c \
			get_map.c \
			bfs.c \
			error_h.c \
			clear_path.c \
			put_ants.c \
			int_h.c \
			graph_h.c \
			lexeur.c \
			parser.c \
			parsing_h.c \
			debug.c \
			part_h.c \
			room_h.c \
			str_h.c \
			verif_h.c \
			link_h.c \
			puts_h.c \
			puts_endlines.c \

SRCS	=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ		=	$(addprefix $(BUILDDIR)/, $(SRC:.c=.o))

LIBDIR	=	lib/my
LIB		=	-L$(LIBDIR) -lmy

vpath %.c	$(SRCDIR):$(SRCDIR)/tools:$(SRCDIR)/parsing:$(SRCDIR)/solver

all: lib $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $^ -o $@ $(LIB)

$(BUILDDIR)/%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: lib

lib:
		$(MAKE) -C $(LIBDIR)

clean:
		$(MAKE) -C $(LIBDIR) clean
		rm -f $(OBJ)

fclean: clean
		$(MAKE) -C $(LIBDIR) fclean
		rm -f $(NAME)

gauthier:all
	cp lem_in .script/unit_lem
	python3 .script/unit_lem/unit.py

re: fclean all
