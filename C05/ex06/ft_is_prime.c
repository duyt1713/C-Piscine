/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:46:21 by duha              #+#    #+#             */
/*   Updated: 2024/09/19 18:41:05 by duha             ###   ########.fr       */
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
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int	argc, char	**argv)
{
	(void) argc;
	int	nb = atoi(argv[1]);
	int	result = ft_is_prime(nb);
	if (result == 0)
		printf("%i is not a prime number", nb);
	else
		printf("%i is a prime number", nb);
	return (0);
} */
