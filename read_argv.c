/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_argv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 19:34:17 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/17 23:35:11 by dkrecisz      ########   odam.nl         */
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

static int	read_single_arg(char *arg, t_stack *stack)
{
	t_list	*node;
	long	nb;
	int		i;

	i = 0;
	while (arg[i])
	{
		while (ft_isspace(arg[i]))
			i++;
		nb = ft_atol(arg + i);
		if (nb == 0 && arg[i] != '0')
			return (1);
		node = ft_lstnew((int)nb);
		if (node)
			ft_lstadd_back(&stack->a, node);
		if (!node || nb > INT_MAX || nb < INT_MIN || check_dup(stack->a, nb))
			return (1);
		i += ft_numlen(nb);
		while (ft_isspace(arg[i]))
			i++;
	}
	return (0);
}

static int	read_multiple_args(int ac, char *av[], t_stack *stack)
{
	t_list	*node;
	long	nb;
	int		i;

	while (ac > 1)
	{
		i = 0;
		ac--;
		if (ft_issign(av[ac][i]) && ft_isdigit(av[ac][i + 1]))
			i++;
		while (av[ac][i])
		{
			if (ft_isdigit(av[ac][i]) == 0)
				return (1);
			i++;
		}
		nb = ft_atol(av[ac]);
		node = ft_lstnew((int)nb);
		if (node)
			ft_lstadd_back(&stack->a, node);
		if (!node || nb > INT_MAX || nb < INT_MIN || check_dup(stack->a, nb))
			return (1);
	}
	return (0);
}

int	read_argv(int ac, char *av[], t_stack *stack)
{
	if (ac == 2)
		return (read_single_arg(av[1], stack));
	else
		return (read_multiple_args(ac, av, stack));
}