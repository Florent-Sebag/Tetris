##
## Makefile for Makefile in /home/soulie_b/PSU_2015_tetris
## 
## Made by Soulies Clément
## Login   <soulie_b@epitech.net>
## 
## Started on  Mon Feb 22 10:13:42 2016 Soulies Clément
## Last update Sun Mar 20 23:35:19 2016 Florent Sebag
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I./include -Werror -g3

NAME	=	tetris

SRC	=	./src/fenetre.c \
		./src/basic.c \
		./src/create_all_win.c \
		./src/find_path.c \
		./src/find_tetrimino.c \
		./src/get_next_line.c \
		./src/use_struct.c \
		./src/basic_use_map.c \
		./src/put_next.c \
		./src/find_key.c  \
		./src/debug_mode.c \
		./src/first_def_key.c \
		./src/init_mini_key.c \
		./src/init_mini_other_key.c \
		./src/is_keypad.c \
		./src/key_turn.c \
		./src/rm_line.c \
		./src/score.c \
		./src/my_getnbr.c \
		./src/init_key.c \
		./src/init_other_key.c \
		./src/find_err.c \
		./src/call_gnl_to_end.c \
		./src/print_all.c \
		./src/my_strdup.c \
		./src/color.c \
		./src/def_tetri_tab.c \
		./src/free_and_malloc.c \
		./src/print_elem.c \
		./src/next_next_turn.c \
		./src/other_use_struct.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
