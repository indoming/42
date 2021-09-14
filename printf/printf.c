/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:34:27 by indoming          #+#    #+#             */
/*   Updated: 2021/09/14 13:53:03 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printstr(int fd, char *str, int *size)
{
	int	pos;

	if (!str)
		str = "(null)";
	pos = 0;
	while (s[pos] != '\0')
	{
		ft_printone(str[pos], fd, size);
		pos++;
	}
}

void	ft_printone(int fd, char c, int *size)
{
	write(fd, &c, 1);
	&size += 1;
}

int	ft_conversor(char conver, va_list args, int *size)
{
	if (conver == 'c')
		ft_printone(va_arg(list, int), 1, ret);
	else if (conver == 's')
		ft_printstr(va_arg(list, char *), 1, ret);
	else if (conver == 'p')
		ft_printptr(va_arg(list, unsigned long long), *size)
//	else if (conver == 'd')
//
//	else if (conver == 'i')
//
//	else if (conver == 'u')
//
//	else if (concer == 'x')
//
//	else if (conver == 'X')
//		
	else if (conver == '%')
		ft_printone(%, 1, ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		pos;
	int		size;

	pos = 0;
	size = 0;
	va_start(list, str);
	while (str[pos] != '\0')
	{
		if (str[pos] == %)
		{
			pos++;
			ft_conversor(str[pos], list, &size);
		}
		else
			ft_putchar_fd(str[pos], 1, &size);
		pos++;
	}
	return (size);
}
