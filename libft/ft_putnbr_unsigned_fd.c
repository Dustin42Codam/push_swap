/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_unsigned_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:39:43 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/15 03:03:26 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char			c;
	long long		nb;

	nb = (long long)n;
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	if (nb < 10)
	{
		c = nb + '0';
		ft_putchar_fd(c, fd);
		return ;
	}
	if (nb)
	{
		ft_putnbr_fd(nb / 10, fd);
		c = nb % 10 + '0';
		write(fd, &c, 1);
		return ;
	}
}
