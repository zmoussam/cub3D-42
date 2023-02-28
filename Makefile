CC := cc
CFLAGS :=  -Wall -Wextra -Werror
MLXFLAGS := -lmlx -framework OpenGL -framework AppKit
NAME := cub3d
SRC = ./parsing/

OBJ := $(SRC:.c=.o)

.PHONY: all re clean fclean bonus

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ)

fclean:
	$(MAKE) -C libft fclean
	rm -f libft.a
	rm -rf $(NAME) $(OBJ) $(DEP)

re: fclean all

libft.a:
	$(MAKE) -C libft
	mv libft/libft.a .

$(NAME): libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libft.a $(MLXFLAGS)