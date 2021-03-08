/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/08 20:46:59 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/include/libft.h"
#include "checker.h"
#include <limits.h>

int	main(int argc, char *argv[])
{

	// printf("%ld\n", ft_atol(argv[1]));
	// printf("%d\n", ft_atoi(argv[1]));
	// printf("%d\n", atoi(argv[1]));

	if (ft_atol(argv[1]) > INT_MAX)
		printf("Greater than int.\n");
	else if (ft_atol(argv[1]) < INT_MIN)
		printf("Lower than int.\n");

	return (0);
}
