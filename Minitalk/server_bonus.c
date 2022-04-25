/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:57:29 by indoming          #+#    #+#             */
/*   Updated: 2022/03/08 10:22:46 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"
#include "libft/include/ft_printf.h"

void	ft_signal_handler(int signal, siginfo_t *info, void *ucontest_t)
{
	static int	bit;
	static int	c;

	(void)ucontest_t;
	(void)info;
	if (signal == SIGUSR1)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int					pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Number of arguments is invalid\n");
		ft_printf("Correct format: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("This is your PID: ");
	ft_putnbr_fd(pid, 1);
	ft_printf("\nWaiting for the message...\n");
	sig.sa_handler = (void (*)(int))ft_signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
