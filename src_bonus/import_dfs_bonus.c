/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_dfs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:42:02 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/20 11:17:39 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	**copy_map(char **original_map, int height, int width)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(height * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (i < height)
	{
		map_copy[i] = malloc((width + 1) * sizeof(char));
		if (!map_copy[i])
			return (NULL);
		ft_strlcpy(map_copy[i], original_map[i], width + 1);
		i++;
	}
	return (map_copy);
}

void	free_dfs(t_dfs *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
}

void	set_directions(t_dfs *data_dfs)
{
	data_dfs->directions[0][0] = -1;
	data_dfs->directions[0][1] = 0;
	data_dfs->directions[1][0] = 1;
	data_dfs->directions[1][1] = 0;
	data_dfs->directions[2][0] = 0;
	data_dfs->directions[2][1] = -1;
	data_dfs->directions[3][0] = 0;
	data_dfs->directions[3][1] = 1;
}
