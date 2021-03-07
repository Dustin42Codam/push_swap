/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 19:05:05 by dkrecisz      #+#    #+#                 */
/*   Updated: 2020/09/08 20:26:47 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*sptr;
	char		char_c;
	size_t		len;

	char_c = (char)c;
	sptr = s;
	len = ft_strlen(s);
	s = s + len;
	while (*s != char_c && s > sptr)
		s--;
	if (*s != char_c && s == sptr)
		return (NULL);
	return ((char *)s);
}
