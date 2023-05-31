/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:30:04 by fluchten          #+#    #+#             */
/*   Updated: 2023/05/02 18:21:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"
# include "game.h"
# include "graphics.h"
# include "parsing.h"
# include "utils.h"

# define WIN_W 1280
# define WIN_H 720
# define MAT_PX 64
# define FOV 0.66
# define WALK_SPEED 0.05
# define RUN_SPEED 0.09
# define ROT_SPEED 0.05

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2 
# define KEY_ESC 53
# define KEY_L 123
# define KEY_R 124

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	*path;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	char		*str;
	char		**array;
	char		*floor_color;
	char		*ceiling_color;
	int			floor_rgb;
	int			ceiling_rgb;
	char		dir;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	bool		key[7];
	t_game		game;
	t_map		map;
	t_img		img;
	t_img		mat[4];
	t_ray		ray;
	t_cross		cross;
}	t_data;

#endif
