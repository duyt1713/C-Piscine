/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehadfiel <ehadfiel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:06:58 by ehadfiel          #+#    #+#             */
/*   Updated: 2024/09/22 22:07:43 by ehadfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	write_1(char *dict, char *input, int search_index)
{
	int	index;

	index = 0;
	while (index != 79)
	{
		if (dict[index] == input[search_index])
		{
			index += 3;
			while (dict[index] != '\n')
			{
				ft_putchar(dict[index]);
				index++;
			}
			write(1, "\n", 1);
			return (1);
		}
		index++;
	}
	return (0);
}
