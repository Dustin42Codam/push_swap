/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 20:13:34 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/15 03:03:26 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return ((char *)ft_memchr((const void *)s, c, ft_strlen(s) + 1));
}
