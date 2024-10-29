/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:33:37 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:55:24 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	if (*b != 0)
	{
		temp = *a;
		*a = temp / *b;
		*b = temp % *b;
	}
}

/*int	main(void)
{
	int	a = 6;
	int	b = 0;

	if (b != 0)
	{
		ft_ultimate_div_mod(&a, &b);
		printf("Results: %i & %i\n", a, b);
	}
	else
		printf("Function did not perform.\n");
	return (0);
}*/
