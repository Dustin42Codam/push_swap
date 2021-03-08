/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 20:28:31 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/08 20:32:14 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

long	ft_atol(const char *str)
{
	int				i;
	unsigned long	nb;
	int				sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (sign == 1 && nb >= 9223372036854775807)
		return (-1);
	else if (sign == -1 && nb > 9223372036854775807)
		return (0);
	return (nb * sign);
}