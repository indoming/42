/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 09:45:14 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 13:02:00 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid_2(int *a, int ncount, int lower, int mid)
{
	int	k;
	int	bottom;

	bottom = 0;
	k = ncount - 1;
	if (lower == 0)
		return (lower);
	ncount--;
	while (ncount >= 0)
	{
		if (a[ncount] <= mid)
		{
			bottom = ncount;
			break ;
		}
		ncount--;
	}
	if (k - bottom < k - lower)
		lower = bottom;
	return (lower);
}

int	get_mid(int *a, int ncount, int mid_val)
{
	int	pos;
	int	lower;

	pos = 0;
	lower = 0;
	while (ncount > pos)
	{
		if (a[pos] <= mid_val)
		{
			lower = pos;
			break ;
		}
		pos++;
	}
	lower = get_mid_2(a, ncount, lower, mid_val);
	return (lower);
}

void	to_the_top_a(int *a, int mid, int ncount)
{
	int	count;

	count = 0;
	if (mid == 0)
		return ;
	if (ncount - mid < mid)
	{
		while (count++ < ncount - mid)
			rra(a, ncount);
	}
	else
	{
		while (count++ < mid)
			ra(a, ncount);
	}
}

void	to_the_top_b(int *b, int max, int ncount_b)
{
	int	count;

	count = 0;
	if (max == 0)
		return ;
	if (ncount_b - max < max)
	{
		while (count++ < ncount_b - max)
			rrb(b, ncount_b);
	}
	else
	{
		while (count++ < max)
			rb(b, ncount_b);
	}
}

int	get_mid_value(int *a, int ncount)
{
	int	pos;

	pos = get_lower(a, ncount);
	if (ncount > 50)
		return (a[pos] + 30);
	return (a[pos] + (ncount - 3) / 2);
}
