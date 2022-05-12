##
## EPITECH PROJECT, 2020
## BSQ
## File description:
## Makefile
##

SRC =	src/my_runner.c		\
		src/my_utils.c		\
		src/my_text.c		\
		src/my_window.c		\
		src/my_hub.c		\
		src/my_credit.c		\
		src/my_game.c		\
		src/my_events.c		\
		src/my_move.c		\
		src/int_to_char.c	\
		src/my_parallax.c	\
		src/my_among.c		\
		src/my_music.c		\
		src/my_loose.c		\

OBJ =	$(SRC:.c=.o)

NAME =	my_runner

all:
	gcc -o $(NAME) $(SRC) -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system -g -g3

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f vgcore.*

re:		fclean all