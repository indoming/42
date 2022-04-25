/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:31:07 by indoming          #+#    #+#             */
/*   Updated: 2022/03/07 12:14:11 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/include/libft.h"
#include "libft/include/ft_printf.h"

void	ft_signal_handler(int signal)
{
	static int	exp;
	static int	c;
	static int	bit;

	if (!c || bit == 8)
		c = 0;
	if (!bit || bit == 8)
		bit = 0;
	if (!exp || bit == 0)
		exp = 1;
	if (signal == SIGUSR2)
		c = c + exp;
	bit++;
	exp = exp * 2;
	if (bit == 8)
		write(1, &c, 1);
	if (bit == 8 && !c)
		ft_printf("\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		ft_printf("Run the server without arguments: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("The PID is: \n");
	ft_putnbr_fd(pid, 1);
	ft_printf("\n");
	while (argc == 1)
	{
		signal (SIGUSR1, ft_signal_handler);
		signal (SIGUSR2, ft_signal_handler);
		pause ();
	}
	return (0);
}
