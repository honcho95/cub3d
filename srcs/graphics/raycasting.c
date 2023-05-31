/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:27:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 17:16:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* init_ray initializes the variables of the ray structure */
void	init_ray(t_ray *ray)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	ray->cam_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->perpwalldist = 0;
	ray->start = 0;
	ray->end = 0;
	ray->wall_x = 0;
	ray->mat_x = 0;
	ray->mat_y = 0;
	ray->step = 0;
	ray->tex_pos = 0;
}

/* init_raycasting launches raycasting on the whole window */
void	init_raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->win_w)
	{
		update_player_pos_data(data, &data->ray, x);
		draw_pxl_column(data, &data->ray, x);
		x++;
	}
}
