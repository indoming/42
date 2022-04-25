/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:20:47 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 13:04:10 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int *a)
{
	free(a);
	ft_printf ("Error\n");
	exit (1);
}

void	check_rep(int *a, int num)
{
	int	pos;
	int	pos2;

	pos = 0;
	pos2 = 1;
	while (num > pos)
	{
		while (num > pos2)
		{
			if (a[pos] == a[pos2])
				ft_error(a);
			pos2++;
		}
		pos++;
		pos2 = pos +1;
	}
}

int	ft_ps_atoi(const char *str, int *a)
{
	unsigned int		i;
	int					sign;
	unsigned long int	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(a);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > 2147483648 && sign == -1) || (num > 2147483647 && sign == 1))
		ft_error(a);
	return (num * sign);
}
