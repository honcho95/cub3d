/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:34:13 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 16:16:21 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* print_error displays an error message in the error output */
int	print_error(char *str)
{
	ft_putendl_fd("Error ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}

/* exit_error displays an error message and exits the program */
void	exit_error(char *str)
{
	print_error(str);
	exit(EXIT_FAILURE);
}

/* free_and_exit displays an error message, frees all allocated memory
and exits the program */
void	free_and_exit(t_data *data, char *str)
{
	print_error(str);
	free_all(data);
	exit(EXIT_FAILURE);
}
