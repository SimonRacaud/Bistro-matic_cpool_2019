##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Project makefile
##

CRITERION =	test_sub.c		\
		test_div.c		\
		test_mul.c		\
		test_add.c		\
		test_mod.c		\
		../infinadd/infinadd.c	\
		../infinadd/basic.c	\
		../infinadd/calcul.c	\
		../add_sub_arithmetic.c	\
		../mul.c		\
		../div_mod.c		\
		../substituate.c	\
		test_error.c		\
		../check_error.c	\
		../check_error2.c	\
		../check_syntax_error.c	\
		../resolve.c		\
		test_space.c		\
		../eval_expr/eval_expr.c		\
		../eval_expr/parenthesis_seeker.c	\
		../eval_expr/operator_seeker.c		\
		../eval_expr/make_operation.c		\
		../eval_expr/combine_operators.c	\
		test_compute.c				\
		../compute.c				\
		../compute_ext.c

OBJ_CRIT =	$(CRITERION:.c=.o)

CRITERION_NAME =	unit_tests

LIB	=	libmy.a

CFLAGS	+= -Wall -Wextra -I./../include -g -L../lib/my -lmy --coverage

tests_run :	 $(LIB) $(OBJ_CRIT)
		gcc -o $(CRITERION_NAME) $(OBJ_CRIT) $(CFLAGS) -lcriterion --coverage
		./$(CRITERION_NAME)

$(LIB) :
	make -C ../lib/my

clean:
	make -C ../lib/my clean
	rm -f $(OBJ_CRIT)
	rm -f $(CRITERION_NAME)

fclean:	clean
	make -C ../lib/my fclean
	rm -f $(CRITERION_NAME)

re:	fclean all

.PHONY :	clean fclean re
