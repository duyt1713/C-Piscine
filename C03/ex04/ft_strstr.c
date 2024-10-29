/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:45:05 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:56:54 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[] = "0123456789duy";
	char	to_find[] = "duy";
	char	*result = ft_strstr(str, to_find);

	if (*to_find == '\0')
		printf("Substring is empty.\n");
	else if (result != NULL)
		printf("Substring found at position: %li\n", result - str);
	else printf("Substring not found.\n");
	return(0);
} */
