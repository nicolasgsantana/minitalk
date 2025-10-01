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

.PHONY: all clean fclean re
