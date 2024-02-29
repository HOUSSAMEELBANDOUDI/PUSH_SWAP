
# Standard
NAME				= push_swap

# Directories
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS 				= -Wall -Werror -Wextra -I
RM					= rm -rf

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/from_b_to_a.c \
						$(SRC_DIR)push_swap/sort_stack.c \
						$(SRC_DIR)push_swap/sort_three.c \
						$(SRC_DIR)push_swap/sort_utils.c \
						$(SRC_DIR)push_swap/ft_split.c \
						$(SRC_DIR)push_swap/add_stack.c \
						$(SRC_DIR)push_swap/free_error.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/stack_utils.c \

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules

all: 				$(NAME)

$(NAME): 			$(OBJ)
					@$(CC) $(CFLAGS) $(INC) $(OBJ)  -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) $(OBJ_DIR)

fclean: 			clean
					@$(RM) $(NAME)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re