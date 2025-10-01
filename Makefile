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

SRC_CLIENT_BONUS = $(SRC_DIR)/client_bonus.c
SRC_SERVER_BONUS = $(SRC_DIR)/server_bonus.c

all: $(CLIENT) $(SERVER)

$(CLIENT): $(HEADER) $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT) $(LIBS) -o $(CLIENT)

$(SERVER): $(HEADER) $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER) $(LIBS) -o $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

_bonus_client:: $(HEADER) $(SRC_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_CLIENT_BONUS) $(LIBS) -o $(CLIENT)

_bonus_server:: $(HEADER) $(SRC_SERVER_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_SERVER_BONUS) $(LIBS) -o $(SERVER)

bonus: $(LIBFT) $(CLIENT) $(SERVER) _bonus_server _bonus_client
	

.PHONY: all clean fclean re bonus
