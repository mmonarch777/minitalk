CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CLIENT_FILE = mandatory/client.c
SERVER_FILE = mandatory/server.c
CLIENT_BONUS_FILE = bonus/client_bonus.c
SERVER_BONUS_FILE = bonus/server_bonus.c

OBJ_CLIENT = $(patsubst %.c,%.o,$(CLIENT_FILE))
OBJ_CLIENT_BONUS = $(patsubst %.c,%.o,$(CLIENT_BONUS_FILE))
OBJ_SERVER = $(patsubst %.c,%.o,$(SERVER_FILE))
OBJ_SERVER_BONUS = $(patsubst %.c,%.o,$(SERVER_BONUS_FILE))

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
		@echo $(FONT_COLOR_GREEN)[server executable create]$(FONT_COLOR_DEFAULT)

%.o: %.c
		@gcc $(FLAGS) -c $< -o $@

bonus: $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(HEADER) $(LIBMINI_DIR)
		@make -C $(LIBMINI_DIR)
		@gcc $(OBJ_SERVER_BONUS) -L$(LIBMINI_DIR) -lmini -o $(SERVER_BONUS)
		@gcc $(OBJ_CLIENT_BONUS) -L$(LIBMINI_DIR) -lmini -o $(CLIENT_BONUS)
		@echo $(FONT_COLOR_GREEN)[client_bonus executable create]$(FONT_COLOR_DEFAULT)
		@echo $(FONT_COLOR_GREEN)[server_bonus executable create]$(FONT_COLOR_DEFAULT)

clean:
		@rm -f $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
		@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
		@make clean -C $(LIBMINI_DIR)

fclean: clean
		@rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
		@rm -f $(CLIENT) $(SERVER)
		@make fclean -C $(LIBMINI_DIR)

re: fclean all

norm:
		@make norm -C $(LIBMINI_DIR)
		@norminette $(CLIENT_FILE) $(SERVER_FILE) $(HEADER) $(SERVER_BONUS_FILE) $(CLIENT_BONUS_FILE)

.PHONY: all clean fclean re libft norm bonus