/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:00:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:18:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* free_array frees the memory of a double entry array */
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* destroy_img destroys all minilibx images */
static void	destroy_img(t_data *data)
{
	int	i;

	if (data->img.ptr)
		mlx_destroy_image(data->mlx, data->img.ptr);
	i = 0;
	while (i < 4)
	{
		if (data->mat[i].ptr)
			mlx_destroy_image(data->mlx, data->mat[i].ptr);
		i++;
	}
}

/* free_all frees all allocated memory */
void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->mat[i].path)
			free(data->mat[i].path);
		i++;
	}
	if (data->map.floor_color)
		free(data->map.floor_color);
	if (data->map.ceiling_color)
		free(data->map.ceiling_color);
	if (data->map.str)
		free(data->map.str);
	if (data->map.array)
		free_array(data->map.array);
	destroy_img(data);
}
