/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:57:49 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/06 13:57:53 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_send_str(int pid, char *str)
{
	int		bit;
	char	symbol;

	while (*str)
	{
		bit = -1;
		symbol = *str++;
		while (++bit < 8)
		{
			if ((symbol >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
		}
		usleep(150);
	}
}

void	ft_send_finish(int pid)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		kill(pid, SIGUSR2);
		usleep(150);
	}
}

static void	ft_handler(int signal)
{
	static int	counter = 0;

	if (signal == SIGUSR1)
		counter++;
	else
	{
		ft_putstr("Сharacters received: ");
		ft_putnbr(counter);
		ft_putchar('\n');
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid;
	char				*str;

	if (argc != 3 || !argv[2])
	{
		ft_putendl_fd("Don't right arguments. Need PID and \"string\"", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	ft_putstr("Сharacters sent: ");
	ft_putnbr(ft_strlen(str) + 1);
	ft_putchar('\n');
	sig.sa_handler = ft_handler;
	sig.sa_flags = 0;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_send_str(pid, str);
	ft_send_str(pid, "\n");
	ft_send_finish(pid);
	while (1)
		usleep(150);
}
