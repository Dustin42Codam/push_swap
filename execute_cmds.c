/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cmds.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 02:27:31 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 07:45:11 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_table(t_jump *jump)
{
	jump->table[0] = swap_a;
	jump->table[1] = swap_b;
	jump->table[2] = swap_a_b;
/* 	jump->table[3] = push_a;
	jump->table[4] = push_b;
	jump->table[5] = push_a_b;
	jump->table[6] = rotate_a;
	jump->table[7] = rotate_b;
	jump->table[8] = rotate_a_b;
	jump->table[9] = rev_rot_a;
	jump->table[10] = rev_rot_b;
	jump->table[11] = rev_rot_a_b; */
}

void	execute_cmds(t_stack *stack, t_cmd cmd)
{
	t_jump	jump;
	int	i;

	i = 0;
	init_table(&jump);
	while (i < cmd.count)
	{
		jump.table[cmd.id[i]]();
		i++;
	}
}
