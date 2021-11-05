#include "../include/minitalk.h"

int	main(void)
{
		struct sigaction	sig;
	int	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
//	sig.sa_sig = ft_sig
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		usleep(150);
}

