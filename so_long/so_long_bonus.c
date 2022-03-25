/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: indoming <indoming@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:50:20 by indoming          #+#    #+#             */
/*   Updated: 2022/03/23 11:55:48 by indoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_create_win(t_var *var)
{
	var->pixel = 50;
	var->mlx = mlx_init();
	var->mlx_win = mlx_new_window(var->mlx,
			var->pixel * var->map_col,
			var->pixel * var->map_row, "Las locas aventuras de Solong");
}

void	ft_check_map(char *buffer, t_var *var)
{
	var->map_tot = ft_strlen(buffer) - var->map_row;
	if (var->map_tot != var->map_col * var->map_row)
	{
		printf("Error!\nThe map isn't correct!\n");
		exit (1);
	}
}

void	ft_readmap(char **argv, t_var *var)
{
	int		pos;
	int		fd;
	char	*buffer;

	pos = 0;
	var->map_col = 0;
	var->map_row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\nThe map can't be readed!.\n");
		exit (1);
	}
	buffer = get_map(fd);
	ft_check_pce(buffer, var);
	var->map = ft_split(buffer, '\n');
	while (var->map[0][pos] != '\0')
	{
		var->map_col++;
		pos++;
	}
	ft_check_map(buffer, var);
	close(fd);
}

void	ft_check_arguments(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error!\nNot enough arguments!\n");
		exit (1);
	}
	if (argc > 2)
	{
		printf("Error!\nToo many arguments!\n");
		exit (1);
	}
	if (argv[1] == 0)
	{
		printf("Error!\nThe file doesn´t  exist!\n");
		exit (1);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		printf("Error!\nThe file extension is not correct!\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_var	var;

	init_struct_var(&var);
	ft_check_arguments(argc, argv);
	ft_readmap(argv, &var);
	ft_check_wall(&var);
	ft_create_win(&var);
	var.player_dir = "./img/down.xpm";
	ft_fill_window(&var);
	mlx_hook(var.mlx_win, 2, 1L << 0, ft_keyboard, &var);
	mlx_hook(var.mlx_win, 17, 1L << 5, ft_close_window, &var);
	mlx_loop(var.mlx);
	exit(0);
	return (0);
}
