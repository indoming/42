/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:59:01 by indoming          #+#    #+#             */
/*   Updated: 2021/08/02 13:10:44 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
		write (fd, "\n", 1);
	}
}
