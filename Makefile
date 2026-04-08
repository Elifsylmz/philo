NAME = philo

CC = CC
CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C fclean

re: fclean all

.PHONY: all clean fclean re