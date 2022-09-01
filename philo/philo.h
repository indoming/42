/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:08:28 by indoming          #+#    #+#             */
/*   Updated: 2022/09/01 11:05:50 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				n_phils;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				t_phil_eat;
	int				id;
	int				init;
	int				leave;
	int				ready;
	int				*fork_taken;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	go;
	pthread_mutex_t	message;
	pthread_mutex_t	identify;
}	t_philo;

typedef struct s_table
{
	int		tid;
	int		lm;
	int		dishes;
	int		right_fork;
	int		left_fork;
	t_philo	*ph;
}	t_table;

//PHILO
void	*ft_begin(void *params);
void	ft_name_phils(t_philo *ph);
void	ft_free_phils(t_philo *ph);
void	ft_put_table(t_philo *ph);
int		main(int argc, char **argv);
//PHILO_ARGS
int		ft_atoi(const char *str);
int		ft_check_each_args(int argc, char **argv, t_philo *ph);
int		ft_check_args(int argc, char **argv, t_philo *ph);
//ACTIONS
void	ft_print_message(t_table *ph2, char *action);
int		ft_right_fork(t_table *ph2);
void	ft_take_forks(t_table *ph2);
void	ft_serve_dish(t_table *ph2);
void	ft_start_runing(t_table *ph2);
//TIME
int		ft_time_to_leave(t_table *ph2);
void	ft_usleep_adjusted(t_table *ph2, int end);
int		ft_set_time(void);

#endif
