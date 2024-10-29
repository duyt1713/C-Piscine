/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:33 by duha              #+#    #+#             */
/*   Updated: 2024/09/15 18:48:40 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_validation_row_left(int **clue, int **grid, int row)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (index < 3)
	{
		if (grid[row][index] < grid[row][index + 1])
			count++;
		index++;
	}
	if (clue[2][row] != count)
		return (0);
	return (1);
}

int	ft_validation_row_right(int **clue, int **grid, int row)
{
	int	count;
	int	index;

	count = 0;
	index = 4;
	while (index > 0)
	{
		if (grid[row][index] < grid[row][index + 1])
			count++;
		index--;
	}
	if (clue[3][row] != count)
		return (0);
	return (1);
}

int	ft_validation_column_down(int **clue, int **grid, int column)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (index < 3)
	{
		if (grid[index][column] < grid[index + 1][column])
			count++;
		index++;
	}
	if (clue[0][column] != count)
		return (0);
	return (1);
}

int	ft_validation_column_up(int **clue, int **grid, int column)
{
	int	count;
	int	index;

	count = 0;
	index = 4;
	while (index > 0)
	{
		if (grid[index][column] < grid[index + 1][column])
			count++;
		index--;
	}
	if (clue[3][column] != count)
		return (0);
	return (1);
}

int	ft_validation(int **grid, int **clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		if (!ft_validation_row_right(clues, grid, i) || \
				!ft_validation_row_left(clues, grid, i))
			return (0);
		while (j < 4)
		{
			if (!ft_validation_column_down(clues, grid, j) || \
					!ft_validation_column_up(clues, grid, j))
				return (0);
		}
	}
	return (1);
}
