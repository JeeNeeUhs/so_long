/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:39:54 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/19 18:23:58 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_data *data, char dir)
{
	if (dir == 'd')
	{
		if (data->map[data->y][data->x + 1] == '0')
			return (1);
	}
	else if (dir == 'a')
	{
		if (data->map[data->y][data->x - 1] == '0')
			return (1);
	}
	else if (dir == 'w')
	{
		if (data->map[data->y - 1][data->x] == '0')
			return (1);
	}
	else if (dir == 's')
	{
		if (data->map[data->y + 1][data->x] == '0')
			return (1);
	}
	return (0);
}

int	check_enemy(t_data *data, int x, int y)
{
	if (data->map[y][x] == '4' ||
		data->map[y][x] == '5' ||
		data->map[y][x] == '6' ||
		data->map[y][x] == '7' ||
		data->map[y][x] == '8' ||
		data->map[y][x] == '9')
		return (1);
	return (0);
}

int	check_collectible(t_data *data, char dir)
{
	if (dir == 'd')
	{
		if (data->map[data->y][data->x + 1] == 'C')
			return (1);
	}
	else if (dir == 'a')
	{
		if (data->map[data->y][data->x - 1] == 'C')
			return (1);
	}
	else if (dir == 'w')
	{
		if (data->map[data->y - 1][data->x] == 'C')
			return (1);
	}
	else if (dir == 's')
	{
		if (data->map[data->y + 1][data->x] == 'C')
			return (1);
	}
	return (0);
}

int	check_exit(t_data *data, char dir)
{
	if (dir == 'd')
	{
		if (data->map[data->y][data->x + 1] == 'E')
			return (1);
	}
	else if (dir == 'a')
	{
		if (data->map[data->y][data->x - 1] == 'E')
			return (1);
	}
	else if (dir == 'w')
	{
		if (data->map[data->y - 1][data->x] == 'E')
			return (1);
	}
	else if (dir == 's')
	{
		if (data->map[data->y + 1][data->x] == 'E')
			return (1);
	}
	return (0);
}

int	check_any_collectible(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			if (data->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
