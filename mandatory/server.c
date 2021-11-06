/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:23:01 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/05 17:56:28 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_get_symbol(int sig)
{
	static char	symbol = '\0';
	static int	counter = 0;

	if (sig == SIGUSR1)
		symbol |= 1 << counter;
	counter++;
	if (counter == 8)
	{
		ft_putchar(symbol);
		symbol = '\0';
		counter = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_get_symbol);
	signal(SIGUSR2, ft_get_symbol);
	while (1)
		usleep(150);
}
