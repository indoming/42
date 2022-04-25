/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:36:21 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 12:17:47 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int num, int ncount, int *c)
{
	int	pos;

	pos = 0;
	while (ncount > pos)
	{
		if (c[pos] == num)
			return (pos);
		pos++;
	}
	return (0);
}

int	*sort_a_to_index(int *c, int *a, int ncount, int pos)
{
	int	pos1;
	int	temp;

	while (ncount > pos)
	{
		c[pos] = a[pos];
		pos++;
	}
	pos = 0;
	while (ncount > pos)
	{
		pos1 = pos + 1;
		while (ncount > pos1)
		{
			if (c[pos] > c[pos1])
			{
				temp = c[pos];
				c[pos] = c[pos1];
				c[pos1] = temp;
			}
			pos1++;
		}
		pos++;
	}
	return (a);
}

void	change_index(int *a, int ncount)
{
	int	pos;
	int	*c;

	c = malloc(ncount * sizeof(int));
	pos = 0;
	sort_a_to_index(c, a, ncount, 0);
	while (ncount > pos)
	{
		a[pos] = get_index(a[pos], ncount, c);
		pos++;
	}
	free (c);
}
