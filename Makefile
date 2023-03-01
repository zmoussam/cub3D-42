# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 02:08:20 by mmakboub          #+#    #+#              #
#    Updated: 2023/03/01 05:25:41 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
BONUS_NAME = cub3d_bonus
LIBF = libft/libft.a
SRC = ./mandatory/3Dprojection.c ./mandatory/getTextureInfo.c \
	  ./mandatory/handleMoves.c ./mandatory/init_map.c \
	  ./mandatory/init_player.c ./mandatory/main.c ./mandatory/RaysCasting.c \
	  ./mandatory/parsing/ft_strcpy.c ./mandatory/parsing/initializer.c \
	  ./mandatory/parsing/mainparsing.c ./mandatory/parsing/mainparsing2.c  \
	  ./mandatory/parsing/parse_color.c ./mandatory/parsing/parse_direction.c\
	  ./mandatory/parsing/parse_map.c ./mandatory/parsing/parser_utils.c\
	  ./mandatory/parsing/parser_utis2.c  ./mandatory/parsing/validposition.c \
	  ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

BNS_SRC = ./bonus/3Dprojection.c ./bonus/getTextureInfo.c \
	  	  ./bonus/handleMoves.c ./bonus/init_map.c ./bonus/MiniMap.c\
	      ./bonus/init_player.c ./bonus/main.c ./bonus/RaysCasting.c \
	      ./bonus/parsing/ft_strcpy.c ./bonus/parsing/initializer.c \
	      ./bonus/parsing/mainparsing.c ./bonus/parsing/mainparsing2.c  \
	      ./bonus/parsing/parse_color.c ./bonus/parsing/parse_direction.c\
	      ./bonus/parsing/parse_map.c ./bonus/parsing/parser_utils.c\
	      ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c\
	      ./bonus/parsing/parser_utis2.c  ./bonus/parsing/validposition.c \
		  
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDE = ./mandatory/include/cub3d.h ./mandatory/include/parsing.h ./get_next_line/get_next_line.h
BNS_INCLUDE = ./bonus/include/cub3d.h ./bonus/include/parsing.h ./get_next_line/get_next_line.h

OBJS = $(SRC:.c=.o)
OBJB = ${BNS_SRC:.c=.o}

all : $(LIBF) $(NAME)
		
	
$(LIBF):
	make -C libft

$(NAME) :$(OBJS) $(LIBF) $(INCLUDE)
	$(CC) $(MLX_FLAGS) $(OBJS) -o $(NAME)  -Llibft -lft 

bonus: $(LIBF) $(BONUS_NAME) 

$(BONUS_NAME) : $(OBJB) $(LIBF) $(BNS_INCLUDE)
	$(CC) $(MLX_FLAGS) $(OBJB) -o $(BONUS_NAME)  -Llibft -lft

clean:
	$(RM) $(OBJS) $(OBJB)
	 make clean -C libft 

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME) $(LIBF)
re: fclean all