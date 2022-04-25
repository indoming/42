/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:50:08 by indoming          #+#    #+#             */
/*   Updated: 2021/08/02 12:57:21 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	pos;

	pos = 0;
	if (s)
	{
		while (s[pos] != '\0')
		{
			write (fd, &s[pos], 1);
			pos++;
		}
	}
}
