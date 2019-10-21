##
## EPITECH PROJECT, 2019
## CPool_Day00_2019
## File description:
## Template of a standard makefile
##

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	cp my.h ../../include/
	gcc -c *.c -I../../include/ && ar rc $(NAME) *.o
	cp libmy.a ../

clean:
	rm -f *.o
	rm -f $(NAME)
	rm -f ../../include/my.h

re:	clean all
