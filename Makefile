CLIENT = client
SERVER = server

CLIENT_FILE = client.c
SERVER_FILE = server.c

OBJ_CLIENT = $(patsubst %.c,%.o,$(CLIENT_FILE))
OBJ_SERVER = $(patsubst %.c,%.o,$(SERVER_FILE))

HEADER = minitalk.h

FLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(HEADER)
		make -C minilib
#		gcc -L minilib -lft -o $(OBJ_CLIENT) $(CLIENT)
		gcc -o $(CLIENT) $(OBJ_CLIENT) -L minilib -lft

$(SERVER): $(OBJ_SERVER) $(HEADER)
		make -C minilib
		gcc -L minilib -lft $(OBJ_SERVER) -o $(SERVER)

%.o: %.c
		gcc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ_CLIENT)
		rm -f $(OBJ_SERVER)
		make clean -C minilib

fclean: clean
		rm -f $(OBJ_CLIENT)
		rm -f $(OBJ_SERVER)
		make fclean -C minilib

re: fclean all

.PHONY: all clean fclean re libft