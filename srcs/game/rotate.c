/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:27:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/02 18:27:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* rotate_angle shifts the player's view angle left or right */
static void	rotate_angle(t_ray *ray, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	ray->dir_x = ray->dir_x * cos(speed) - ray->dir_y * sin(speed);
	ray->dir_y = old_dir_x * sin(speed) + ray->dir_y * cos(speed);
	old_plane_x = ray->plane_x;
	ray->plane_x = ray->plane_x * cos(speed) - ray->plane_y * sin(speed);
	ray->plane_y = old_plane_x * sin(speed) + ray->plane_y * cos(speed);
}

/* update_angle update the player's view angle according to the key pressed */
void	update_angle(t_data *data, t_map *map, t_ray *ray, double speed)
{
	if (data->key[L] == true && is_north_or_south(map->dir))
		rotate_angle(ray, -speed);
	if (data->key[R] == true && is_east_or_weast(map->dir))
		rotate_angle(ray, -speed);
	if (data->key[L] == true && is_east_or_weast(map->dir))
		rotate_angle(ray, speed);
	if (data->key[R] == true && is_north_or_south(map->dir))
		rotate_angle(ray, speed);
}
