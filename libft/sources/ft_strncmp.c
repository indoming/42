/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:36:25 by indoming          #+#    #+#             */
/*   Updated: 2021/07/27 11:42:38 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned int	diff;

	count = 0;
	diff = 0;
	while ((count < n) && !diff && (s1[count] != '\0') && (s2[count] != '\0'))
	{
		diff = (unsigned char)s1[count] - (unsigned char)s2[count];
		count++;
	}
	if (count < n && !diff && (s1[count] == '\0' || s2[count] == '\0'))
		diff = (unsigned char)s1[count] - (unsigned char)s2[count];
	return (diff);
}
