# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 14:52:34 by toroman           #+#    #+#              #
#    Updated: 2025/12/13 19:31:48 by ehattab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = parsing/utils.c parsing/main.c parsing/utils1.c parsing/utils2.c parsing/utils3.c\
raycasting/game.c raycasting/player.c raycasting/utils.c raycasting/texture.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = ./utils/minilibx-linux
UTILS_DIR = ./utils

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(UTILS_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(UTILS_DIR)/utils.a $(MLX_DIR)/libmlx.a -lXext -lX11 -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(UTILS_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(UTILS_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(UTILS_DIR)/utils.a

re: fclean all

.PHONY: all clean fclean re
