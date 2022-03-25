/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:22 by indoming          #+#    #+#             */
/*   Updated: 2022/03/25 09:53:32 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_up(t_var *var)
{
	var->map[var->playery][var->playerx] = '0';
	var->map[var->playery - 1][var->playerx] = 'P';
	var->player_mov++;
	var->player_dir = "./img/up.xpm";
	ft_fill_window(var);
}

void	ft_move_down(t_var *var)
{
	var->map[var->playery][var->playerx] = '0';
	var->map[var->playery + 1][var->playerx] = 'P';
	var->player_mov++;
	var->player_dir = "./img/down.xpm";
	ft_fill_window(var);
}

void	ft_move_left(t_var *var)
{
	var->map[var->playery][var->playerx] = '0';
	var->map[var->playery][var->playerx - 1] = 'P';
	var->player_mov++;
	var->player_dir = "./img/left.xpm";
	ft_fill_window(var);
}

void	ft_move_right(t_var *var)
{
	var->map[var->playery][var->playerx] = '0';
	var->map[var->playery][var->playerx + 1] = 'P';
	var->player_mov++;
	var->player_dir = "./img/right.xpm";
	ft_fill_window(var);
}

void	ft_movements(t_var *var)
{
	mlx_string_put(var->mlx, var->mlx_win,
		var->pixel * var->map_col * (0.84), 10, 0x80000,
		"Movements: ");
	mlx_string_put(var->mlx, var->mlx_win,
		var->pixel * var->map_col * (0.96), 10, 0x80000,
		ft_itoa(var->player_mov));
}
