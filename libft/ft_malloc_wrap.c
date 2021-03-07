/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_wrap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 18:46:05 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/04 14:31:35 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_malloc_wrap(void *dest, size_t len)
{
	dest = malloc(len);
	return (dest);
}
