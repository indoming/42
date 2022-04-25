/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:04:50 by indoming          #+#    #+#             */
/*   Updated: 2021/10/25 11:52:17 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check_readbyt(int readbyt, char *buff)
{
	if (readbyt == -1)
		free(buff);
}

char	*get_next_line(int fd)
{
	int			readbyt;
	static char	*leftstr;
	char		*line;
	char		*buff;

	readbyt = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(leftstr, '\n') && readbyt != 0)
	{
		readbyt = read(fd, buff, BUFFER_SIZE);
		ft_check_readbyt(readbyt, buff);
		if (readbyt == -1)
			return (NULL);
		buff[readbyt] = '\0';
		leftstr = ft_strjoin(leftstr, buff);
	}
	free(buff);
	line = ft_line(leftstr);
	leftstr = ft_newleftstr(leftstr);
	return (line);
}
