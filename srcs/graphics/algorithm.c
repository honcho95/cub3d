/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:13:29 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/25 12:54:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* update_delta_dist calculates the length of the ray from
one side x or y to the next side x or y */
static void	update_delta_dist(t_ray *ray)
{	
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

/* update_step_dist calculates the step direction in x or y
and the lateral distance */
static void	update_step_dist(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->y) * ray->delta_dist_y;
	}
}

/* dda_algorithm implements the DDA (Digital Differential Analyzer) algorithm
used to calculate intersections between a ray and walls */
static void	dda_algorithm(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map.array[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/* update_player_pos_data updates all necessary information
according to the player's position */
void	update_player_pos_data(t_data *data, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double) data->win_w - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->cam_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->cam_x;
	ray->map_x = (int) data->ray.x;
	ray->map_y = (int) data->ray.y;
	update_delta_dist(ray);
	update_step_dist(ray);
	dda_algorithm(data, ray);
	if (ray->side == 0)
		ray->perpwalldist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perpwalldist = (ray->side_dist_y - ray->delta_dist_y);
}
