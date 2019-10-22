##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Project makefile
##

SRC	=	infinadd/infinadd.c	\
		infinadd/base.c		\
		infinadd/calcul.c	\
		infinadd/main.c		\
		arithmetic.c	\
		base.c		\
		check_error.c	\
		compute.c	\
		display.c	\
		eval_expr.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
