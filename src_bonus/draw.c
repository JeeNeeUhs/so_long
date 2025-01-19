/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:40:26 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/19 17:40:33 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"

void	draw_image_to_cell(t_data *data, void *image, int x, int y)
{
	x *= data->square_size;
	y *= data->square_size;
	mlx_put_image_to_window(data->mlx, data->window, image, x, y);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			draw_map_if(data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map_if(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		draw_image_to_cell(data, data->sea, x, y);
	else if (data->map[y][x] == 'C')
		draw_image_to_cell(data, data->berry, x, y);
	else if (data->map[y][x] == 'P')
	{
		draw_image_to_cell(data, data->character, x, y);
		data->x = x;
		data->y = y;
		data->map[y][x] = '0';
	}
	else if (data->map[y][x] == 'E')
		draw_image_to_cell(data, data->exit, x, y);
	else if (data->map[y][x] == 'F')
	{
		draw_image_to_cell(data, data->enemy[0], x, y);
		data->map[y][x] = '4';
	}
	else if (data->map[y][x] == '0')
		draw_image_to_cell(data, data->tile, x, y);
}

void	draw_original_block(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		draw_image_to_cell(data, data->sea, x, y);
	else
		draw_image_to_cell(data, data->tile, x, y);
	if (data->map[y][x] == 'C')
		draw_image_to_cell(data, data->berry, x, y);
	else if (data->map[y][x] == 'E')
		draw_image_to_cell(data, data->exit, x, y);
	else if (data->map[y][x] == 'F')
		draw_image_to_cell(data, data->tile, x, y);
}
