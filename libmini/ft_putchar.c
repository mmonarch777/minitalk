#include "libmini.h"

void	ft_putchar(char symbol)
{
	write(1, &symbol, 1);
}
