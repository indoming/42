/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:42:36 by indoming          #+#    #+#             */
/*   Updated: 2022/03/24 09:56:38 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"

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
	int	pos;

	pos = 0;
	while (buffer[pos])
	{
		if (buffer[pos] == '\n')
			var->map_row++;
		if (buffer[pos] == 'C')
			var->collect++;
		if (buffer[pos] == 'E')
			var->exit++;
		if (buffer[pos] == 'P')
			var->player++;
		pos++;
	}
	if (var->exit != 1 || var->player != 1 || var->collect < 1)
	{
		printf("Error.");
		printf("The number of Players Coins or Exits aren´t right.\n");
		exit(1);
	}
}
