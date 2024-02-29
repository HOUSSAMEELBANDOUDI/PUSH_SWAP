# Standard
NAME        = push_swap
NAME_BONUS = checker

# Directories
INC         = inc/
SRC_DIR     = srcs/

# Compiler and CFlags
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -I$(INC)
RM          = rm -rf

# Source Files
SRC = $(SRC_DIR)commands/push.c $(SRC_DIR)commands/rev_rotate.c $(SRC_DIR)commands/rotate.c $(SRC_DIR)commands/swap.c \
      $(SRC_DIR)push_swap/from_b_to_a.c $(SRC_DIR)push_swap/sort_stack.c $(SRC_DIR)push_swap/sort_three.c $(SRC_DIR)push_swap/sort_utils.c \
      $(SRC_DIR)push_swap/ft_split.c $(SRC_DIR)push_swap/add_stack.c $(SRC_DIR)push_swap/free_error.c \
      $(SRC_DIR)push_swap/push_swap.c $(SRC_DIR)push_swap/stack_utils.c \

SRC_BONUS = $(SRC_DIR)checker/get_next_line.c $(SRC_DIR)checker/get_next_line_utils.c $(SRC_DIR)checker/checker.c \
			$(SRC_DIR)push_swap/ft_split.c $(SRC_DIR)push_swap/add_stack.c $(SRC_DIR)push_swap/sort_three.c \

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ) -o $(NAME_BONUS)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
