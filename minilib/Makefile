NAME = minilib.a

SRC = ft_putchar.c	ft_putnbr.c	ft_putstr.c

OBJ = $(patsubst %.c,%.o,$(SRC))

FLAGS = -Wall -Wextra -Werror

HEADER = minilib.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o: %.c
	gcc $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re all