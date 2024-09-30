/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:25:28 by duha              #+#    #+#             */
/*   Updated: 2024/09/19 18:39:05 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	next;

	next = nb - 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (next <= nb && next >= 1)
	{
		nb = nb * next;
		next--;
	}
	return (nb);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int	argc, char	**argv)
{
	(void) argc;
	int	nb = atoi(argv[1]);
	int	result = ft_iterative_factorial(nb);
	printf("%i! = %i\n", nb, result);
	return (0);
} */
