SRCS = get_next_line.c get_next_line_utils.c 

# NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
GCC = gcc

# $ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

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