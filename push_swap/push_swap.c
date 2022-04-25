/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:13:26 by indoming          #+#    #+#             */
/*   Updated: 2022/04/22 13:40:18 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_number_count(char **argv)
{
	size_t	count;

	count = 0;
	while (*argv)
	{
		count++;
		argv++;
	}
	return (count);
}	

void	ft_push_swap(char **argv)
{
	int		*a;
	int		*b;
	long	ncount;
	int		pos;

	ncount = ft_number_count(argv);
	a = malloc((ncount) * sizeof(int));
	pos = 0;
	while (ncount > pos)
	{
		a[pos] = ft_ps_atoi(argv[pos], a);
		pos++;
	}
	check_rep(a, ncount);
	b = malloc((ncount) * sizeof(int));
	if (!sorted(a, ncount))
	{
		dawn(&a, &b, ncount);
	}
	free(a);
	free(b);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = ft_split(*argv, ' ');
		ft_push_swap(argv);
		return (0);
	}
	return (0);
}
