/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmds.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 07:45:50 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 07:45:51 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmds.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 18:54:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 06:54:04 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "checker.h"
#include <stdlib.h>
#include <unistd.h>

int	count_cmds(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

/* static void	add_cmd_id(t_cmd **cmd, int cmd_id, int i)
{
	if (i == 0)
	
} */

int	validate_cmds(t_cmd *cmd)
{
	const char	*pool[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", \
							"rra", "rrb", "rrr", 0};
	int	i;
	int	j;

	i = 0;
	while (cmd->list[i])
	{
		j = 0;
		while (pool[j])
		{
			if (!ft_strncmp(cmd->list[i], pool[j], ft_strlen(cmd->list[i])))
			{
				cmd->id[i] = j;
				break ;
			}
			j++;
		}
		if (!pool[j])
			return (1);
		i++;
	}
	return (0);
}

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

char	**read_cmds(void)
{
	char	**cmds;
	char	*input;
	char	buf;
	int		ret;

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
	cmds = ft_split(input, '\n');
	free(input);
	if (!cmds)
		return (0);
	return (cmds);
}
