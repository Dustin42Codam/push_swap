/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_commands.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 18:54:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 18:58:31 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_charjoin(char *input, char const c)
{
	size_t	len;
	char	*str;

	if (!input)
		return (0);
	len = ft_strlen(input) + 1;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, input, len);
	str[len - 1] = c;
	free(input);
	return (str);
}

char	**read_commands(void)
{
	char	**token;
	char	*input;
	char	buf;
	int ret;

	ret = 1;
	input = ft_calloc(1, 1);
	if (!input)
		return (0);
	while (ret > 0)
	{
		ret = read(0, &buf, 1);
		if (ret == -1)
			return (0);
		input = ft_charjoin(input, buf);
		if (!input)
			return (0);
	}
	token = ft_split(input, '\n');
	free(input);
	if (!token)
		return (0);
	return (token);
}
