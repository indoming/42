/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:34:50 by indoming          #+#    #+#             */
/*   Updated: 2022/03/25 09:52:22 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (var)
	var->player_mov++;
	var->player_dir = "./img/right.xpm";
	ft_fill_window(var);
}
