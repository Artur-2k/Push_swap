# EXECUTABLE
TARGET = push_swap

# LIBRARIES
LIBFT = libft.a

# DIRECTORIES
SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = libft/
INC_DIR = inc/

# COMPILE STUFF
CC = gcc
CFLAGS = -I$(INC_DIR) -Ilibft/
# -Wall -Werror -Wextra
LINKS = $(LIB_DIR)/$(LIBFT)

# FILES
SRC_FILES = list_utils.c argument_checker.c movements.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
MAIN_FILE = $(addprefix $(SRC_DIR), push_swap.c)

# RULES
all: $(TARGET)

$(TARGET): $(LIBFT) $(OBJ)
	@echo "Preparing the executable..."
	@$(CC) $(CFLAGS) -o $@ $(MAIN_FILE) $(OBJ) $(LINKS)
	@echo "\nPush_swap is ready.\nUsage: ./push_swap int1 int2 int3 ..."

$(LIBFT):
	@echo "Creating libft.a..."
	@make --silent -C $(LIB_DIR)
	@make --silent clean -C $(LIB_DIR)

build:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | build
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning!"
	@rm -rf $(OBJ_DIR) $(LIBFT)

fclean:
	@echo "Full cleaning!"
	@rm -rf $(OBJ_DIR) $(TARGET) $(LIB_DIR)$(LIBFT)

re: fclean all

.PHONY: all clean fclean re