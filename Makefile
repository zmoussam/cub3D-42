# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 16:01:03 by zmoussam          #+#    #+#              #
#    Updated: 2023/02/06 16:12:51 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = main.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) 
	$(RM) $(OBJ)

%.o: %.c cub3d.h
	$(CC) -c $< -o $@

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: fclean clean all re