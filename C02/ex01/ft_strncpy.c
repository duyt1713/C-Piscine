/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:41:34 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:08 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	unsigned int	n = 5;
	char	dest[42] = " ";
	char	src[] = "Fooooooooooooooooooooooooooooooooood";

	printf("%s\n", ft_strncpy(dest, src, n));
	return (0);
} */
