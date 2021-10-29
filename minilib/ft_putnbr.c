#include "minilib.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	unsigned int	na;
	unsigned int	i;

	nb = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	na = n;
	while (na >= 10)
	{
		nb = nb * 10;
		na = na / 10;
	}
	while (nb != 0)
	{
		i = n / nb + 48;
		write(1, &i, 1);
		n = n % nb;
		nb = nb / 10;
	}
}
