##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Project makefile
##

CRITERION =	test_sub.c	\
		../infinadd/infinadd.c     \
		../infinadd/basic.c        \
		../infinadd/calcul.c       \
		../arithmetic.c            \
		../substituate.c           \
		../debug_display.c		\
		test_error.c	\
		../check_error.c		\
		../check_error2.c		\
		test_syntax.c	\
		../check_syntax_error.c

OBJ_CRIT =	$(CRITERION:.c=.o)

CRITERION_NAME =	unit_tests

LIB	=	libmy.a

CFLAGS	+= -Wall -Wextra -I./../include -g -L../lib/my -lmy

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
