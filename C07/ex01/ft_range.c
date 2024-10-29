/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:50:19 by duha              #+#    #+#             */
/*   Updated: 2024/09/25 12:34:39 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*space;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	space = malloc(size * sizeof(int));
	i = 0;
	if (!space)
		return (NULL);
	while (i < size)
	{
		space[i] = min + i;
		i++;
	}
	return (space);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <min> <max>\n", argv[0]);
		return (1);
	}
	int i = 0;
	int	min = atoi(argv[1]);
	int	max = atoi(argv[2]);
	int *res = ft_range(min, max);
	if (res == NULL)
	{
		printf("Invalid range or memory allocation failed.\n");
		return (1);
	}
	while (i < max - min)
	{
		printf("%d\n", res[i]);
		i++;
	}
	free(res);
	return (0);
} */
