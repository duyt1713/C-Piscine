/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:09 by duha              #+#    #+#             */
/*   Updated: 2024/09/15 18:14:24 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

void	parse_input(char *input, int **clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4 && *input)
	{
		j = 0;
		while (j < 4)
		{
			if (*input != ' ')
			{
				clues[i][j] = ft_atoi(input);
				input++;
			}
			input++;
			j++;
		}
		i++;
	}
}
