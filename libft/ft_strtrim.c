/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:55:18 by indoming          #+#    #+#             */
/*   Updated: 2021/07/29 13:55:17 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(char c, char const *set)
{
	int	pos;

	pos = 0;
	while (set[pos])
	{
		if (set[pos++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;
	int		end;
	int		pos;

	pos = 0;
	start = 0;
	if (!s1 || !set)
		return (0);
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_setcheck(s1[start], set))
		start++;
	while (end > start && ft_setcheck(s1[end - 1], set))
		end--;
	s2 = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s2)
		return (0);
	while (start < end)
		s2[pos++] = s1[start++];
	s2[pos] = '\0';
	return (s2);
}
