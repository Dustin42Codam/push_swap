/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_cmds.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 14:34:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/27 14:37:11 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

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

static int	free_cmd_list(char **s)
{
	free(s);
	return (1);
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
			return (free_cmd_list(list));
		i++;
	}
	free(list);
	return (0);
}
