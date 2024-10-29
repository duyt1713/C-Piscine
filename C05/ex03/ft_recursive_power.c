/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:02:02 by duha              #+#    #+#             */
/*   Updated: 2024/09/19 18:43:03 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int	argc, char	**argv)
{
	(void) argc;
	int	nb = atoi(argv[1]);
	int	power = atoi(argv[2]);
	int	result = ft_recursive_power(nb, power);
	printf("%i ^ %i = %i\n", nb, power, result);
	return (0);
} */
