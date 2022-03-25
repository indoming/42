/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:48:42 by indoming          #+#    #+#             */
/*   Updated: 2022/03/25 10:05:21 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_wall(t_var *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			"./img/wall.xpm", &var->pixel, &var->pixel);
	mlx_put_image_to_window (var->mlx, var->mlx_win,
		var->file, var->pixel * var->coor_x,
		var->pixel * var->coor_y);
}

void	ft_make_floor(t_var *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			"./img/floor.xpm", &var->pixel, &var->pixel);
	mlx_put_image_to_window (var->mlx, var->mlx_win,
		var->file, var->pixel * var->coor_x,
		var->pixel * var->coor_y);
}

void	ft_make_collect(t_var *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			"./img/Coinf.xpm", &var->pixel, &var->pixel);
	mlx_put_image_to_window (var->mlx, var->mlx_win,
		var->file, var->pixel * var->coor_x,
		var->pixel * var->coor_y);
	var->collect++;
}

void	ft_make_player(t_var *var)
{
	var->file = mlx_xpm_file_to_image(var->mlx,
			var->player_dir, &var->pixel, &var->pixel);
	var->playery = var->coor_y;
	var->playerx = var->coor_x;
	mlx_put_image_to_window (var->mlx, var->mlx_win,
		var->file, var->pixel * var->coor_x,
		var->pixel * var->coor_y);
}

void	ft_make_exit(t_var *var)
{
	if (var->collect > 0)
		var->file = mlx_xpm_file_to_image(var->mlx,
				"./img/exit3.xpm", &var->pixel, &var->pixel);
	else
	{
		var->file = mlx_xpm_file_to_image(var->mlx,
				"./img/exit4.xpm", &var->pixel, &var->pixel);
		var->file = mlx_xpm_file_to_image(var->mlx,
				"./img/exit2.xpm", &var->pixel, &var->pixel);
	}
	mlx_put_image_to_window (var->mlx, var->mlx_win,
		var->file, var->pixel * var->coor_x,
		var->pixel * var->coor_y);
}
