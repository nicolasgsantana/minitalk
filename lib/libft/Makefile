GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RESET  = \033[0m

NAME = libft.a
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
INCLUDES = -I$(INC_DIR)

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = $(wildcard $(INC_DIR)/*.h)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)Creating library $(NAME)...$(RESET)"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@echo "$(BLUE) Compiling: $(notdir $<)$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@echo "$(CYAN) Creating obj directory...$(RESET)"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(YELLOW) Removing obj directory...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW) Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re