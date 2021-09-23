/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:34:27 by indoming          #+#    #+#             */
/*   Updated: 2021/09/23 11:20:30 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_printchar(char c, int fd, int *size)
{
	write(fd, &c, 1);
	*size += 1;
}

void	ft_conversor(char conver, va_list list, int *size)
{
	if (conver == 'c')
		ft_printchar(va_arg(list, int), 1, size);
	else if (conver == 's')
		ft_printstr(va_arg(list, char *), 1, size);
	else if (conver == 'p')
	{
		ft_printstr("0x", 1, size);
		ft_printhex_min(va_arg(list, uintptr_t), 16, size);
	}	
	else if (conver == 'd' || conver == 'i')
		ft_printnum(va_arg(list, int), 1, size);
	else if (conver == 'u')
		ft_printunk(va_arg(list, unsigned int), 1, size);
	else if (conver == 'x') 
	   ft_printhex_min(va_arg(list, unsigned int), 16, size);
	else if	(conver == 'X')
		ft_printhex_may(va_arg(list, unsigned int), 16, size);
	else if (conver == '%')
		ft_printchar('%', 1, size);
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
		if (str[pos] == '%')
		{
			pos++;
			ft_conversor(str[pos], list, &size);
		}
		else
			ft_printchar(str[pos], 1, &size);
		pos++;
	}
	return (size);
}
