/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mov3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:18:37 by indoming          #+#    #+#             */
/*   Updated: 2022/02/24 11:32:51 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *a, int *b)
{
	int	tempa;
	int	tempb;

	tempa = a[0];
	a[0] = a[1];
	a[1] = tempa;
	tempb = b[0];
	b[0] = b[1];
	b[1] = tempb;
	ft_printf("ss\n");
}

void	rr(int *a, int *b, int ncount, int ncount_b)
{
	int	posa;
	int	tempa;
	int	posb;
	int	tempb;

	posa = 1;
	tempa = a[0];
	while (posa != ncount)
	{
		a[posa] = a[posa - 1];
		posa++;
	}
	posb = 1;
	tempb = b[0];
	while (posb != ncount_b)
	{
		b[posb] = b[posb - 1];
		posb++;
	}
	ft_printf("rr\n");
}

void	rrr(int *a, int *b, int ncount, int ncount_b)
{
	int	posa;
	int	tempa;
	int	posb;
	int	tempb;

	posa = 0;
	tempa = a[ncount - 1];
	while (posa)
	{
		a[posa] = a[posa + 1];
		posa++;
	}
	posb = 0;
	tempb = b[ncount_b -1];
	while (posb)
	{
		b[posb] = b[posb + 1];
		posb++;
	}
	ft_printf("rrr\n");
}
