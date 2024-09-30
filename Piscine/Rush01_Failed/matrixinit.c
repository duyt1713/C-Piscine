/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:05 by duha              #+#    #+#             */
/*   Updated: 2024/09/15 18:11:25 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**create(void)
{
	int	**create;
	int	i;
	int	j;

	create = NULL;
	create = (int **)malloc(4 * sizeof(int *));
	if (!create)
		return (0);
	i = 0;
	while (i < 4)
	{
		create[i] = (int *)malloc(4 * sizeof(int));
		if (!create[i])
			return (0);
		j = 0;
		while (j < 4)
		{
			create[i][j] = 0;
			j++;
		}
		i++;
	}
	return (create);
}
