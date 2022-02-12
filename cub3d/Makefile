# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 19:17:40 by samirbouzid       #+#    #+#              #
#    Updated: 2022/02/12 10:27:28 by sbouzidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Cub3D

INC=-I./inc

CC = gcc

FLAGS=-Wall -Wextra -Werror

LIB_MY=-L libft/ -lft -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit  
LIB_SCHOOL= -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
LIB=$(LIB_SCHOOL)

SRCS= ./srcs/main.c \
		./srcs/init.c \
		./srcs/text_parsing.c \
		./srcs/color_parsing.c \
		./srcs/map_parsing.c \
		./srcs/map_utile.c \
		./srcs/check_len.c \
		./srcs/raycasting.c \
		./srcs/display.c \
		./srcs/key_detect.c \
		./srcs/moove.c \
		./srcs/rotate.c \
		./srcs/utile.c \
		./srcs/utile2.c \
		./srcs/minimap.c \
		./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c \

BONUS_SRCS= ./srcs/main.c \
		./srcs/init.c \
		./srcs/text_parsing.c \
		./srcs/color_parsing.c \
		./srcs/map_parsing.c \
		./srcs/map_utile.c \
		./srcs/raycasting.c \
		./srcs/display.c \
		./srcs/key_detect.c \
		./srcs/moove.c \
		./srcs/rotate.c \
		./srcs/utile.c \
		./srcs/utile2.c \
		./srcs/minimap.c \
		./srcs/get_next_line.c \
		./srcs/get_next_line_utils.c \

ifdef WITH_BONUS
	OBJ=$(BONUS_SRCS:.c=.o)
else
	OBJ=$(SRCS:.c=.o)
endif

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

bonus: 
		@make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus