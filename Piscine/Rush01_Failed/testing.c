/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airdiren <airdiren@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:18:39 by airdiren          #+#    #+#             */
/*   Updated: 2024/09/15 18:39:51 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_test(int x, int y)
{
	int	array[4][4] = { {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4} };
	int	row;
	int	col;

	printf("x %d\n", x);
	printf("y %d", y);
	x = 4;
	y = 4;
	row = 0;
	col = 0;
	while (row < x && col < y)
		// While neither all rows or columns are done...
	{
		if (row < x)
		{
			printf("%d", array[row][col]);
			row++;
		}
		if (row != y)
		{
			printf("\n");
			row = 0;
			col++;
		}
	}
}
