/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:40:03 by duha              #+#    #+#             */
/*   Updated: 2024/09/17 15:55:21 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

/*int	main(void)
{
	int	a = 6;
	int	b = 0;
	int	div;
	int	mod;

	ft_div_mod(a, b, &div, &mod);
	if (b != 0)
		printf("%i %i\n", div, mod);
	else
		printf("Function did not perform.\n");
	return (0);
}*/
