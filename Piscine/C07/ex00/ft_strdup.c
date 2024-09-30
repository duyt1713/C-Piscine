/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:15:03 by duha              #+#    #+#             */
/*   Updated: 2024/09/25 17:48:48 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*space;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	space = malloc((len + 1) * (sizeof(char)));
	if (!space)
		return (NULL);
	while (i < len)
	{
		space[i] = src[i];
		i++;
	}
	space[len] = '\0';
	return (space);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	char *res = ft_strdup(argv[1]);
	printf("%s", res);
	free(res);
	return (0);
} */
