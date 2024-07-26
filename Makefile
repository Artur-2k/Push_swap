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
SRC_FILES = argument_checker.c error_managment.c free_resources.c \
			 list_utils1.c list_utils2.c movements1.c  movements2.c \
			 movements3.c 
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(BIN)

$(BIN): $(LIB) $(MAIN_FILE) $(OBJ) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MAIN_FILE) $(OBJ) $(LIB) -o $@ -g

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -g

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(BIN)

re: fclean all