/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:42:19 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/19 18:12:18 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	enemy_sprite(t_data *data, int x, int y)
{
	if (data->map[y][x] == '4')
	{
		draw_image_to_cell(data, data->enemy[1], x, y);
		data->map[y][x] = '5';
	}
	else if (data->map[y][x] == '5')
	{
		draw_image_to_cell(data, data->enemy[2], x, y);
		data->map[y][x] = '6';
	}
	else if (data->map[y][x] == '6')
	{
		draw_image_to_cell(data, data->enemy[3], x, y);
		data->map[y][x] = '7';
	}
	else if (data->map[y][x] == '7')
	{
		draw_image_to_cell(data, data->enemy[2], x, y);
		data->map[y][x] = '8';
	}
	else
		enemy_sprite2(data, x, y);
}

void	enemy_sprite2(t_data *data, int x, int y)
{
	int	random;

	if (data->map[y][x] == '8')
	{
		draw_image_to_cell(data, data->enemy[1], x, y);
		data->map[y][x] = '9';
	}
	else if (data->map[y][x] == '9')
	{
		draw_image_to_cell(data, data->enemy[0], x, y);
		random = rand() % 4;
		if (random == 0)
			move_enemy(data, 'w', x, y);
		else if (random == 1)
			move_enemy(data, 'a', x, y);
		else if (random == 2)
			move_enemy(data, 's', x, y);
		else if (random == 3)
			move_enemy(data, 'd', x, y);
		draw_image_to_cell(data, data->tile, x, y);
		data->map[y][x] = '0';
	}
}

void	move_enemy(t_data *data, char dir, int x, int y)
{
	if (dir == 'w' && data->map[y - 1][x] == '0')
	{
		data->map[y - 1][x] = '4';
		draw_image_to_cell(data, data->enemy[0], x, y - 1);
	}
	else if (dir == 'a' && data->map[y][x - 1] == '0')
	{
		data->map[y][x - 1] = '4';
		draw_image_to_cell(data, data->enemy[0], x - 1, y);
	}
	else if (dir == 's' && data->map[y + 1][x] == '0')
	{
		data->map[y + 1][x] = '4';
		draw_image_to_cell(data, data->enemy[0], x, y + 1);
	}
	else if (dir == 'd' && data->map[y][x + 1] == '0')
	{
		data->map[y][x + 1] = '4';
		draw_image_to_cell(data, data->enemy[0], x + 1, y);
	}
}
