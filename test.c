/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 05:04:38 by dkrecisz      ########   odam.nl         */
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

int	main(void)
{
	t_jump	table;

	table = init_table();
	table.function[2]();
	return (0);
}
