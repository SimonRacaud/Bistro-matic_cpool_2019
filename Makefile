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

NAME	=	calc

LIB	=	libmy.a

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

tests_run :
	make -C ./tests tests_run

$(LIB) :
	make -C ./lib/my

clean:
	make -C ./lib/my clean
	make -C ./tests clean
	rm -f $(OBJ)

fclean:	clean
	make -C ./lib/my fclean
	make -C ./tests fclean
	rm -f $(NAME)

re:	fclean all

.PHONY :	clean fclean re
