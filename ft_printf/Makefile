NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_numprint.c
SRCS_BONUS = ft_printf_bonus.c ft_numprint.c ft_bonus.c dashHandler.c dotHandler.c zeroHandler.c hashHandler.c spaceHandler.c plusHandler.c utils.c

LIB = ../libft/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -C ../libft/
	@ar -crs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	@make --no-print-directory -C ../libft/
	@ar -crs $(NAME) $(OBJS_BONUS)

clean:
	@rm -f *.o
	@make --no-print-directory -C ../libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make --no-print-directory -C ../libft/ fclean

re:	fclean all

.PHONY: all clean fclean re
