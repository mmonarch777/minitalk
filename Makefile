CLIENT = client
SERVER = server

CLIENT_FILE = client.c
SERVER_FILE = server.c

OBJ_CLIENT = $(patsubst %.c,%.o,$(CLIENT_FILE))
OBJ_SERVER = $(patsubst %.c,%.o,$(SERVER_FILE))

HEADER = minitalk.h

FLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(HEADER) libmini
		make -C libmini
		gcc -o $(CLIENT) $(OBJ_CLIENT) -L libmini -lmini

$(SERVER): $(OBJ_SERVER) $(HEADER) libmini
		make -C libmini
		gcc -o $(SERVER) $(OBJ_SERVER) -L libmini -lmini

%.o: %.c
		gcc $(FLAGS) -c $< -o $@

clean:
		rm -f *.o
		make clean -C libmini

fclean: clean
		rm -f $(CLIENT) $(SERVER)
		make fclean -C libmini

re: fclean all

norm:
		make norm -C libmini
		norminette $(CLIENT_FILE) $(SERVER_FILE) $(HEADER)

.PHONY: all clean fclean re libft norm