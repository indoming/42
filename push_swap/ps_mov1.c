/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mov1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:49:48 by indoming          #+#    #+#             */
/*   Updated: 2022/04/25 09:40:37 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	ft_printf("sa\n");
}

void	sb(int	*b)
{
	int	temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	ft_printf("sb\n");
}

void	pa(int *a, int *b, int ncount_b, int ncount)
{	
	int	pos;
	int	pos1;

	pos = 0;
	pos1 = pos + 1;
	if (ncount_b > 0)
	{
		while (pos < ncount)
		{
			a[ncount - pos] = b[ncount - pos - 1];
			pos++;
		}
		a[0] = b[0];
		pos = 0;
		while (pos < ncount_b)
		{
			b[pos] = b[pos + 1];
			pos++;
		}
		ft_printf("pa\n");
	}
}

void	pb(int *a, int *b, int ncount_b, int ncount)
{
	int	pos;
	int	pos1;

	pos = 0;
	pos1 = pos + 1;
	if (ncount > 0)
	{
		while (pos < ncount_b)
		{
			b[ncount_b - pos] = b[ncount_b - pos - 1];
			pos++;
		}
		b[0] = a[0];
		pos = 0;
		while (pos < ncount)
		{
			a[pos] = a[pos + 1];
			pos++;
		}
		ft_printf("pb\n");
	}
}
