/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:42:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 11:55:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* init_params initializes the variables of the game structure */
static void	init_params(t_data *data)
{
	data->game.mat_px = MAT_PX;
	data->game.fov = FOV;
	data->game.walk_speed = WALK_SPEED;
	data->game.run_speed = RUN_SPEED;
	data->game.rot_speed = ROT_SPEED;
}

/* init_map initializes the variables of the map structure */
static void	init_map(t_data *data)
{
	int	i;

	data->map.str = NULL;
	data->map.array = NULL;
	data->img.ptr = NULL;
	i = 0;
	while (i < 4)
	{
		data->mat[i].ptr = NULL;
		data->mat[i].path = NULL;
		i++;
	}
	data->map.floor_color = NULL;
	data->map.ceiling_color = NULL;
	data->map.floor_rgb = 0;
	data->map.ceiling_rgb = 0;
	data->map.dir = 0;
}

/* init_player initializes the position variables */
static void	init_player(t_data *data)
{
	data->ray.x = 0;
	data->ray.y = 0;
}

/* init_keys initializes the variables of the keys */
static void	init_keys(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		data->key[i] = false;
		i++;
	}
}

/* init_all initializes all structures */
void	init_all(t_data *data)
{
	data->win_w = WIN_W;
	data->win_h = WIN_H;
	init_params(data);
	init_map(data);
	init_player(data);
	init_keys(data);
	init_ray(&data->ray);
}
