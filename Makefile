# EXECUTABLE
TARGET = push_swap

# LIBRARIES
LIBFT = libft.a

# DIRECTORIES
SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/
INC_DIR = inc/

# COMPILE STUFF
CC = gcc
CFLAGS = -I$(INC_DIR) -Ilib/libft
# -Wall -Werror -Wextra
LINKS = $(LIB_DIR)/$(LIBFT)

# FILES
SRC_FILES = list_utils.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
MAIN_FILE = $(addprefix $(SRC_DIR), push_swap.c)

# RULES
all: $(TARGET)

$(TARGET): $(LIBFT) $(OBJ)
	@echo "Preparing the executable..."
	@$(CC) $(CFLAGS) -o $@ $(MAIN_FILE) $(OBJ) $(LINKS)
	@echo -e "\nPush_swap is ready.\nUsage: ./push_swap <(int)args>"

$(LIBFT):
	@echo "Creating libft.a..."
	@make --silent -C $(LIB_DIR)/libft
	@make --silent clean -C $(LIB_DIR)/libft
	@mv $(LIB_DIR)libft/libft.a $(LIB_DIR)

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