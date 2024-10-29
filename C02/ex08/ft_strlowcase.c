/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:50:45 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:32 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	char	src[] = "FOOD WHERE HIVE";
	char	src1[] = "FOOO34//.DD";

	printf("%s\n", ft_strlowcase(src));
	printf("%s\n", ft_strlowcase(src1));
	return (0);
} */
