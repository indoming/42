/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:51:40 by indoming          #+#    #+#             */
/*   Updated: 2022/03/25 10:00:01 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_window(t_var *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(1);
	return (0);
}

int	ft_keyboard(int keyhook, t_var *var)
{
	if (keyhook == 53)
		ft_close_window(var);
	if (var->collect == 0
		&& ((keyhook == 2 && var->map[var->playery][var->playerx + 1] == 'E')
		|| (keyhook == 1 && var->map[var->playery + 1][var->playerx] == 'E')
		|| (keyhook == 0 && var->map[var->playery][var->playerx - 1] == 'E')
		|| (keyhook == 13 && var->map[var->playery - 1][var->playerx] == 'E')))
		ft_close_window(var);
	if (keyhook == 13 && var->map[var->playery - 1][var->playerx] != '1'
		&& var->map[var->playery - 1][var->playerx] != 'E')
		ft_move_up(var);
	if (keyhook == 0 && var->map[var->playery][var->playerx - 1] != '1'
		&& var->map[var->playery][var->playerx - 1] != 'E')
		ft_move_left(var);
	if (keyhook == 1 && var->map[var->playery + 1][var->playerx] != '1'
		&& var->map[var->playery + 1][var->playerx] != 'E')
		ft_move_down(var);
	if (keyhook == 2 && var->map[var->playery][var->playerx + 1] != '1'
		&& var->map[var->playery][var->playerx + 1] != 'E')
		ft_move_right(var);
	return (0);
}

void	ft_make_green(t_var *var)
{
	var->coor_y = 0;
	while ((var->coor_y) < (var->map_row))
	{
		var->coor_x = 0;
		while ((var->coor_x) < (var->map_col))
		{
			var->file = mlx_xpm_file_to_image(var->mlx,
					"./img/Floor.xpm", &var->pixel, &var->pixel);
			mlx_put_image_to_window (var->mlx, var->mlx_win,
				var->file, var->pixel * var->coor_x,
				var->pixel * var->coor_y);
			var->coor_x++;
		}
		var->coor_y++;
	}
}

void	ft_fill_window(t_var *var)
{
	var->collect = count_collect(var);
	ft_make_green(var);
	var->coor_y = 0;
	while ((var->coor_y) < (var->map_row))
	{
		var->coor_x = 0;
		while ((var->coor_x) < (var->map_col))
		{
			if (var->map[var->coor_y][var->coor_x] == '1')
				ft_make_wall(var);
			else if (var->map[var->coor_y][var->coor_x] == 'C')
				ft_make_collect(var);
			else if (var->map[var->coor_y][var->coor_x] == 'P')
				ft_make_player(var);
			else if (var->map[var->coor_y][var->coor_x] == 'E')
				ft_make_exit(var);
			var->coor_x++;
		}
		var->coor_y++;
	}
	ft_movements(var);
}

void	init_struct_var(t_var *var)
{
	var->map_col = 0;
	var->map_row = 0;
	var->map_tot = 0;
	var->coor_x = 0;
	var->coor_y = 0;
	var->pixel = 0;
	var->collect = 0;
	var->exit = 0;
	var->player = 0;
	var->player_mov = 0;
}
