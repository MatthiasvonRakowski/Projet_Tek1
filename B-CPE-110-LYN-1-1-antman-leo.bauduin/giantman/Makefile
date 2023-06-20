##
## EPITECH PROJECT, 2022
## antman
## File description:
## Makefile
##

SRC = $(shell find ./src -name "*.c")
TESTS = $(shell find ./tests -name "*.c") \
	src/huffman/node_for_char.c \
	src/huffman/bubble_sort.c \
	src/huffman/binary_tree.c
OBJET = $(SRC:.c=.o)
NAME = giantman
CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -Llib -lmy

$(NAME): $(OBJET)
	$(CC) $(CFLAGS) $(OBJET) -o $(NAME)
	@echo "\033[32m=========Compilation done for $(NAME)========="

all: $(NAME)

clean:
	rm -f $(OBJET)
	@echo "\033[33m=====Clean all files *.o of $(NAME) done====="

fclean: clean
	rm -f $(NAME)
	@echo "\033[33m========Clean the binary $(NAME) done========\033[39m"

g3: fclean
	$(CC) src/*.c $(CFLAGS) -o $(NAME) -g3

re: fclean all

run:
	@gcc *.c -o $(NAME) $(CFLAGS)
	@./$(NAME)

tests_clean:
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f unit_tests
	@echo "\033[33m========All files generate by criterion are deleted========"

tests_build:
	$(CC) $(TESTS) -o unit_tests --coverage -lcriterion $(CFLAGS)
	@echo "\033[32m========Compilation of tests done========"

tests_run: tests_build
	@rm -f *.gcno
	@./unit_tests

.SILENT:$(OBJ)
.PHONY:all clean fclean re run tests_run tests_clean
