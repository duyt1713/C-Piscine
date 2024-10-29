/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:10:17 by duha              #+#    #+#             */
/*   Updated: 2024/09/19 18:41:12 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	target;

	target = nb;
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(target) == 1)
			return (target);
		else
			target++;
	}
	return (target);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int	argc, char	**argv)
{
	(void) argc;
	int	nb = atoi(argv[1]);
	int	result = ft_find_next_prime(nb);
	printf("%i is the next prime number greater or equal to %i.\n", result, nb);
	return (0);
} */
