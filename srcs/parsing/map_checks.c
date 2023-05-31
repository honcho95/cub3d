/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:26:30 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:00:00 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* is_valid checks if the map contains only valid items */
static int	is_valid(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' '
				&& !is_player(map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/* check_player_spawn checks if there is only 1 position of player's spawn */
static int	check_player_spawn(char **map)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player(map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

/* check_is_valid_map checksif the map is valid */
void	check_is_valid_map(t_data *data)
{
	if (is_valid(data->map.array) != 0)
		free_and_exit(data, "Map can only contain 0, 1, space or player");
	if (check_player_spawn(data->map.array) != 1)
		free_and_exit(data, "Cant have more or less than 1 player spawn");
	if (is_walls_around(data->map.array) != 0)
		free_and_exit(data, "Map is open");
}
