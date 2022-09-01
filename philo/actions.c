/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:48:20 by indoming          #+#    #+#             */
/*   Updated: 2022/09/01 11:04:42 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	ft_print_message(t_table *tab, char *action)
{
	if (tab->ph->leave)
		return ;
	pthread_mutex_lock(&tab->ph->message);
	printf("%i %i %s\n", ft_set_time() - tab->ph->init, tab->tid, action);
	pthread_mutex_unlock(&tab->ph->message);
}

int	ft_right_fork(t_table *tab)
{
	int	right_fork;

	if (tab->tid == tab->ph->n_phils)
		right_fork = 0;
	else
		right_fork = tab->tid;
	return (right_fork);
}

void	ft_take_forks(t_table *tab)
{
	if (tab->ph->n_phils == 1)
	{
		pthread_mutex_lock(&tab->ph->fork[tab->left_fork]);
		ft_print_message(tab, "has taken a fork");
		ft_usleep_adjusted(tab, tab->ph->ttdie + 10);
		return ;
	}
	while (tab->ph->fork_taken[tab->left_fork]
		&& tab->ph->fork_taken[tab->right_fork])
		ft_usleep_adjusted(tab, 1);
	pthread_mutex_lock(&tab->ph->fork[tab->left_fork]);
	pthread_mutex_lock(&tab->ph->fork[tab->right_fork]);
	tab->ph->fork_taken[tab->left_fork] = 1;
	tab->ph->fork_taken[tab->right_fork] = 1;
	ft_print_message(tab, "has taken a fork");
	ft_print_message(tab, "has taken a fork");
}

void	ft_serve_dish(t_table *tab)
{
	ft_take_forks(tab);
	tab->lm = ft_set_time();
	ft_print_message(tab, "is eating");
	if (tab->dishes >= 0)
		tab->dishes--;
	ft_usleep_adjusted(tab, tab->ph->tteat);
	tab->ph->fork_taken[tab->right_fork] = 0;
	tab->ph->fork_taken[tab->left_fork] = 0;
	pthread_mutex_unlock(&tab->ph->fork[tab->right_fork]);
	pthread_mutex_unlock(&tab->ph->fork[tab->left_fork]);
}

void	ft_start_runing(t_table *tab)
{
	if (tab->tid % 2 == 0)
		ft_usleep_adjusted(tab, tab->ph->tteat);
	while (!tab->ph->leave)
	{
		ft_serve_dish(tab);
		if (tab->ph->leave || tab->dishes == 0)
			break ;
		ft_print_message(tab, "is sleeping");
		ft_usleep_adjusted(tab, tab->ph->ttsleep);
		if (tab->ph->leave)
			break ;
		ft_print_message(tab, "is thinking");
	}
}
