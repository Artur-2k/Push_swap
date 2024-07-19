# Binary
BIN = push_swap

# Compiler
CC = gcc
#-Wall -Wextra -Werror
CFLAGS = -I$(INC_DIR) -I$(LIB_DIR)

# Directories
INC_DIR = inc/
LIB_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/

# Files
MAIN_FILE = $(SRC_DIR)push_swap.c
LIB = $(LIB_DIR)libft.a
SRC_FILES = argument_checker.c list_utils.c movements.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(BIN)

$(BIN): $(LIB) $(OBJ) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MAIN_FILE) $(OBJ) $(LIB) -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(BIN)

re: fclean all