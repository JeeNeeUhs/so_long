/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:42:36 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/20 11:17:28 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "so_long_bonus.h"

void	error_exit(t_data *data)
{
	destroy_images(data);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data);
	free(data);
	write(1, "Error\n", 6);
	exit(-1);
}

void	destroy_images(t_data *data)
{
	if (data->sea)
		mlx_destroy_image(data->mlx, data->sea);
	if (data->tile)
		mlx_destroy_image(data->mlx, data->tile);
	if (data->berry)
		mlx_destroy_image(data->mlx, data->berry);
	if (data->character_right)
		mlx_destroy_image(data->mlx, data->character_right);
	if (data->character_left)
		mlx_destroy_image(data->mlx, data->character_left);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->enemy)
	{
		if (data->enemy[0])
			mlx_destroy_image(data->mlx, data->enemy[0]);
		if (data->enemy[1])
			mlx_destroy_image(data->mlx, data->enemy[1]);
		if (data->enemy[2])
			mlx_destroy_image(data->mlx, data->enemy[2]);
		if (data->enemy[3])
			mlx_destroy_image(data->mlx, data->enemy[3]);
		free(data->enemy);
	}
}

void	err(t_data *data)
{
	free(data);
	write(1, "Error\n", 6);
	exit(-1);
}

int	expected_exit(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	destroy_images(data);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	free_map(data);
	free(data);
	exit(-1);
	return (0);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->window_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
