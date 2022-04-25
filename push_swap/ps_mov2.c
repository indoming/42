/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mov2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:08:24 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 12:16:11 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a, int ncount)
{
	int	pos;
	int	temp;

	pos = 0;
	temp = a[pos];
	pos++;
	while (ncount > pos)
	{	
		a[pos - 1] = a[pos];
		pos++;
	}
	a[pos - 1] = temp;
	ft_printf("ra\n");
}

void	rb(int *b, int ncount_b)
{
	int	pos;
	int	temp;

	pos = 0;
	temp = b[pos];
	pos++;
	while (ncount_b > pos)
	{	
		b[pos - 1] = b[pos];
		pos++;
	}
	b[pos - 1] = temp;
	ft_printf("rb\n");
}

void	rra(int *a, int ncount)
{
	int	temp;

	ncount--;
	temp = a[ncount];
	while (ncount)
	{
		a[ncount] = a[ncount - 1];
		ncount--;
	}
	a[ncount] = temp;
	ft_printf("rra\n");
}

void	rrb(int *b, int ncount_b)
{
	int	temp;

	ncount_b--;
	temp = b[ncount_b];
	while (ncount_b)
	{
		b[ncount_b] = b[ncount_b - 1];
		ncount_b--;
	}
	b[ncount_b] = temp;
	ft_printf("rrb\n");
}
