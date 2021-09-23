/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:43:51 by indoming          #+#    #+#             */
/*   Updated: 2021/09/23 11:32:15 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex_may(unsigned int dec, int base, int *size)
{
	if (dec / base > 0)
	{
		ft_printhex_may(dec / base, base, size);
		if (dec % base < 10)
			ft_printnum(dec % base, 1, size);
		else
			ft_printchar(dec % base + 55, 1, size);
	}
	else
	{
		if (dec < 10)
			ft_printnum(dec, 1, size);
		else
			ft_printchar(dec + 55, 1, size);
	}
}

void	ft_printhex_min(unsigned long int dec, int base, int *size)
{
	if (dec	/ base > 0)
	{
		ft_printhex_min(dec / base, base, size);
		if (dec % base < 10)
			ft_printnum(dec % base, 1, size);
		else
			ft_printchar(dec % base + 87, 1, size);
	}
	else
	{
		if (dec < 10)
			ft_printnum(dec, 1, size);
		else
			ft_printchar(dec + 87, 1, size);
	}
}
