/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:31 by duha              #+#    #+#             */
/*   Updated: 2024/09/25 12:34:57 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strslen(int size, char **strs, char *sep)
{
	int	len;
	int	sep_len;
	int	i;
	int	j;

	len = 0;
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		if (i < size - 1)
			len += sep_len;
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*space;
	int		i;

	len = ft_strslen(size, strs, sep);
	space = malloc((len + 1) * sizeof(char *));
	if (!space)
		return (NULL);
	space[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(space, strs[i]);
		if (i < size - 1)
			ft_strcat(space, sep);
		i++;
	}
	return (space);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: %s <size> <string1> <string2> ... <separator>\n", argv[0]);
		return (1);
	}
	int size = atoi(argv[1]);
	if (size < 0 || size > argc - 2)
	{
		printf("Invalid size.\n");
		return (1);
	}
	char **strs = malloc(size * sizeof(char*));
	if (!strs)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	int i = 0;
	while (i < size)
	{
		strs[i] = argv[i + 2];
		i++;
	}
	char *sep = argv[argc - 1];
	char *res = ft_strjoin(size, strs, sep);
	printf("%s\n", res);
	free(strs);
	return (0);
} */
