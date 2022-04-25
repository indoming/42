/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:05:37 by indoming          #+#    #+#             */
/*   Updated: 2021/09/01 12:16:25 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *leftstr, char *buff)
{
	size_t	pos;
	size_t	pos2;
	char	*str;

	if (!leftstr)
	{
		leftstr = (char *)malloc(1 * sizeof(char));
		leftstr[0] = '\0';
	}
	if (!leftstr || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(leftstr) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	pos = -1;
	pos2 = 0;
	if (leftstr)
		while (leftstr[++pos] != '\0')
			str[pos] = leftstr[pos];
	while (buff[pos2] != '\0')
		str[pos++] = buff[pos2++];
	str[ft_strlen(leftstr) + ft_strlen(buff)] = '\0';
	free(leftstr);
	return (str);
}

char	*ft_line(char *leftstr)
{
	int		pos;
	char	*str;

	pos = 0;
	if (!leftstr[pos])
		return (NULL);
	while (leftstr[pos] && leftstr[pos] != '\n')
		pos++;
	str = (char *)malloc(sizeof(char) * (pos + 2));
	if (!str)
		return (NULL);
	pos = 0;
	while (leftstr[pos] && leftstr[pos] != '\n')
	{
		str[pos] = leftstr[pos];
		pos++;
	}
	if (leftstr[pos] == '\n')
	{	
		str[pos] = leftstr[pos];
		pos++;
	}
	str[pos] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	pos;

	pos = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[pos] != '\0')
	{
		if (s[pos] == (char) c)
			return ((char *)&s[pos]);
		pos++;
	}
	return (0);
}

char	*ft_newleftstr(char *leftstr)
{
	int		pos;
	int		pos2;
	char	*str;

	pos = 0;
	while (leftstr[pos] && leftstr[pos] != '\n')
		pos++;
	if (!leftstr[pos])
	{
		free(leftstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftstr) - pos + 1));
	if (!str)
		return (NULL);
	pos++;
	pos2 = 0;
	while (leftstr[pos])
		str[pos2++] = leftstr[pos++];
	str[pos2] = '\0';
	free(leftstr);
	return (str);
}
