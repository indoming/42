/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:00:59 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 12:52:15 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *a, int ncount)
{
	int	min;
	int	pos;

	min = a[0];
	pos = 1;
	while (pos < ncount)
	{
		if (a[pos] < min)
			min = a[pos];
		pos++;
	}
	return (min);
}

void	min_to_0(int *a, int min, int ncount)
{
	int	pos;
	int	mid;

	pos = 0;
	while (a[pos] != min)
		pos++;
	mid = ncount / 2;
	if ((ncount % 2 == 0))
		mid--;
	while (min != a[0])
	{
		if (pos >= mid)
		{	
			rra(a, ncount);
			pos++;
		}
		else
		{
			ra(a, ncount);
			pos++;
		}
	}	
}

int	get_lower(int *a, int ncount)
{
	int	pos;
	int	lower;

	pos = 1;
	lower = 0;
	while (ncount > pos)
	{
		if (a[lower] > a[pos])
			lower = pos;
		pos++;
	}
	return (lower);
}

int	get_max(int *b, int ncount_b)
{
	int	pos;
	int	max;

	pos = 1;
	max = 0;
	while (ncount_b > pos)
	{
		if (b[max] < b[pos])
			max = pos;
		pos++;
	}
	return (max);
}

void	order_a_lot_2(int *a, int *b, int ncount, int ncount_b)
{
	int	max;

	while (ncount_b > 0)
	{
		max = get_max(b, ncount_b);
		to_the_top_b(b, max, ncount_b);
		pa(a, b, ncount_b, ncount);
		ncount++;
		ncount_b--;
	}
}
