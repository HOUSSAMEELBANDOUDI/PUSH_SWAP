NAME = push_swap
NAME_BONUS = checker

INC_DIR = inc/
SRC_DIR = srcs/

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)
RM = rm -rf

SRC = $(SRC_DIR)commands/push.c $(SRC_DIR)commands/rev_rotate.c \
      $(SRC_DIR)commands/rotate.c $(SRC_DIR)commands/swap.c \
      $(SRC_DIR)push_swap/from_b_to_a.c $(SRC_DIR)push_swap/sort_stack.c \
      $(SRC_DIR)push_swap/sort_three.c $(SRC_DIR)push_swap/sort_utils.c \
      $(SRC_DIR)push_swap/ft_split.c $(SRC_DIR)push_swap/add_stack.c \
      $(SRC_DIR)push_swap/free_error.c $(SRC_DIR)push_swap/push_swap.c \
      $(SRC_DIR)push_swap/stack_utils.c

SRC_BONUS = bonus/get_next_line_bonus.c \
            bonus/get_next_line_utils_bonus.c \
            bonus/checker_bonus.c \
            bonus/free_error_bonus.c \
            bonus/ft_is_sorted_bonus.c \
            bonus/ft_split_bonus.c \
            bonus/push_bonus.c \
            bonus/rev_rotate_bonus.c \
            bonus/rotate_bonus.c \
            bonus/swap_bonus.c \
            bonus/stack_utils_bonus.c \
            bonus/add_stack_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking objects into $@"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "Linking bonus objects into $@"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

srcs/%.o: srcs/%.c $(INC_DIR)push_swap.h
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(INC_DIR)checker_bonus.h
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo "Cleaning executables"
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
