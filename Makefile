##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Puigsagur
##

CC		=	gcc

CFLAGS	=	-Werror -Wall -Wextra -W

SRC		=	main.c				\
			src/start.c			\
			src/init.c			\
			src/hero.c			\
			src/hero_movement.c	\
			src/animation.c		\


OBJ		=	$(SRC:.c=.o)

NAME	=	myBoss

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
