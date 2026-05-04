NAME = miniRT
NAME_BONUS = miniRT_bonus

CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -Iinclude

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
BUILD_DIR = build
BUILD_DIR_BONUS = build_bonus

SRCS_COMMON = $(shell find $(SRC_DIR)/matrix $(SRC_DIR)/minilibx $(SRC_DIR)/math \
	$(SRC_DIR)/transformations $(SRC_DIR)/bvh $(SRC_DIR)/texture $(SRC_DIR)/aTrier \
	$(SRC_DIR)/intersections $(SRC_DIR)/errors $(SRC_DIR)/parser $(SRC_DIR)/struct_rt -type f -name "*.c" ! -name "*_bonus.c")

MAIN = src/main.c
MAIN_BONUS = src_bonus/main.c
UTILS = src/debug_utils.c

SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

SRCS_BONUS = $(shell find $(SRC_BONUS_DIR) -type f -name "*.c")
OBJS_BONUS = $(SRCS_BONUS:%.c=$(BUILD_DIR_BONUS)/%.o)

LIBS = minilibx-linux/libmlx_Linux.a \
       ft_printf/libftprintf.a \
       libft/libft.a \
       gnl/gnl.a

INCLUDES = -Iminilibx-linux -Ignl -Ilibft -Ift_printf -Iinclude

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -C libft/
	@make --no-print-directory -C gnl/
	@make --no-print-directory -C ft_printf/
	@make --no-print-directory -C minilibx-linux/
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -Lminilibx-linux -lX11 -lXext -lm -o $(NAME)
	@echo "🧑‍💻 mandatory (mandatory) : $(NAME)"

bonus: $(OBJS_BONUS)
	@make --no-print-directory -C libft/
	@make --no-print-directory -C gnl/
	@make --no-print-directory -C ft_printf/
	@make --no-print-directory -C minilibx-linux/
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIBS) -Lminilibx-linux -lX11 -lXext -lm -o $(NAME_BONUS)
	@echo "🧑🥹 bonus omg (bonus) : $(NAME_BONUS)"


$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BUILD_DIR_BONUS)
	@make --no-print-directory -C libft/ clean
	@make --no-print-directory -C gnl/ clean
	@make --no-print-directory -C ft_printf/ clean
	@make --no-print-directory -C minilibx-linux/ clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make --no-print-directory -C libft/ fclean
	@make --no-print-directory -C gnl/ fclean
	@make --no-print-directory -C ft_printf/ fclean

re: fclean all

.PHONY: all bonus clean fclean re
