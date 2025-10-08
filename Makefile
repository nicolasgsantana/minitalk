GREEN  = \033[1;32m
YELLOW = \033[1;33m
RESET  = \033[0m

CLIENT = client
SERVER = server
SRC_DIR = src
INC_DIR = include

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/include
LIBS = $(LIBFT)

SRC_CLIENT = $(SRC_DIR)/client.c 
SRC_SERVER = $(SRC_DIR)/server.c
HEADER = $(INC_DIR)/minitalk.h

all: $(CLIENT) $(SERVER)

$(CLIENT): $(HEADER) $(SRC_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBS) -o $(CLIENT)
	@echo "$(GREEN)$(CLIENT) created$(RESET)"

$(SERVER): $(HEADER) $(SRC_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBS) -o $(SERVER)
	@echo "$(GREEN)$(SERVER) created$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -f $(CLIENT)
	@echo "$(YELLOW)$(CLIENT) deleted$(RESET)"
	@rm -f $(SERVER)
	@echo "$(YELLOW)$(SERVER) deleted$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re
