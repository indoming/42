/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:18:46 by indoming          #+#    #+#             */
/*   Updated: 2022/09/01 11:04:02 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_begin(void *params)
{
	t_table	tab;
	t_philo	*ph;

	ph = (t_philo *) params;
	tab = (t_table){.tid = ph->id,
		.dishes = ph->t_phil_eat, .ph = ph};
	tab.right_fork = ft_right_fork(&tab);
	tab.left_fork = tab.tid - 1;
	pthread_mutex_unlock(&tab.ph->identify);
	usleep(175);
	while (!ph->ready)
		usleep(100);
	ph->init = ft_set_time();
	tab.lm = ph->init;
	ft_start_runing(&tab);
	return (NULL);
}

void	ft_name_phils(t_philo *ph)
{
	int	num;

	num = 0;
	while (num < ph->n_phils)
	{
		pthread_mutex_lock(&ph->identify);
		ph->id = num + 1;
		if (pthread_create(&ph->thread[num], NULL, ft_begin, (void *)ph) != 0)
		{
			printf("Error creating the thread :%i\n", ph->id);
			break ;
		}
		if (num + 1 == ph->n_phils)
			ph->ready = 1;
		num++;
	}
}

void	ft_free_phils(t_philo *ph)
{
	int	num;

	num = 0;
	while (num < ph->n_phils)
	{
		pthread_join(ph->thread[num], NULL);
		pthread_mutex_destroy(&ph->fork[num]);
		num++;
	}
	pthread_mutex_destroy(&ph->message);
	pthread_mutex_destroy(&ph->identify);
	free(ph->fork_taken);
	free(ph->fork);
	free(ph->thread);
}

void	ft_put_table(t_philo *ph)
{
	int	num;

	num = 0;
	ph->leave = 0;
	ph->ready = 0;
	ph->fork_taken = (int *) malloc (ph->n_phils * sizeof(int));
	ph->thread = malloc (ph->n_phils * sizeof(pthread_t));
	ph->fork = (pthread_mutex_t *)
		malloc (ph->n_phils * sizeof(pthread_mutex_t));
	while (num < ph->n_phils)
	{
		pthread_mutex_init (&ph->fork[num], NULL);
		ph->fork_taken[num] = 0;
		num++;
	}
	pthread_mutex_init(&ph->go, NULL);
	pthread_mutex_init(&ph->message, NULL);
	pthread_mutex_init(&ph->identify, NULL);
}

int	main(int argc, char **argv)
{
	t_philo	ph;

	memset(&ph, 0, sizeof(t_philo));
	if (!ft_check_args(argc, argv, &ph))
		return (1);
	ft_put_table(&ph);
	ft_name_phils(&ph);
	ft_free_phils(&ph);
	return (0);
}
