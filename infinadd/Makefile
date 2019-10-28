##
## EPITECH PROJECT, 2019
## CPool_infinadd
## File description:
## Project Makefile
##

SRC	=	infinadd.c	\
		basic.c		\
		calcul.c	\
		main_test.c

SRC_CRIT =	infinadd.c	\
		basic.c		\
		calcul.c	\
		test_infadd.c

OBJ	=	$(SRC:.c=.o)

OBJ_CRIT =	$(SRC_CRIT:.c=.o)

NAME	=	infin_add

CFLAGS	+= -Wall -Wextra -I../include --coverage -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) -L../lib/my -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

test:		$(OBJ_CRIT)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ_CRIT) -L../lib/my -lmy
