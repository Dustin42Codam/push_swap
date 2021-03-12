/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_arguments.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 19:34:17 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 21:02:24 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_dup(t_list *list, int nb)
{
	while (list && list->next)
	{
		if (list->content == nb)
			return (1);
		list = list->next;
	}
	return (0);
}

int	read_arguments(int argc, char *argv[], t_stack *stack)
{
	t_list	*node;
	long	nb;
	int		i;

	while (argc > 1)
	{
		i = 0;
		argc--;
		if ((argv[argc][i] == '-' || argv[argc][i] == '+') \
			 && ft_isdigit(argv[argc][i + 1]))
			i++;
		while (argv[argc][i])
		{
			if (ft_isdigit(argv[argc][i]) == 0)
				return (1);
			i++;
		}
		nb = ft_atol(argv[argc]);
		node = ft_lstnew((int)nb);
		if (node)
			ft_lstadd_back(&stack->a, node);
		if (!node || nb > INT_MAX || nb < INT_MIN || check_dup(stack->a, nb))
			return (1);
	}
	return (0);
}
