#include "minitalk.h"

void	sent_symbol(char **str, int pid)
{
	int	count_bit;
	int digit;

	count_bit = 0;
	while (count_bit <= 7)
	{
		digit = ((**str) >> count_bit) & 1;
		if (digit == 1)
			digit = kill(pid, SIGUSR1);
		else if (digit == 0)
			digit = kill(pid, SIGUSR2);
		else
		{
			ft_putendl_fd("Error send", 2);
			exit (1);
		}
		count_bit++;
		usleep(150);
	}
	(*str)++;
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc != 3)
	{
		ft_putendl_fd("Don't right arguments. Need PID and \"string\"", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid < 0)
	{
		ft_putendl_fd("Error PID", 2);
		return (1);
	}
	while (*str)
		sent_symbol(&str, pid);
	ft_putchar('\n');
}
