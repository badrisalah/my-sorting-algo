CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
BONUS_NAME = checker


SRCS = srcs/main.c srcs/utils.c srcs/parsing.c srcs/sorting_algo.c srcs/moves.c\
	srcs/sort.c srcs/moves2.c srcs/arr_ut.c srcs/moves3.c srcs/2ndmain.c srcs/libc.c srcs/libc2.c

SRCSB = srcsb/get_next_line.c srcsb/get_next_line_utils.c srcsb/checker_bonus.c\
	srcs/utils.c srcs/2ndmain.c\
	srcs/parsing.c srcs/sorting_algo.c srcs/moves.c\
	srcs/sort.c srcs/moves2.c srcs/arr_ut.c srcs/moves3.c srcs/libc.c srcs/libc2.c\
	srcsb/utils_bonus.c 

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}

all: ${NAME}

bonus: ${BONUS_NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

${BONUS_NAME}: ${OBJSB}
	${CC} ${CFLAGS} -o ${BONUS_NAME} ${OBJSB}

%.o: %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${OBJSB}

fclean: clean
	rm -f ${NAME} ${BONUS_NAME} ${LIBFT}

re: fclean all
