#include "../include/minitalk.h"

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int 				pid;
	char				*str;

	if (argc != 3 || !argv[2])
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
//	sig.sa_handler = ft_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
//	ft_kill(pid, str);
	while (1)
		usleep(150);
}
