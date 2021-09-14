/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:17:23 by indoming          #+#    #+#             */
/*   Updated: 2021/09/14 13:52:52 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_ptrlen(uintptr_t num)
{
	int	count;

	count =	0;
	while (num != '\0')
	{
		count++;
		num = num / 16;
	}
	return (len);
}

int	ft_printptr(unsigned long long ptr, size)
{
	size += write(1, "0x", 2);
	if (ptr == 0)
		size += write(1, '0', 1);
	else
	{
		ft_putptr(ptr);
		size += ft_ptrlen(ptr);
	}
	return (size)
}
