CC = gcc 
FLAGS = -Wall -Wextra -Werror 
SRC = main.c \
	init_player.c \
	init_map.c \
	handleMoves.c \
	getTextureInfo.c \
	RaysCasting.c \
	3Dprojection.c \
	
MFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = cub3d

OBJ := ${SRC:.c=.o}

all: ${NAME}

%.o:%.c 
	$(CC) -c $(FLAGS) ${SRC}
	
${NAME}: ${OBJ}
	$(CC) $(MFLAGS) $(FLAGS) ${OBJ} -o ../${NAME} 
	
clean:
	rm -rf ${OBJ}
	
fclean:
	rm -rf ${NAME} ${OBJ}

re: fclean all