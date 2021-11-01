#ifndef LIBMINI_H
# define LIBMINI_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char symbol);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
#endif
