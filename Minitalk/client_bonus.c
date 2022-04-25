/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:57:54 by indoming          #+#    #+#             */
/*   Updated: 2022/03/08 10:47:52 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"
#include "libft/include/ft_printf.h"

void	ft_send_bits(int pid_num, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill (pid_num, SIGUSR1);
		else
			kill (pid_num, SIGUSR2);
		usleep(80);
		bit++;
	}
}

void	ft_receive_signal(int signal, siginfo_t	*info, void *ucontest_t)
{
	(void)ucontest_t;
	(void)info;
	if (signal == SIGUSR1)
		ft_printf("Signal received\n");
	if (signal == SIGUSR2)
		ft_printf("Signal received\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid_numb;
	int					x;

	x = 0;
	sig.sa_handler = (void (*)(int))ft_receive_signal;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	if (argc != 3)
	{
		ft_printf("-----ERROR-----\n");
		ft_printf("Number of arguments is invalid\n");
		ft_printf("Try: ./client PID MESSAGE\n");
		return (1);
	}
	pid_numb = ft_atoi(argv[1]);
	while (argv[2][x] != '\0')
	{
		ft_send_bits(pid_numb, argv[2][x]);
		x++;
	}
	return (0);
}
