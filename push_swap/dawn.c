/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dawn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:36 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 13:40:12 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_2(int *a)
{
	if (a[0] > a[1])
		sa(a);
}

void	order_3(int *a, int ncount)
{
	if (a[0] > a[1] && a[0] < a[2])
		sa(a);
	else if (a[0] < a[1] && a[0] > a[2])
		rra(a, ncount);
	else if (a[0] < a[1] && a[1] > a[2])
	{
		rra(a, ncount);
		sa(a);
	}
	else if (a[0] > a[1] && a[0] > a[2] && a[1] < a[2])
		ra(a, ncount);
	else if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
	{
		ra(a, ncount);
		sa(a);
	}
}

void	order_some(int *a, int *b, int ncount)
{
	int	ncount_b;

	ncount_b = 0;
	do_min(a, b, ncount, ncount_b);
}

void	order_a_lot(int *a, int *b, int ncount)
{
	int	mid;
	int	tcount;
	int	mid_val;
	int	ncount_b;

	ncount_b = 0;
	change_index(a, ncount);
	tcount = ncount;
	while (tcount > ncount_b + 3)
	{
		mid_val = get_mid_value(a, ncount);
		if (mid_val + 3 == tcount)
			mid_val--;
		while (ncount_b <= mid_val && tcount > ncount_b + 3)
		{
			mid = get_mid(a, ncount, mid_val);
			to_the_top_a(a, mid, ncount);
			pb(a, b, ncount_b, ncount);
			ncount_b++;
			ncount--;
		}
	}
	order_3(a, ncount);
	order_a_lot_2(a, b, ncount, ncount_b);
}

void	dawn(int **a, int **b, int ncount)
{
	if (ncount == 2)
		order_2(*a);
	else if (ncount == 3)
		order_3(*a, ncount);
	else if (ncount > 3 && ncount <= 9)
		order_some(*a, *b, ncount);
	else if (ncount > 9)
		order_a_lot(*a, *b, ncount);
}
