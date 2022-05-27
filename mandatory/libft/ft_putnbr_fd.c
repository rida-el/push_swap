/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:31:36 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/12 19:48:15 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_putnbr(int fd, int nb)
{
	int	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
	else
	{
		_ft_putnbr(fd, nb / 10);
		_ft_putnbr(fd, nb % 10);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	min;

	if (n < 0)
	{
		write(fd, "-", 1);
		min = 1 << (sizeof(int) * 8 - 1);
		if (min == n)
		{
			_ft_putnbr(fd, n / 10 * -1);
			_ft_putnbr(fd, n % 10 * -1);
			return ;
		}
		n = n * -1;
	}
	_ft_putnbr(fd, n);
}
