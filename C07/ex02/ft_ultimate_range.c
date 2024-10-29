/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:29:05 by duha              #+#    #+#             */
/*   Updated: 2024/09/25 12:34:46 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*space;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	space = malloc(size * sizeof(int));
	i = 0;
	if (!space)
	{
		*range = NULL;
		return (-1);
	}
	*range = space;
	while (i < size)
	{
		space[i] = min + i;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("Usage: %s <range> <min> <max>\n", argv[0]);
		return (1);
	}
	int i = 0;
	int *range;
	int	min = atoi(argv[2]);
	int	max = atoi(argv[3]);
	int res = ft_ultimate_range(&range, min, max);
	if (res == -1)
	{
		printf("Memory allocation failed.\n");
		return (-1);
	}
	if (res == 0)
	{
		printf("Invalid range.\n");
		return (0);
	}
	while (i < res)
	{
		printf("%d\n", range[i]);
		i++;
	}
	printf("Range is %d.\n", res);
	free(range);
	return (0);
} */
