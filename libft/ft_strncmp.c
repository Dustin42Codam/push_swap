/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 13:33:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/27 16:14:05 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			dif;
	unsigned char	*c1;
	unsigned char	*c2;

	dif = ft_strlen(s1) - ft_strlen(s2);
	if (dif)
		return (1);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n && c1[i] == c2[i] && c1[i] && c2[i])
		i++;
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}
