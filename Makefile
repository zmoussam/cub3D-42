# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 02:08:20 by mmakboub          #+#    #+#              #
#    Updated: 2023/03/03 23:16:43 by mmakboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
BONUS_NAME = cub3d_bonus
LIBF = libft/libft.a
SRC = ./mandatory/3Dprojection/3Dprojection.c ./mandatory/getTextureInfo.c \
	  ./mandatory/Moves/handleMoves.c ./mandatory/3Dprojection/draw.c\
	  ./mandatory/Moves/keyPress.c\
	  ./mandatory/initPlayer.c ./mandatory/main.c ./mandatory/RayCasting/Utils.c \
	  ./mandatory/RayCasting/RaysCasting.c ./mandatory/RayCasting/findIntersection.c\
	  ./mandatory/parsing/ft_strcpy.c ./mandatory/parsing/initializer.c \
	  ./mandatory/parsing/mainparsing.c ./mandatory/parsing/mainparsing2.c  \
	  ./mandatory/parsing/parse_color.c ./mandatory/parsing/parse_direction.c\
	  ./mandatory/parsing/parse_map.c ./mandatory/parsing/parser_utils.c\
	  ./mandatory/parsing/parser_utis2.c  ./mandatory/parsing/validposition.c \
	  ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

BNS_SRC = ./bonus/3Dprojection/3Dprojection.c ./bonus/getTextureInfo.c \
	  	  ./bonus/Moves/handleMoves.c ./bonus/miniMap/MiniMap.c ./bonus/3Dprojection/draw.c\
	      ./bonus/initPlayer.c ./bonus/main.c ./bonus/RayCasting/RaysCasting.c\
		  ./bonus/bonusTexture/putTexture.c ./bonus/Moves/keyPress.c ./bonus/miniMap/miniPlayer.c\
		  ./bonus/RayCasting/findIntersection.c ./bonus/RayCasting/Utils.c\
	      ./bonus/parsing/ft_strcpy.c ./bonus/parsing/initializer.c \
	      ./bonus/parsing/mainparsing.c ./bonus/parsing/mainparsing2.c  \
	      ./bonus/parsing/parse_color.c ./bonus/parsing/parse_direction.c\
	      ./bonus/parsing/parse_map.c ./bonus/parsing/parser_utils.c\
		  ./bonus/handleMouse/mouse.c ./bonus/freeData.c\
	      ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c\
	      ./bonus/parsing/parser_utis2.c  ./bonus/parsing/validposition.c \
		  
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit 
INCLUDE = ./mandatory/include/cub3d.h ./mandatory/include/parsing.h ./get_next_line/get_next_line.h ./libft/libft.h
BNS_INCLUDE = ./bonus/include/cub3d.h ./bonus/include/parsing.h ./get_next_line/get_next_line.h ./libft/libft.h

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