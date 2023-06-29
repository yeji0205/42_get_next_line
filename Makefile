SRCS = ft_printf.c ft_num_base.c ft_strlen.c ft_word.c \

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all:	${NAME}


clean:
	rm -f ${OBJS}
#	rm test

fclean: clean
	rm -f ${NAME}

re: fclean all

# test:
# 	${CC} -c ${SRCS} ${CFLAGS}
# 	${CC} -o test ${OBJS}

.PHONY: all clean fclean re