/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:19:30 by mmonarch          #+#    #+#             */
/*   Updated: 2021/11/01 20:19:34 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
