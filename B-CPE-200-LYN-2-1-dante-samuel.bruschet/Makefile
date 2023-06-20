##
## EPITECH PROJECT, 2022
## my_ls
## File description:
## Makefile
##


all:
	@make -C generator
	@make -C solver -s

solver:
	@make -C dante_solver -s

clean:
	@make -C generator clean -s
	@make -C solver clean -s

fclean:
	@make -C generator fclean -s
	@make -C solver fclean -s

re: fclean all
