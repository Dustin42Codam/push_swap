/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_argv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 21:39:58 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/13 19:16:13 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dup(t_list *list, t_list *node, int nb)
{
	while (list && list != node)
	{
		if (list->content == nb)
			return (ERROR);
		list = list->next;
	}
	return (NO_ERROR);
}

static int	read_single_arg(char *arg, t_stack *stack)
{
	t_list	*node;
	size_t	i;
	long	nb;

	i = 0;
	while (arg[i])
	{
		while (ft_isspace(arg[i]))
			i++;
		nb = ft_atol(arg + i);
		if (nb == 0 && arg[i] != '0')
			return (ERROR);
		node = ft_lstnew((int)nb);
		if (node)
			ft_lstadd_front(&stack->a, node);
		if (!node || nb > INT_MAX || nb < INT_MIN || \
			check_dup(stack->a->next, node, nb))
			return (ERROR);
		i += ft_numlen(nb);
		while (ft_isspace(arg[i]))
			i++;
	}
	return (NO_ERROR);
}

static int	read_multiple_args(int ac, char *av[], t_stack *stack)
{
	t_list	*node;
	size_t	i;
	long	nb;

	while (ac > 1)
	{
		i = 0;
		ac--;
		if (ft_issign(av[ac][i]) && ft_isdigit(av[ac][i + 1]))
			i++;
		while (av[ac][i])
		{
			if (ft_isdigit(av[ac][i]) == 0)
				return (ERROR);
			i++;
		}
		nb = ft_atol(av[ac]);
		node = ft_lstnew((int)nb);
		if (node)
			ft_lstadd_back(&stack->a, node);
		if (!node || nb > INT_MAX || nb < INT_MIN || \
			check_dup(stack->a, node, nb))
			return (ERROR);
	}
	return (NO_ERROR);
}

int	read_argv(int ac, char *av[], t_stack *stack)
{
	if (stack == 0)
		return (ERROR);
	if (ac == 2)
		return (read_single_arg(av[1], stack));
	else if (ac > 2)
		return (read_multiple_args(ac, av, stack));
	return (0);
}
