/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:05:13 by duha              #+#    #+#             */
/*   Updated: 2024/09/19 18:41:02 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	test;

	test = 0;
	if (nb < 0 || nb == 0)
		return (0);
	while (test * test < nb)
		test++;
	if (test * test == nb)
		return (test);
	else
		return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int	argc, char	**argv)
{
	(void) argc;
	int	nb = atoi(argv[1]);
	int	result = ft_sqrt(nb);
	if (result == 0)
		printf("The input number is either 0, negative or \
		the square root of such input is irrational.\n");
	else
		printf("√%i = %i\n", nb, result);
	return (0);
} */
