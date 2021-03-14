/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 20:57:21 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/14 02:48:32 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_all(t_stack *stack, char **cmds)
{
	t_list	*tmp;
	int		i = 0;
	printf("++++++++++ STACK A ++++++++++\n");
	if (ft_lstsize(stack->a))
	{
		tmp = stack->a;
		while (tmp)
		{
			printf("[%d] %d\n", i, tmp->content);
			i++;
			tmp = tmp->next;
		}
	}
	printf("++++++++++ STACK B ++++++++++\n");
	if (ft_lstsize(stack->b))
	{
		tmp = stack->b;
		while (tmp)
		{
			printf("[%d] %d\n", i, tmp->content);
			i++;
			tmp = tmp->next;
		}
	}
	printf("++++++++++++ END +++++++++++++\n");
	return ;
	i = 0;
	while (cmds[i])
	{
		printf("[%s]\n", cmds[i]);
		i++;
	}
}
