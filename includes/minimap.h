/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:08:29 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/22 19:57:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

typedef struct s_data	t_data;

typedef struct s_minimap
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		rect;
	int		scale;
	int		clr_back;
	int		clr_out;
	int		clr_wall;
	int		clr_floor;
	int		clr_ply;
	t_data	*data;
}	t_minimap;

/* init */
void	init_minimap(t_data *data);
/* utils */
void	draw_minimap_rect(t_minimap *mini, double px, double py, int color);
void	draw_minimap_background(t_data *data, t_minimap *mini);
void	draw_minimap_map(t_ray *ray, t_minimap *mini, char **map);
void	draw_minimap_player(t_minimap *mini);

#endif
