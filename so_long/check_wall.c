/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:35:46 by indoming          #+#    #+#             */
/*   Updated: 2022/03/24 13:54:32 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_wall(void)
{
	printf("Error!\nThere is a hole in the wall\nSeal it to proceed\n");
	exit(1);
}

void	ft_check_wall_horiz(t_var *var)
{
	var->coor_y = 0;
	var->coor_x = 0;
	while ((var->coor_x) < (var->map_col))
	{
		if (var->map[0][var->coor_x] != '1')
			ft_error_wall();
		var->coor_x++;
	}
	var->coor_y = var->map_row - 1;
	var->coor_x = 0;
	while ((var->coor_x) < (var->map_col))
	{
		if (var->map[var->coor_y][var->coor_x] != '1')
			ft_error_wall();
		var->coor_x++;
	}
}

void	ft_check_wall(t_var *var)
{
	ft_check_wall_horiz(var);
	var->coor_y = 0;
	var->coor_x = 0;
	while ((var->coor_y) < (var->map_row))
	{
		if (var->map[var->coor_y][0] != '1')
			ft_error_wall();
		var->coor_y++;
	}
	var->coor_y = 0;
	var->coor_x = var->map_col - 1;
	while ((var->coor_y) < (var->map_row))
	{
		if (var->map[var->coor_y][var->coor_x] != '1')
			ft_error_wall();
		var->coor_y++;
	}
}

int	count_collect(t_var *var)
{
	int	count;

	count = 0;
	var->coor_y = 0;
	while ((var->coor_y) < (var->map_row))
	{
		var->coor_x = 0;
		while ((var->coor_x) < (var->map_col))
		{
			if (var->map[var->coor_y][var->coor_x] == 'C')
				count++;
			var->coor_x++;
		}
		var->coor_y++;
	}
	return (count);
}
