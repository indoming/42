/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:49:04 by indoming          #+#    #+#             */
/*   Updated: 2021/10/25 11:52:31 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnum(int n, int fd, int *size)
{
	long	num;

	num = n;
	while (num < 0)
	{
		ft_printchar('-', fd, size);
		num = num * -1;
	}
	if (num >= 10)
		ft_printnum (num / 10, fd, size);
	ft_printchar ((num % 10) + '0', fd, size);
}

void	ft_printunk(int n, int fd, int *size)
{
	unsigned int	num;

	num = n;
	if (num >= 10)
		ft_printunk (num / 10, fd, size);
	ft_printchar ((num % 10) + '0', fd, size);
}

void	ft_printstr(char *str, int fd, int *size)
{
	int	pos;

	if (!str)
		str = "(null)";
	pos = 0;
	while (str[pos] != '\0')
	{
		ft_printchar(str[pos], fd, size);
		pos++;
	}
}
