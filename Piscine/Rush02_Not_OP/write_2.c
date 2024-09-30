/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehadfiel <ehadfiel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:41:14 by ehadfiel          #+#    #+#             */
/*   Updated: 2024/09/22 21:44:34 by ehadfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		write_1(char *dict, char *input, int search_index);
int		handle_one(char *dict, char *input);
int		handle_other_digits(char *dict, char *input);
int		handle_tens(char *dict, char *input);

int	write_2(char *dict, char *input)
{
	if (input[0] == '1')
		return (handle_one(dict, input));
	else if (input[1] == '0')
		return (handle_tens(dict, input));
	else
		return (handle_other_digits(dict, input));
}

int	handle_one(char *dict, char *input)
{
	int	index;

	index = 80;
	while (index != 199)
	{
		if (dict[index] == input[0])
		{
			index++;
			if (dict[index] == input[1])
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
		}
		index++;
	}
	return (0);
}

int	handle_other_digits(char *dict, char *input)
{
	int	index;

	index = 200;
	while (index != 285)
	{
		if (dict[index] == input[0])
		{
			index += 4;
			while (dict[index] != '\n')
			{
				ft_putchar(dict[index]);
				index++;
			}
			write(1, " ", 1);
			return (write_1(dict, input, 1));
		}
		index++;
	}
	return (0);
}

int	handle_tens(char *dict, char *input)
{
	int	index;

	index = 200;
	while (index != 285)
	{
		if (dict[index] == input[0])
		{
			index += 4;
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
