/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:58:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/04/23 10:17:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef enum e_dir
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
}	t_dir;

typedef enum s_key
{
	W = 0,
	A = 1,
	S = 2,
	D = 3,
	L = 4,
	R = 5,
	SHIFT = 6,
}	t_key;

/* errors */
int		print_error(char *str);
void	exit_error(char *str);
void	free_and_exit(t_data *data, char *str);
/* free */
void	free_array(char **array);
void	free_all(t_data *data);

#endif
