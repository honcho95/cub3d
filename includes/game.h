/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:25:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/02 18:26:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_ray	t_ray;

typedef struct s_game
{
	int		mat_px;
	double	fov;
	double	walk_speed;
	double	run_speed;
	double	rot_speed;
}	t_game;

/* game */
int		init_game(t_data *data);
/* hooks */
int		close_window(t_data *data);
int		key_pressed(int key, t_data *data);
int		key_release(int key, t_data *data);
int		mouse_rotate(int x, int y, t_data *data);
/* moves */
void	update_pos(t_data *data, t_ray *ray, char **map, double speed);
/* rotate */
void	update_angle(t_data *data, t_map *map, t_ray *ray, double speed);
void	update_angle_mouse(t_data *data, t_ray *ray, int left, double speed);
/* utils */
int		is_player(char c);
int		is_north_or_south(char c);
int		is_east_or_weast(char c);

#endif
