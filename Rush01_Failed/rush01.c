/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:16 by duha              #+#    #+#             */
/*   Updated: 2024/09/15 18:27:43 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	parse_input(char *input, int **clues);
//int ft_validation(int **grid, int **clues);
void	print_grid(int **grid);
int	**create(void);

void	rush(char *arr)
{
	int	**grid;
	int	**clues;
	int	i;
	int	j;

	grid = create();
	clues = create();
	parse_input(arr, clues);
	printf("clues\n");
	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			printf("%d", clues[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("grid\n");
	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			printf("%d", grid[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
