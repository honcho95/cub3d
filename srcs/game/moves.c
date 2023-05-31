/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:27:55 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/25 10:09:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* move_up moves the player's position up */
static void	move_up(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x + ray->dir_x * speed)] != '1')
		ray->x += ray->dir_x * speed;
	if (map[(int)(ray->y + ray->dir_y * speed)][(int)ray->x] != '1')
		ray->y += ray->dir_y * speed;
}

/* move_left moves the player's position to the left */
static void	move_left(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x - ray->plane_x * speed)] != '1')
		ray->x -= ray->plane_x * speed;
	if (map[(int)(ray->y - ray->plane_y * speed)][(int)ray->x] != '1')
		ray->y -= ray->plane_y * speed;
}

/* move_down moves the player's position down */
static void	move_down(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x - ray->dir_x * speed)] != '1')
		ray->x -= ray->dir_x * speed;
	if (map[(int)(ray->y - ray->dir_y * speed)][(int)ray->x] != '1')
		ray->y -= ray->dir_y * speed;
}

/* move_right moves the player's position to the right */
static void	move_right(t_ray *ray, char **map, double speed)
{
	if (map[(int)ray->y][(int)(ray->x + ray->plane_x * speed)] != '1')
		ray->x += ray->plane_x * speed;
	if (map[(int)(ray->y + ray->plane_y * speed)][(int)ray->x] != '1')
		ray->y += ray->plane_y * speed;
}

/* update_pos updates the position of the player according to the key pressed */
void	update_pos(t_data *data, t_ray *ray, char **map, double speed)
{
	if (data->key[W] == true)
		move_up(ray, map, speed);
	if (data->key[A] == true)
		move_left(ray, map, speed);
	if (data->key[S] == true)
		move_down(ray, map, speed);
	if (data->key[D] == true)
		move_right(ray, map, speed);
}
