/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:38:10 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/20 11:17:12 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"

void	count_width_height(t_data *data, int fd)
{
	char	*line;
	int		flag;

	flag = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->window_height = data->window_height + 1;
		if (data->window_width == 0)
			data->window_width = ft_strlen(line);
		else
		{
			if (data->window_width != (int)ft_strlen(line))
				flag = 1;
		}
		free(line);
	}
	if (flag == 1)
		err(data);
	close(fd);
}

int	check_map(t_data *data, int start, int exit_c, int collectible)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			if (data->map[y][x] == 'P')
				start++;
			else if (data->map[y][x] == 'E')
				exit_c++;
			else if (data->map[y][x] == 'C')
				collectible++;
			else if (data->map[y][x] != '1' && data->map[y][x] != '0' &&
					data->map[y][x] != 'F')
				return (0);
			x++;
		}
		y++;
	}
	if (start == 1 && exit_c == 1 && collectible > 0)
		return (1);
	return (0);
}

void	filename_checker(char *str)
{
	int	i;

	if (ft_strlen(str) < 5)
		err(NULL);
	else
	{	
		i = ft_strlen(str) - 1;
		if (!(str[i] == 'r' && str[i - 1] == 'e'
				&& str[i - 2] == 'b' && str[i - 3] == '.'))
			err(NULL);
		if (str[i - 4] == '/' || str[i - 4] == '\0')
			err(NULL);
	}
}

void	checker(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err(data);
	count_width_height(data, fd);
	close(fd);
	data->map = malloc(sizeof(char *) * data->window_height);
	if (!data->map)
		err(data);
	init_map(data, argv[1]);
	if (!check_map(data, 0, 0, 0))
		error_exit(data);
	find_player(data);
	check_paths(data);
	if (!map_walls(data->map, data->window_width, data->window_height))
		error_exit(data);
}
