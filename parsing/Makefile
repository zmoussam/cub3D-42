CC = gcc 
FLAGS = -Wall -Werror -Wextra
CFILES = main.c check_colors.c check_extention.c check_map.c check_texture.c\
		collect_infos.c parsing.c utils.c get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c
OFILES = ${CFILES:.c=.o}
NAME = cub3d


all: $(OFILES) parsing.h
	$(MAKE) -C ../libft_zack
	mv ../libft_zack/libft.a .
	$(CC) $(FLAGS) $(OFILES) libft.a -o $(NAME)

# %.o:%.c
# 	$(CC) -c $(CFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	$(MAKE) fclean -C ../libft_zack
	rm -rf $(NAME)
	rm -rf libft.a
re: fclean
	all