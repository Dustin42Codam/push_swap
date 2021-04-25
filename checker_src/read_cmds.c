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

static char	**init_cmd_list(int *i)
{
	char	**s;

	s = (char **)ft_calloc(12, sizeof(char *));
	if (!s)
		return (0);
	s[0] = "sa";
	s[1] = "sb";
	s[2] = "ss";
	s[3] = "pa";
	s[4] = "pb";
	s[5] = "ra";
	s[6] = "rb";
	s[7] = "rr";
	s[8] = "rra";
	s[9] = "rrb";
	s[10] = "rrr";
	s[11] = 0;
	(*i) = 0;
	return (s);
}

int	validate_cmds(t_cmd *cmd)
{
	char	**list;
	int		i;
	int		j;

	list = init_cmd_list(&i);
	if (!list)
		return (1);
	while (cmd->list[i])
	{
		j = 0;
		while (list[j])
		{
			if (!ft_strncmp(cmd->list[i], list[j], ft_strlen(cmd->list[i])))
			{
				cmd->id[i] = j;
				break ;
			}
			j++;
		}
		if (!list[j])
			return (1);
		i++;
	}
	free(list);
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
	while (input && ret > 0)
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
