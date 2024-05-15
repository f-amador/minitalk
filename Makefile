CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC_DIR = srcs
OBJ_DIR = objs
SRC1 = $(SRC_DIR)/server.c
SRC2 = $(SRC_DIR)/client.c
OBJ1 = $(OBJ_DIR)/server.o
OBJ2 = $(OBJ_DIR)/client.o

all : $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ2)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ2)

$(SERVER): $(OBJ1)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ1)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
