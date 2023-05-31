/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:35:57 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/27 07:31:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* map_contains_all_infos checks if the map file contains all the information,
so the 4 textures and the color of the floor and the ceiling */
static int	map_contains_all_infos(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->mat[i].path)
			return (1);
		i++;
	}
	if (!data->map.floor_color || !data->map.ceiling_color)
		return (1);
	return (0);
}

/* alloc_info checks that there is no duplicate information and saves
all the data by removing the line break and the spaces before and after */
static char	*alloc_info(t_data *data, char *line, int start, int info)
{
	char	*final;
	char	*tmp;
	int		new_line;
	int		len;

	if ((info == 1 && data->mat[NO].path)
		|| (info == 2 && data->mat[SO].path)
		|| (info == 3 && data->mat[WE].path)
		|| (info == 4 && data->mat[EA].path)
		|| (info == 5 && data->map.floor_color)
		|| (info == 6 && data->map.ceiling_color))
		free_and_exit(data, "Map contains duplicate information!");
	new_line = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		new_line = 1;
	tmp = ft_substr(line, start, (len - start) - new_line);
	if (!tmp)
		free_and_exit(data, "malloc failed !");
	final = ft_strtrim(tmp, " ");
	if (!final)
		free_and_exit(data, "malloc failed !");
	free(tmp);
	return (final);
}

/* alloc_map checks that all the information has been allocated
and saves each line of the map in a string */
static void	alloc_map(t_data *data, char *line)
{
	char	*tmp;

	if (map_contains_all_infos(data) != 0)
		free_and_exit(data, "Map doesn't contain all infos");
	tmp = ft_strdup(data->map.str);
	if (!tmp)
		free_and_exit(data, "malloc failed !");
	free(data->map.str);
	data->map.str = ft_strjoin(tmp, line);
	if (!data->map.str)
		free_and_exit(data, "malloc failed !");
	free(tmp);
}

/* parse_map compares each line to find the right
information to allocate */
void	parse_map(t_data *data, char *line)
{
	static int	is_map = 0;

	if (ft_strncmp("NO ", line, 3) == 0)
		data->mat[NO].path = alloc_info(data, line, 3, 1);
	else if (ft_strncmp("SO ", line, 3) == 0)
		data->mat[SO].path = alloc_info(data, line, 3, 2);
	else if (ft_strncmp("WE ", line, 3) == 0)
		data->mat[WE].path = alloc_info(data, line, 3, 3);
	else if (ft_strncmp("EA ", line, 3) == 0)
		data->mat[EA].path = alloc_info(data, line, 3, 4);
	else if (ft_strncmp("F ", line, 2) == 0)
		data->map.floor_color = alloc_info(data, line, 2, 5);
	else if (ft_strncmp("C ", line, 2) == 0)
		data->map.ceiling_color = alloc_info(data, line, 2, 6);
	else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
	{
		is_map = 1;
		alloc_map(data, line);
	}
	else if (line[0] == '\n' && is_map == 1)
		free_and_exit(data, "Map contains a newline!");
	else if (line[0] != '\n')
		free_and_exit(data, "Map syntax error!");
}
