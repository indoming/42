/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:51:42 by indoming          #+#    #+#             */
/*   Updated: 2021/07/27 13:37:14 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;

	ptr = 0;
	len = count * size;
	ptr = malloc(len);
	if (ptr != 0)
		ft_bzero(ptr, len);
	return (ptr);
}
