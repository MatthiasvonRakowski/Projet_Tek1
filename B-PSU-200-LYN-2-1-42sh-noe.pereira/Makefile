##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

.PHONY:		all clean fclean re

L_REP	=	src/launch_command
ENV_REP	=	env_func
CD_REP 	=	cd_functions
HISTO_REP	=	src/history
BUILT_IN  =  $(L_REP)/sh42_built_in

SRC_NO_MAIN	=	\
		utilitary/clean_str.c	\
		utilitary/rm_allspace.c	\
		utilitary/append_char_to_str.c	\
		src/ast_tree/store_command.c	\
		src/ast_tree/free_tree.c	\
		src/ast_tree/create_tree.c	\
		src/ast_tree/str_to_word_array.c	\
		src/ast_tree/check_parentheses.c	\
		src/pipe/free_pipe.c	\
		src/pipe/pipe_bis.c	\
		src/pipe/pipe_redirection.c	\
		src/pipe/pipe.c	\
		src/pipe/pipe_next.c	\
		src/redirection/redirection.c	\
		src/SYNTAX_ERROR/syntax_error.c	\
		src/SYNTAX_ERROR/syntax_error_bis.c	\
		src/check_if_executable/check_if_do.c 	\
		src/repeat/repeat.c	\
		src/globbing/globbing.c 	\
		src/varenv/varenv.c	\
		src/varenv/alias_replace.c \
		src/varenv/varenv_replace.c	\
		$(L_REP)/launch_command.c	\
		$(L_REP)/launch_command_next.c	\
		$(L_REP)/check_error.c	\
		$(L_REP)/get_paths_and_check_commands.c	\
		$(L_REP)/create_path.c 	\
		$(L_REP)/free_all.c	\
		$(L_REP)/buildin_next.c	\
		$(L_REP)/$(CD_REP)/cd_function.c	\
		$(L_REP)/$(CD_REP)/change_path.c	\
		$(L_REP)/$(CD_REP)/check_error.c	\
		$(L_REP)/$(CD_REP)/ressource.c	\
		$(L_REP)/$(ENV_REP)/check_alphanum_and_return_output.c	\
		$(L_REP)/$(ENV_REP)//setenv.c	\
		$(L_REP)/$(ENV_REP)//unsetenv.c	\
		$(HISTO_REP)/history_functions.c	\
		$(HISTO_REP)/add_red_in_str.c	\
		$(HISTO_REP)/cleaner_str.c	\
		$(HISTO_REP)/add_and_rm_history_cell.c	\
		$(HISTO_REP)/execute_history_com.c	\
		$(HISTO_REP)/change_str_history_command.c	\
		$(HISTO_REP)/add_com_nb.c	\
		$(HISTO_REP)/add_com_str.c	\
		$(HISTO_REP)/free_history.c	\
		$(BUILT_IN)/where_function.c \
		$(BUILT_IN)/which_function.c \
		$(BUILT_IN)/alias.c \

SRC 	=	$(SRC_NO_MAIN) src/main.c

OBJ =   $(SRC:.c=.o)

CC  =   gcc
DEBUG   =   -g3 -p -ggdb3 -DDEBUG_MODE

# To prevent Marvin from flagging my code due to optimizations
RELEASE = -O0 -fno-builtin
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined
ANALYZER	=

CFLAGS  +=  -Wall -Wextra -pedantic -fsigned-char       \
-funsigned-bitfields -Wno-unused-parameter -std=gnu2x
LD_PRELOAD	=

NAME    =   42sh

.PHONY: all re
all: CFLAGS += $(RELEASE)
all: $(NAME)
re: fclean all

.PHONY: debug redebug
debug: CFLAGS += $(DEBUG)
debug: $(NAME)
redebug: fclean debug

.PHONY: sanitize resanitize
sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LD_PRELOAD += -lasan -lubsan
sanitize: $(NAME)
resanitize: fclean sanitize

.PHONY: analyzer reanalyzer
analyzer: ANALYZER += on
analyzer: CFLAGS += $(DEBUG) -fanalyzer
analyzer: $(NAME)
reanalyzer: fclean analyzer

.PHONY: clean_tests
clean_tests:
	@echo [42SH] Removing criterion temporary files.
	@rm -f *.gcda
	@rm -f *.gcno

.PHONY: tests
tests: clean_tests
	@if [[ "$(shell find ../tests/ -type f -name '*.c')" == "" ]]; then	\
		echo "[42SH] No .c file in /tests/ directory - aborting.";		\
		exit 1;															\
	fi
	@echo [42SH] Building tests
	@gcc -g3 $(SRC_NO_MAIN) ../tests/*.c -DRUNNING_CRITERION_TESTS	\
		--coverage -lcriterion $(LDFLAGS) -o $(NAME)
	@echo "[42SH] Running tests :"
	@./42SH
	@echo "[42SH] Writing line coverage log in line_coverage.log."
	@gcovr --exclude tests/ > line_coverage.log
	@echo "[42SH] Writing branch coverage log in branch_coverage.log."
	@gcovr --exclude tests/ --branches > branch_coverage.log

$(NAME): $(OBJ)
	@echo -------------
	@echo [42SH] CC : $(CC)
	@echo [42SH] CFLAGS : $(CFLAGS)
	@echo [42SH] LDFLAGS : $(LD_PRELOAD) $(LDFLAGS)
	@gcc $(OBJ) $(LD_PRELOAD) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@if [[ "$(ANALYZER)" != "" ]]; then\
		$(CC) -c $(CFLAGS) $< -o $@ 2>> analyzer.log;\
	else\
		$(CC) -c $(CFLAGS) $< -o $@;\
	fi

.PHONY: clean_vgcore
clean_vgcore:
	@echo [42SH] Removing Core Dumped files.
	@rm -f vgcore.*
	@rm -f valgring*.log.core.*

.PHONY: clean
clean: clean_tests clean_vgcore
	@echo [42SH] Removing temporary and object files.
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@echo [42SH] Removing binary.
	@rm -f $(NAME)
	@rm -f coding-style-reports.log
