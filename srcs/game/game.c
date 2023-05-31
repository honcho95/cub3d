/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:29:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/02 18:22:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* game_loop is the main loop of the game which calls all necessary functions */
static int	game_loop(t_data *data)
{
	double	speed;

	speed = data->game.walk_speed;
	update_pos(data, &data->ray, data->map.array, speed);
	update_angle(data, &data->map, &data->ray, data->game.rot_speed);
	draw_background(data);
	init_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}

/* init_game_main initializes the main image of the game */
static int	init_game_main(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx, data->win_w, data->win_h);
	if (!data->img.ptr)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (1);
	return (0);
}

/* init_game materials initializes the images of each texture */
static int	init_game_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->mat[i].ptr = mlx_xpm_file_to_image(data->mlx, data->mat[i].path,
				&data->mat[i].w, &data->mat[i].h);
		if (!data->mat[i].ptr)
			return (1);
		data->mat[i].addr = mlx_get_data_addr(data->mat[i].ptr,
				&data->mat[i].bpp, &data->mat[i].line_length,
				&data->mat[i].endian);
		if (!data->mat[i].addr)
			return (1);
		i++;
	}
	return (0);
}

/* init_hooks initializes game hooks */
static void	init_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_pressed, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}

/* init_game initializes minilibx and all its utilities */
int	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "cub3d");
	if (!data->win)
		return (1);
	if (init_game_main(data) != 0)
		return (1);
	if (init_game_textures(data) != 0)
		return (1);
	init_hooks(data);
	return (0);
}
