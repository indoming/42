/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_gnl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:49:49 by indoming          #+#    #+#             */
/*   Updated: 2022/03/24 11:18:35 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "so_long_bonus.h"

int	ft_check(char *str)
{
	int	pos;

	pos = 0;
	if (!str)
		return (0);
	while (str[pos])
	{
		if (str[pos] == '\0')
			return (1);
		pos++;
	}
	return (0);
}

char	*ft_join(char	*line, char c)
{
	int		pos;
	char	*str;

	pos = 0;
	while (line[pos])
		pos++;
	str = malloc(pos + 2);
	pos = 0;
	while (line[pos])
	{
		str[pos] = line[pos];
		pos++;
	}
	str[pos] = c;
	str[pos + 1] = '\0';
	free(line);
	return (str);
}

int	ft_checking(int fd, char **line, int *readed)
{
	*readed = 1;
	if (fd < 0)
	{
		*line = NULL;
		return (0);
	}
	*line = malloc(1);
	*line[0] = '\0';
	return (1);
}

char	*get_map(int fd)
{
	char	buffer;
	char	*line;
	int		readed;

	ft_checking(fd, &line, &readed);
	while (!ft_check(line) && readed > 0)
	{
		readed = read(fd, &buffer, 1);
		if (readed == 0)
		{
			if (line[0] == '\0')
			{
				free(line);
				return (NULL);
			}
			return (line);
		}
		if (readed < 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_join(line, buffer);
	}
	return (line);
}

void	ft_check_pce(char *buffer, t_var *var)
{
	int	j;

	j = 0;
	while (buffer[j])
	{
		if (buffer[j] == '\n')
			var->map_row++;
		if (buffer[j] == 'C')
			var->collect++;
		if (buffer[j] == 'E')
			var->exit++;
		if (buffer[j] == 'P')
			var->player++;
		j++;
	}
	if (var->exit != 1 || var->player != 1 || var->collect < 1)
	{
		printf("Error.");
		printf("The number of Players Coins or Exits aren´t right.\n");
		exit(1);
	}
}
