/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:01:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 17:16:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* texture_cords calculates the position of the surface touched by a ray
and determines which part of the texture should be used to draw this surface */
static void	texture_cords(t_data *data, t_ray *ray, int start, int line_height)
{
	if (ray->side == 0)
		ray->wall_x = data->ray.y + ray->perpwalldist * ray->ray_dir_y;
	else
		ray->wall_x = data->ray.x + ray->perpwalldist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->mat_x = ray->wall_x * data->game.mat_px;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->mat_x = data->game.mat_px - ray->mat_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->mat_x = data->game.mat_px - ray->mat_x - 1;
	ray->step = 1.0 * data->game.mat_px / line_height;
	ray->tex_pos = (start - data->win_h / 2
			+ line_height / 2) * ray->step;
}

/* draw_texture draws a pixel of the texture at the specified
x and y position on the screen */
static void	draw_texture(t_data *data, int x, int texture)
{
	int	color;

	color = get_color(data, data->ray.mat_x, data->ray.mat_y, texture);
	ft_mlx_pixel_put(&data->img, x, data->ray.start, color);
}

/* draw_pxl_column draws a column of pixels */
void	draw_pxl_column(t_data *data, t_ray *ray, int x)
{
	int	line_height;

	line_height = get_height(data);
	ray->start = get_lowest_pxl(data, line_height);
	ray->end = get_highest_pxl(data, line_height);
	texture_cords(data, ray, ray->start, line_height);
	while (ray->start < ray->end)
	{
		ray->mat_y = (int)ray->tex_pos & (data->game.mat_px - 1);
		ray->tex_pos += ray->step;
		if (ray->side == 1 && ray->ray_dir_y < 0)
			draw_texture(data, x, SO);
		else if (ray->side == 1 && ray->ray_dir_y > 0)
			draw_texture(data, x, NO);
		else if (ray->side == 0 && ray->ray_dir_x < 0)
			draw_texture(data, x, WE);
		else if (ray->side == 0 && ray->ray_dir_x > 0)
			draw_texture(data, x, EA);
		ray->start++;
	}
}
