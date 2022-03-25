/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:38:37 by indoming          #+#    #+#             */
/*   Updated: 2022/03/25 09:56:45 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/include/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "lib/minilibx/mlx.h"

//general struct
typedef struct s_var
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*file;
	int		map_col;
	int		map_row;
	int		map_tot;
	int		coor_x;
	int		coor_y;
	int		pixel;
	int		collect;
	int		exit;
	int		player;
	int		playerx;
	int		playery;
	int		player_mov;
	char	*player_dir;
}	t_var;

//SO_LONG.C
void	ft_check_arguments(int argc, char **argv);
void	ft_readmap(char **argv, t_var *var);
void	ft_check_map(char *buffer, t_var *var);
void	ft_create_win(t_var *var);
//CHECK_WALL.C
void	ft_check_wall(t_var *var);
void	ft_check_wall_horiz(t_var *var);
void	ft_error_wall(void);
int		count_collect(t_var *var);
//SO_UTILS.C
int		ft_close_window(t_var *var);
int		ft_keyboard(int keyhook, t_var *var);
void	init_struct_var(t_var *var);
void	ft_make_green(t_var *var);
void	ft_fill_window(t_var *var);
//SO_GNL.C
char	*get_map(int fd);
int		ft_checking(int fd, char **line, int *readed);
char	*ft_join(char *line, char c);
int		ft_check(char *str);
void	ft_check_pce(char *buffer, t_var *var);
//FILLING.C
void	ft_make_wall(t_var *var);
void	ft_make_collect(t_var *var);
void	ft_make_floor(t_var *var);
void	ft_make_player(t_var *var);
void	ft_make_exit(t_var *var);
//MOVEMENTS.C
void	ft_move_up(t_var *var);
void	ft_move_down(t_var *var);
void	ft_move_left(t_var *var);
void	ft_move_right(t_var *var);

#endif
