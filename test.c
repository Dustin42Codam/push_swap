/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 07:10:02 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdio.h>

void	print_a(void)
{
	printf("a\n");
}

void	print_b(void)
{
	printf("b\n");
}

void	print_c(void)
{
	printf("c\n");
}

t_jump	init_table(void)
{
	t_jump	table;

	table.function[0] = print_a;
	table.function[1] = print_b;
	table.function[2] = print_c;
	return (table);
}

static void	init_cmd(t_cmd *cmd)
{
	cmd->id = 0;
	cmd->count = 0;
}

int	main(void)
{
	int	len = 3;
	int	*arr = ft_calloc(len + 1, sizeof(int));

	arr[len] = -1;


	int i = 0;
	while (arr[i])
	{
		printf("%d\n", arr[i]);
		i++;
	}


	// printf("%s\n", cmd.pool[1]);
	// table = init_table();
	// table.function[2]();
	return (0);
}
