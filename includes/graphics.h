/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:25:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/24 11:26:09 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

typedef struct s_data	t_data;
typedef struct s_img	t_img;

typedef struct s_ray
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	step_x;
	double	step_y;
	double	side;
	double	perpwalldist;
	int		start;
	int		end;
	double	wall_x;
	int		mat_x;
	int		mat_y;
	double	step;
	double	tex_pos;
}	t_ray;

typedef struct s_cross
{
	int		size;
	int		cx;
	int		cy;
	int		clr;
}	t_cross;

/* algorithm */
void	update_player_pos_data(t_data *data, t_ray *ray, int x);
/* draw_crosshair */
void	init_crosshair(t_data *data);

void	draw_pxl_column(t_data *data, t_ray *ray, int x);
void	draw_background(t_data *data);
/* raycasting */
void	init_ray(t_ray *ray);
void	init_raycasting(t_data *data);
/* utils */
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_height(t_data *data);
int		get_lowest_pxl(t_data *data, int line_height);
int		get_highest_pxl(t_data *data, int line_height);
int		get_color(t_data *data, int x, int y, int i);

#endif
