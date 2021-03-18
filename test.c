/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/18 07:06:08 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_flags	flags;

	flags.bitfield = 0;
	// printf("%d\n", flags.bitfield);
	// flags.bitfield |= COLORS;
	// printf("%d\n", flags.bitfield);
	flags.bitfield |= DEBUG;
	// printf("%d\n", flags.bitfield);
	// flags.bitfield |= FILE;
	// printf("%d\n", flags.bitfield);
	flags.bitfield |= SLOMO;
	// printf("%d\n", flags.bitfield);

	//	16  8  4  2  1
	//	 0  0  0  1  0
	//	 0  1  0  1  0

	printf("%d\n", argc);

	return (0);
}
