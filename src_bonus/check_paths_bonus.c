/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:38:32 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/20 11:17:16 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

void	check_paths(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			if (data->map[y][x] == 'C')
				create_find(data, data->map, x, y);
			if (data->map[y][x] == 'E')
				create_find(data, data->map, x, y);
			x++;
		}
		y++;
	}
}

void	create_find(t_data *data, char **map, int x, int y)
{
	t_dfs	*data_dfs;

	data_dfs = malloc(sizeof(t_dfs));
	if (!data_dfs)
		error_exit(data);
	set_directions(data_dfs);
	data_dfs->map = copy_map(map, data->window_height, data->window_width);
	data_dfs->width = data->window_width;
	data_dfs->height = data->window_height;
	data_dfs->x = data->x;
	data_dfs->y = data->y;
	data_dfs->goal_x = x;
	data_dfs->goal_y = y;
	if (!dfs(data_dfs))
	{
		free_dfs(data_dfs);
		error_exit(data);
	}
	else
		free_dfs(data_dfs);
}
