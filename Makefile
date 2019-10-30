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
		mul.c			\
		add_sub_arithmetic.c	\
		div_mod.c		\
		check_error.c		\
		compute.c		\
		compute_ext.c		\
		display.c		\
		substituate.c		\
		resolve.c		\
		debug_display.c		\
		main.c			\
		check_error2.c		\
		check_syntax_error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

LIB	=	libmy.a

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

tests_run :
	make -f Makefile_test tests_run

$(LIB) :
	make -C ./lib/my

clean:
	make -C ./lib/my clean
	make -f Makefile_test clean
	rm -f $(OBJ)

fclean:	clean
	make -C ./lib/my fclean
	make -f Makefile_test fclean
	rm -f $(NAME)

re:	fclean all

.PHONY :	clean fclean re
