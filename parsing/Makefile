CC = gcc 
FLAGS = -Wall -Werror -Wextra
CFILES = main.c
OFILES = ${CFILES:.c=.o}
NAME = cub3d


all: $(OFILES) parsing.h
	$(MAKE) -C ../libft_zack
	mv ../libft_zack/libft.a .
	$(CC) $(FLAGS) $(OFILES) libft.a -o $(NAME)

%.o:%.c
	$(CC) -c $(CFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	$(MAKE) fclean -C ../libft_zack
	rm -rf $(NAME)
re: fclean
	all