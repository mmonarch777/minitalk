/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:58:07 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/06 13:58:11 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_sigaction(int signal, siginfo_t *act, void *oldact)
{
	static char		symbol = 0;
	static int		bit = 0;
	static pid_t	pid;

	(void)oldact;
	if (!pid)
		pid = act->si_pid;
	if (signal == SIGUSR1)
		symbol |= 1 << bit;
	if (++bit == 8)
	{
		bit = 0;
		if (!symbol)
		{
			kill(pid, SIGUSR2);
			pid = 0;
			return ;
		}
		ft_putchar(symbol);
		kill(pid, SIGUSR1);
		symbol = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sigaction;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		usleep(150);
}
