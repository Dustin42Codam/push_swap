/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_argv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 19:34:17 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/31 14:45:16 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	read_multiple_args(int ac, char *av[], t_stack *stack, int flags)
{
	t_list	*node;
	size_t	i;
	long	nb;

	while (ac > 1 + flags)
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

static int	read_flags(char *av[], t_flags **flags)
{
	size_t	i;

	i = 1;
	(*flags)->bitfield = 0;
	while (av[i])
	{
		if (ft_strncmp("-c", av[i], 3) == 0)
			(*flags)->bitfield |= COLORS;
		else if (ft_strncmp("-v", av[i], 3) == 0)
			(*flags)->bitfield |= DEBUG;
		else if (ft_strncmp("-f", av[i], 3) == 0)
			(*flags)->bitfield |= READ_FILE;
		else if (ft_strncmp("-s", av[i], 3) == 0)
			(*flags)->bitfield |= SLOMO;
		else
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	read_argv(int ac, char *av[], t_stack *stack, t_flags *flags)
{
	int	flag_count;

	if (stack == 0)
		return (ERROR);
	flag_count = read_flags(av, &flags);
	if (ac == 2 + flag_count)
	{
		// return (read_single_arg(av[1 + flag_count], stack));
		read_single_arg(av[1 + flag_count], stack);
		printf("%d\n", stack->a->content);
		return (0);
	}
	else
		return (read_multiple_args(ac, av, stack, flag_count));
}
