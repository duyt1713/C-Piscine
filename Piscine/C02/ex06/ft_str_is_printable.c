/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:34:16 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:25 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
			return (0);
		i++;
	}
	return (1);
}

/* #include <stdio.h>

int	main(void)
{
	char	str[] = "am hungy";
	char	str2[] = {0x01, 0x02, 0x03, '\0'};

	printf("%i\n", ft_str_is_printable(str));
	printf("%i\n", ft_str_is_printable(str2));
	return (0);
} */
