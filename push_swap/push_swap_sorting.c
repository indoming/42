/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:21:07 by indoming          #+#    #+#             */
/*   Updated: 2022/04/25 11:54:48 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(int *a, int ncount)
{
	int	pos;

	pos = 1;
	while (ncount > pos)
	{
		if (a[pos -1] > a[pos])
			return (0);
		pos++;
	}
	return (1);
}

void	do_min(int *a, int *b, int ncount, int ncount_b)
{
	int	min;

	while (ncount > 3)
	{
		min = get_min(a, ncount);
		min_to_0(a, min, ncount);
		ncount_b++;
		pb(a, b, ncount_b, ncount);
		ncount--;
	}
	if (!sorted (a, ncount))
		order_3(a, ncount);
	while (ncount_b != 0)
	{
		ncount++;
		pa(a, b, ncount_b, ncount);
		ncount_b--;
	}
}
