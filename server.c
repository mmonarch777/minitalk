#include "minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);

}
