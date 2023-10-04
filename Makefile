SRCS = get_next_line.c get_next_line_utils.c
SRCS_B = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
GCC = gcc

# $ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

# ${NAME}: ${OBJS}
#	@ar rcs ${NAME} ${OBJS}

# ${NAME}: ${OBJS}
# 	${GCC} ${CFLAGS} -D BUFFER_SIZE=32 ${SRCS}

all:	${NAME}

clean:
	rm -f ${OBJS}
#	rm test

fclean: clean
	rm -f ${NAME}
	rm a.out
# rm output

re: fclean all

test:
#	${CC} -c ${SRCS} ${CFLAGS}
#	${CC} -o test ${OBJS}
	${GCC} -o output ${SRCS}

build:
	${GCC} ${CFLAGS} ${SRCS}

bonus:
	${GCC} ${CFLAGS} ${SRCS_B}


.PHONY: all clean fclean re