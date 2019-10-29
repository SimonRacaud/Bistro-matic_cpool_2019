##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Project makefile
##

SRC	=	infinadd/infinadd.c	\
		infinadd/basic.c	\
		infinadd/calcul.c	\
		eval_expr/eval_expr.c	\
		eval_expr/parenthesis_seeker.c	\
		eval_expr/operator_seeker.c	\
		eval_expr/make_operation.c	\
		eval_expr/combine_operators.c	\
		arithmetic.c		\
		check_error.c		\
		compute.c		\
		display.c		\
		substituate.c		\
		resolve.c		\
		debug_display.c		\
		main.c			\
		check_error2.c		\
		check_syntax_error.c

OBJ	=	$(SRC:.c=.o)

CRITERION =	tests/test_sub.c	\
		infinadd/infinadd.c     \
		infinadd/basic.c        \
		infinadd/calcul.c       \
		eval_expr/eval_expr.c	\
		eval_expr/parenthesis_seeker.c	\
		eval_expr/operator_seeker.c	\
		eval_expr/make_operation.c	\
		eval_expr/combine_operators.c	\
		arithmetic.c            \
		substituate.c           \
		debug_display.c		\
		tests/test_error.c	\
		check_error.c		\
		check_error2.c		\
		tests/test_syntax.c	\
		check_syntax_error.c

OBJ_CRIT =	$(CRITERION:.c=.o)

CRITERION_NAME =	unit_tests

NAME	=	calc

LIB	=	libmy.a

CFLAGS	+= -Wall -Wextra -I./include

CFLAGS_CRIT	+= -Wall -Wextra -I./include -g -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

tests_run :	 $(LIB) $(OBJ_CRIT)
		gcc -o $(CRITERION_NAME) $(OBJ_CRIT) $(CFLAGS_CRIT) -lcriterion --coverage
		./$(CRITERION_NAME)

$(LIB) :
	make -C ./lib/my

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f $(CRITERION_NAME)

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY :	clean fclean re
