CC = cc
FLAGS =  -Wall -Werror -Wextra
CFILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_strcmp.c\
			    ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_striteri.c ft_strtrim.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
				ft_lstclear.c ft_lstiter.c
OFILES = ${CFILES:.c=.o}
NAME = libft.a

INC = libft.h

all : ${NAME}

${NAME} : ${OFILES}
	@ar -rc ${NAME} ${OFILES}

%.o:%.c ${INC}
	@${CC} -c ${FLAGS} $<
clean :
	@rm -f ${OFILES} ${BONUSO}

fclean : clean
	@rm -f ${NAME}

re : fclean all
