/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:17:58 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:42 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_strncmp("Duy", "duy", 6));
	printf("%i\n", ft_strncmp("Duy", "DUy", 2));
	printf("%i\n", ft_strncmp("Duy", "Duyy", 6));
	printf("%i\n", ft_strncmp("Duyy", "Duy", 3));
	printf("%i\n", ft_strncmp("Duy", "Duy", 5));
	return (0);
}*/
