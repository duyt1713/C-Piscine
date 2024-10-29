/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:58 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:39 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/* #include <stdio.h>

int	main(void)
{
	printf("%i\n", ft_strcmp("Duy", "hungry"));
	printf("%i\n", ft_strcmp("hungry", "Duy"));
	printf("%i\n", ft_strcmp("Duy", "Duyy"));
	printf("%i\n", ft_strcmp("Duyy", "Duy"));
	printf("%i\n", ft_strcmp("Duy", "Duy"));
	return (0);
} */
