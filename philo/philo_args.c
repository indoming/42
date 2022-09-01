/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:13:23 by indoming          #+#    #+#             */
/*   Updated: 2022/09/01 11:04:04 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int					cnt;
	int					neg;
	unsigned long long	num;

	cnt = 0;
	neg = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[cnt] >= '\t' && str[cnt] <= '\r') || str[cnt] == ' ')
		cnt++;
	if (str[cnt] == '-')
		neg = -1;
	if (str[cnt] == '+' || str[cnt] == '-')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		num = (str[cnt] - '0') + (num * 10);
		cnt++;
	}
	return (num * neg);
}

int	ft_check_each_args(int argc, char **argv, t_philo *ph)
{
	ph->n_phils = ft_atoi(argv[1]);
	if (ph->n_phils <= 0)
		return (printf("You need at least one philosopher\n"), (0));
	ph->ttdie = ft_atoi(argv[2]);
	ph->tteat = ft_atoi(argv[3]);
	ph->ttsleep = ft_atoi(argv[4]);
	if (ph->ttdie <= 0 || ph->tteat <= 0 || ph->ttsleep <= 0)
		return (printf("Thank you, but i'm not that fast\n"), (0));
	if (argc == 6)
	{
		ph->t_phil_eat = ft_atoi(argv[5]);
		if (ph->t_phil_eat <= 0)
			return (printf("To think, they need to eat\n"), (0));
	}
	return (1);
}

int	ft_check_args(int argc, char **argv, t_philo *ph)
{
	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments\n");
		return (0);
	}
	if (!ft_check_each_args(argc, argv, ph))
	{
		printf("Try again\n");
		return (0);
	}
	return (1);
}
