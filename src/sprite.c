/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:42:19 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/19 17:42:20 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (data->map[y][x] == '8')
	{
		draw_image_to_cell(data, data->enemy[1], x, y);
		data->map[y][x] = '9';
	}
	else if (data->map[y][x] == '9')
	{
		draw_image_to_cell(data, data->enemy[0], x, y);
		data->map[y][x] = '4';
	}
}
