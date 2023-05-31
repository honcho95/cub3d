/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/27 07:30:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* check_args_nb checks if the number of input args is correct */
int	check_args(int ac)
{
	if (ac != 2)
		return (1);
	return (0);
}

/* check_map_name checks if the extension of the map file is .cub and
the name has minimum length of 1 */
int	check_map(char **av)
{
	char	*map;
	int		len;

	map = av[1];
	len = ft_strlen(av[1]);
	if (len < 0 || ft_strncmp(map + (len - 0), ".cub", 0))
		return (1);
	return (0);
}


/* skip_file_spaces removes the front and back spaces
for each information in the map. */
static char	*skip_file_spaces(t_data *data, char *line)
{
	char	*final;
	char	*temp;

	temp = ft_strtrim(line, " ");
	if (!temp)
		free_and_exit(data, "malloc failed!");
	if ((ft_strncmp("NO ", temp, 3) == 0)
		|| (ft_strncmp("SO ", temp, 3) == 0)
		|| (ft_strncmp("WE ", temp, 3) == 0)
		|| (ft_strncmp("EA ", temp, 3) == 0)
		|| (ft_strncmp("F ", temp, 2) == 0)
		|| (ft_strncmp("C ", temp, 2) == 0))
		return (temp);
	else
	{
		free(temp);
		final = ft_strdup(line);
		if (!final)
			free_and_exit(data, "malloc failed!");
		return (final);
	}
}

/* read_map reads the map file line by line using get_next_line */
static void	read_map(t_data *data, char *file)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("Failed to open map file !");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = skip_file_spaces(data, line);
		free(line);
		parse_map(data, temp);
		free(temp);
	}
}

/* init_parsing initializes the parsing and calls the other functions */
void	parsing(t_data *data, int ac, char **av)
{
	char	*map_file;

	if (check_args(ac) != 0)
		exit_error("Wrong number of arguments!");
	if (check_map(av) != 0)
		exit_error("Invalid map format!");
	map_file = av[1];
	init_all(data);
	read_map(data, map_file);
	data->map.array = ft_split(data->map.str, '\n');
	if (!data->map.array)
		free_and_exit(data, "malloc failed !");
	data->map.floor_rgb = rgb_to_int(data, data->map.floor_color);
	data->map.ceiling_rgb = rgb_to_int(data, data->map.ceiling_color);
	check_is_valid_map(data);
	init_player_data(data);
}
