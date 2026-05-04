NAME = gnl.a

CC = cc

FLAGS = -Wall -Wextra -Werror #-D BUFFER_SIZE=n

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar -crs $(NAME) $(OBJS)
	@make --no-print-directory clean

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
