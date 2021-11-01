NAME = libmini.a

SRC = ft_putchar.c	ft_putnbr.c	ft_putstr.c	ft_putendl_fd.c	ft_atoi.c

OBJ = $(patsubst %.c,%.o,$(SRC))

FLAGS = -Wall -Wextra -Werror

HEADER = libmini.h

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

norm:
	norminette $(SRC) $(HEADER)

.PHONY : clean fclean re all norm