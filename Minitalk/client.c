/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:31:37 by indoming          #+#    #+#             */
/*   Updated: 2022/03/08 10:46:32 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/include/libft.h"
#include "libft/include/ft_printf.h"

void	ft_send_bits(char c, int pid_num)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill (pid_num, SIGUSR2);
		else
			kill (pid_num, SIGUSR1);
		usleep(20);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_num;
	int	pos;

	pos = 0;
	if (argc == 3)
	{
		pid_num = ft_atoi(argv[1]);
		while (argv[2][pos])
		{
			ft_send_bits(argv[2][pos], pid_num);
			pos++;
		}
		ft_send_bits('\n', pid_num);
	}
	else
	{
		ft_printf("Error\n");
		ft_printf("Use: ./client [pid] string \n");
	}
	return (0);
}
