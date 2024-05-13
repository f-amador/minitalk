
NAME1= client
NAME2 = server
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC2 = server.c
OBJ =
SRC_DIR = srcs
OBJ_DIR = objs

all : $(NAME2)

$(NAME2):
	$(CC) $(CFLAGS) -o $(NAME2) $(SRC2)

