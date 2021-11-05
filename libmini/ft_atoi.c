/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:19:45 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/04 14:58:29 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmini.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	num;

	i = 0;
	num = 0;
	nb = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'\
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb = nb * (-1);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * nb);
}
