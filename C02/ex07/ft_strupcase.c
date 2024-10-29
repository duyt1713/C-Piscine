/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:39:34 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:29 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	char	src[] = "hive give me more food";
	char	src1[] = "FooOOooo88//OOOd";

	printf("%s\n", ft_strupcase(src));
	printf("%s\n", ft_strupcase(src1));
	return (0);
} */
