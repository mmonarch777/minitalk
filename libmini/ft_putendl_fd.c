#include "libmini.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr(s);
	write(fd, "\n", 1);
}
