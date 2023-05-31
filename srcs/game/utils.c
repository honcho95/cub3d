/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:06:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:46:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* key_loop is the main key loop that changes the movement speed
if the player is walking or running */
// void	key_loop(t_data *data)
// {
// 	double	speed;

// 	speed = data->game.walk_speed;
// 	update_pos(data, &data->ray, data->map.array, speed);
// 	update_angle(data, &data->map, &data->ray, data->game.rot_speed);
// }
void	draw_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < (data->win_h / 2))
	{
		x = 0;
		while (x < data->win_w)
		{
			ft_mlx_pixel_put(&data->img, x, y,
				data->map.ceiling_rgb);
			ft_mlx_pixel_put(&data->img, x, y + (data->win_h / 2),
				data->map.floor_rgb);
			x++;
		}
		y++;
	}
}

/* is character is a simple function that checks if the character is a player */
int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/* is_north_or_south is a simple function that checks
if the player spawns north or south */
int	is_north_or_south(char c)
{
	return (c == 'N' || c == 'S');
}

/* is_east_or_weast is a simple function that checks
if the player spawns east or weast */
int	is_east_or_weast(char c)
{
	return (c == 'E' || c == 'W');
}
