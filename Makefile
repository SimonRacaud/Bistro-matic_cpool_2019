##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Project makefile
##

SRC	=	infinadd/infinadd.c	\
		infinadd/basic.c	\
		infinadd/calcul.c	\
		arithmetic.c		\
		check_error.c		\
		compute.c		\
		display.c		\
		substituate.c		\
		resolve.c		\
		debug_display.c		\
		main.c			\
		check_error2.c

OBJ	=	$(SRC:.c=.o)

CRITERION =	tests/test_sub.c	\
		infinadd/infinadd.c     \
		infinadd/basic.c        \
		infinadd/calcul.c       \
		arithmetic.c            \
		substituate.c           \
		debug_display.c

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
