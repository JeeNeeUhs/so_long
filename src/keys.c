/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:41:20 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/19 17:41:38 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_data *data)
{
	counter(data, 1);
	if (check_enemy(data, data->x, data->y - 1))
		expected_exit(data);
	if (check_collectible(data, 'w'))
		data->map[data->y - 1][data->x] = '0';
	if (check_exit(data, 'w') && check_any_collectible(data) == 0)
		expected_exit(data);
	draw_original_block(data, data->x, data->y);
	data->y--;
	draw_image_to_cell(data, data->character, data->x, data->y);
}

void	key_a(t_data *data)
{
	if (check_enemy(data, data->x - 1, data->y))
		expected_exit(data);
	if (!(check_wall(data, 'a')))
	{
		data->character = data->character_left;
		draw_image_to_cell(data, data->character, data->x, data->y);
		return ;
	}
	counter(data, 1);
	if (check_collectible(data, 'a'))
		data->map[data->y][data->x - 1] = '0';
	if (check_exit(data, 'a') && check_any_collectible(data) == 0)
		expected_exit(data);
	draw_original_block(data, data->x, data->y);
	data->x--;
	data->character = data->character_left;
	draw_image_to_cell(data, data->character, data->x, data->y);
}

void	key_s(t_data *data)
{
	counter(data, 1);
	if (check_enemy(data, data->x, data->y + 1))
		expected_exit(data);
	if (check_collectible(data, 's'))
		data->map[data->y + 1][data->x] = '0';
	if (check_exit(data, 's') && check_any_collectible(data) == 0)
		expected_exit(data);
	draw_original_block(data, data->x, data->y);
	data->y++;
	draw_image_to_cell(data, data->character, data->x, data->y);
}

void	key_d(t_data *data)
{
	if (check_enemy(data, data->x + 1, data->y))
		expected_exit(data);
	if (!(check_wall(data, 'd')))
	{
		data->character = data->character_right;
		draw_image_to_cell(data, data->character, data->x, data->y);
		return ;
	}
	counter(data, 1);
	if (check_collectible(data, 'd'))
		data->map[data->y][data->x + 1] = '0';
	if (check_exit(data, 'd') && check_any_collectible(data) == 0)
		expected_exit(data);
	draw_original_block(data, data->x, data->y);
	data->x++;
	data->character = data->character_right;
	draw_image_to_cell(data, data->character, data->x, data->y);
}
