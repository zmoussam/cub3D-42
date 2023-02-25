# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 12:25:03 by zmoussam          #+#    #+#              #
#    Updated: 2023/02/26 00:50:45 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
FLAGS = -Wall -Wextra -Werror 
SRC = main.c MiniMap.c init_player.c init_map.c handleMoves.c getTextureInfo.c RaysCasting.c 3Dprojection.c
MFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

OBJ := ${SRC:.c=.o}

all: ${NAME}

%.o:%.c ./include/cub3d.h
	$(CC) -c $(FLAGS) ${SRC}
	
${NAME}: ${OBJ}
	$(CC) $(MFLAGS) ${OBJ} -o ${NAME} 
	
clean:
	rm -rf ${OBJ}
	
fclean:
	rm -rf ${NAME} ${OBJ}

re: fclean all

	