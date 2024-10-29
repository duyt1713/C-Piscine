/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:45:06 by duha              #+#    #+#             */
/*   Updated: 2024/09/19 18:40:44 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int	argc, char	**argv)
{
	(void) argc;
	int	nb = atoi(argv[1]);
	int	power = atoi(argv[2]);
	int	result = ft_iterative_power(nb, power);
	printf("%i ^ %i = %i\n", nb, power, result);
	return (0);
} */
