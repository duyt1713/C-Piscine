/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehadfiel <ehadfiel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:27:07 by ehadfiel          #+#    #+#             */
/*   Updated: 2024/09/22 21:27:25 by ehadfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	read_dict(char *input);

int	main(int argc, char **argv)
{
	if (argc != 2 || read_dict(argv[1]) == 0)
		write(1, "Error\n", 6);
	return (0);
}
