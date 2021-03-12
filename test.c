/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 22:50:31 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdio.h>

static int	validate_cmds(char **cmds)
{
	const char	*valid_cmds[] = {"sa", "sb", "ss", "pa", \
								"pb", "ra", "rb", "rr", \
								"rra", "rrb", "rrr", 0};
	int			i;
	int			j;

	i = 0;
	while (cmds[i])
	{
		j = 0;
		while (valid_cmds[j])
		{
			if (ft_strncmp(cmds[i], valid_cmds[j], ft_strlen(cmds[i])) == 0)
				break ;
			j++;
		}
		if (!valid_cmds[j])
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{

	return (0);
}
