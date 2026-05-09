NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = philo.c utils.c parse_args.c init.c threads.c monitor.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re