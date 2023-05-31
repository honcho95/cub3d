/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:54:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:00:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// /* pos_valid checks if the point next to the floor is in the map */
// static int	pos_valid(char **map, int x, int y)
// {
// 	if (y < 0 || y >= ft_array_len(map))
// 		return (1);
// 	if (x < 0 || x >= (int) ft_strlen(map[y]))
// 		return (1);
// 	if (map[y][x] == ' ')
// 		return (1);
// 	return (0);
// }

// /* check_around_pos checks the 4 positions around all the floors and
// the spawn position to check if the map is well surrounded by walls */
// static int	check_around_pos(char **map, int x, int y)
// {
// 	if (pos_valid(map, y - 1, x) != 0)
// 		return (1);
// 	if (pos_valid(map, y + 1, x) != 0)
// 		return (1);
// 	if (pos_valid(map, y, x - 1) != 0)
// 		return (1);
// 	if (pos_valid(map, y, x + 1) != 0)
// 		return (1);
// 	return (0);
// }

// /* is_walls_around checks that the whole map is closed by walls */
// int	is_walls_around(char **map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (map[y])
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == '0' || is_player(map[y][x]))
// 				if (check_around_pos(map, y, x) != 0)
// 					return (1);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

static int pos_valid(char **map, int x, int y) 
{
	int cols; 
	
	cols = ft_strlen(map[y]);
    if (y < 0 || y >= ft_array_len(map) || x < 0 || x >= cols || map[y][x] == ' ')
        return 1;  // Invalid position
    return 0;  // Valid position
}

int is_walls_around(char **map)
{
    int x;
    int y;

	x = 0;
	y = 0;
    while (map[y])
	{
        x = 0;
        while (map[y][x])
		{
            if (map[y][x] == '0' || is_player(map[y][x]))
			{
                if (pos_valid(map, x, y - 1) != 0 ||
                    pos_valid(map, x, y + 1) != 0 ||
                    pos_valid(map, x - 1, y) != 0 ||
                    pos_valid(map, x + 1, y) != 0)
                    return 1;  // Invalid map
            }
            x++;
        }
        y++;
    }
    return 0;  // Valid map
}
