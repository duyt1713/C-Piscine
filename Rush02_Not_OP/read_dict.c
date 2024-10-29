/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehadfiel <ehadfiel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:27:40 by ehadfiel          #+#    #+#             */
/*   Updated: 2024/09/22 21:29:26 by ehadfiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	execute(char *dict, char *input);

int	read_dict(char *input)
{
	int		fd;
	char	dict[692];
	ssize_t	bytes_read;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, dict, 691);
	if (bytes_read <= 0)
	{
		close(fd);
		return (0);
	}
	dict[bytes_read] = '\0';
	if (execute(dict, input) == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
