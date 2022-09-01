/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:42:03 by indoming          #+#    #+#             */
/*   Updated: 2022/09/01 09:51:18 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int	ft_time_to_leave(t_table *tab)
{
	pthread_mutex_lock(&tab->ph->go);
	if (tab->ph->leave)
	{
		pthread_mutex_unlock(&tab->ph->go);
		return (1);
	}
	pthread_mutex_unlock(&tab->ph->go);
	if (ft_set_time() - tab->lm >= tab->ph->ttdie)
	{
		pthread_mutex_lock(&tab->ph->go);
		ft_print_message(tab, "died");
		tab->ph->leave = 1;
		pthread_mutex_unlock(&tab->ph->go);
		usleep(100);
	}
	return (tab->ph->leave);
}

void	ft_usleep_adjusted(t_table *tab, int end)
{
	int	time;

	time = ft_set_time();
	while (ft_set_time() - time < end)
	{
		usleep(100);
		if (ft_time_to_leave(tab))
			break ;
	}
}

int	ft_set_time(void)
{
	struct timeval	current;
	int				now;

	gettimeofday(&current, NULL);
	now = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (now);
}
