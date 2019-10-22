##
## EPITECH PROJECT, 2019
## CPool_infinadd
## File description:
## Project Makefile
##

SRC	=	infinadd.c \
		base.c \
		calcul.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

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
