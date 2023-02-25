# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 12:25:03 by zmoussam          #+#    #+#              #
#    Updated: 2023/02/24 21:40:45 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
FLAGS = -Wall -Wextra -Werror 
SRC = main.c handleMoves.c 3Dprojection.c CollectData.c MiniMap.c RayCasting.c
MFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

OBJ := ${SRC:.c=.o}

all: ${NAME}

%.o:%.c cub3d.h
	$(CC) -c $(FLAGS) ${SRC}
	
${NAME}: ${OBJ}
	$(CC) $(MFLAGS) ${OBJ} -o ${NAME} 
	
clean:
	rm -rf ${OBJ}
	
fclean:
	rm -rf ${NAME} ${OBJ}

re: fclean all

	