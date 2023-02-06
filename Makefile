# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 16:01:03 by zmoussam          #+#    #+#              #
#    Updated: 2023/02/06 16:01:12 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = cub3d.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework Appkit
RM = rm -f
LIBFT = libft/libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(MLX) $(OBJ) $(LIBFT)
	$(RM) $(OBJ)

%.o: %.c cub3d.h
	$(CC) -c $< -o $@

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: fclean clean all re