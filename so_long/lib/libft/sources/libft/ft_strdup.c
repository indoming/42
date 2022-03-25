/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:44:30 by indoming          #+#    #+#             */
/*   Updated: 2021/10/25 11:37:45 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*s1b;
	size_t		len;

	len = ft_strlen(s1) + 1;
	s1b = malloc(len);
	if (!s1b)
		return (0);
	ft_memcpy(s1b, s1, len);
	return (s1b);
}
