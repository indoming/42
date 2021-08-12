/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:04:10 by indoming          #+#    #+#             */
/*   Updated: 2021/08/02 12:19:40 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	pos;
	char			*news;

	if (!s || !f)
		return (0);
	news = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!news)
		return (0);
	pos = 0;
	while (s[pos])
	{
		news[pos] = f(pos, s[pos]);
		pos++;
	}
	news[pos] = '\0';
	return (news);
}
