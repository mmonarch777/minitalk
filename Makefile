CLIENT = client
SERVER = server

CLIENT_FILE = mandatory/client.c
SERVER_FILE = mandatory/server.c

OBJ_CLIENT = $(patsubst %.c,%.o,$(CLIENT_FILE))
OBJ_SERVER = $(patsubst %.c,%.o,$(SERVER_FILE))

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_DEFAULT = '\033[0m'

HEADER = include/minitalk.h

FLAGS = -Wall -Wextra -Werror

LIBMINI_DIR = libmini/

all: $(CLIENT)  $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(HEADER) $(LIBMINI_DIR)
		@make -C $(LIBMINI_DIR)
		@gcc $(OBJ_CLIENT) -L$(LIBMINI_DIR) -lmini -o $(CLIENT)
		@echo $(FONT_COLOR_GREEN)[client executable create]$(FONT_COLOR_DEFAULT)

$(SERVER): $(OBJ_SERVER) $(HEADER) $(LIBMINI_DIR)
		@make -C $(LIBMINI_DIR)
		@gcc $(OBJ_SERVER) -L$(LIBMINI_DIR) -lmini -o $(SERVER)
		@echo $(FONT_COLOR_GREEN)[server executable create]

%.o: %.c
		@gcc $(FLAGS) -c $< -o $@

clean:
		@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
		@make clean -C $(LIBMINI_DIR)

fclean: clean
		@rm -f $(CLIENT) $(SERVER)
		@make fclean -C $(LIBMINI_DIR)

re: fclean all

norm:
		make norm -C $(LIBMINI_DIR)
		norminette $(CLIENT_FILE) $(SERVER_FILE) $(HEADER)

.PHONY: all clean fclean re libft norm