# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 19:17:40 by samirbouzid       #+#    #+#              #
#    Updated: 2022/02/04 21:12:44 by samirbouzid      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Cub3D

INC=-I./inc

CC = gcc

FLAGSD=-Wall -Wextra -Werror -fsanitize=address
FLAGS=-Wall -Wextra -Werror

LIB_MY=-L libft/ -lft -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit  
LIB_MAC=-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB=$(LIB_MY)

SRCS= ./srcs/main.c \
		./srcs/init.c \
		./srcs/text_parsing.c \
		./srcs/color_parsing.c \
		./srcs/map_parsing.c \
		./srcs/map_utile.c \
		./srcs/raycasting.c \
		./srcs/display.c \
		./srcs/key_detect.c \
		./srcs/moove.c \
		./srcs/utile.c \
		./srcs/test.c \
		./srcs/utile2.c \
		./srcs/minimap.c \
		./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c \

OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGSD) $(INC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean: $(OBJ)
	make $@ -C libft
	rm -f $(OBJ)

fclean: clean
	make $@ -C libft
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re