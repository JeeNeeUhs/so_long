/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahekinci <ahekinci@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:27:49 by ahekinci          #+#    #+#             */
/*   Updated: 2025/01/13 13:27:31 by ahekinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	if (!s1 || !*s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len);
	return (str);
}

char	*to_nl(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new = (char *)malloc((sizeof(char) * i) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*read_line(int fd, char *left)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (!ft_strchr(left, '\n') && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return (free(left), free(str), NULL);
		str[i] = '\0';
		left = ft_strjoin(left, str);
	}
	free(str);
	return (left);
}

char	*after_nl(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
		return (free(left_str), NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free (left_str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(left), left = NULL, NULL);
	left = read_line(fd, left);
	if (!left)
		return (NULL);
	if (ft_strchr(left, '\n') == NULL)
	{
		line = ft_strdup(left);
		return (free(left), left = NULL, line);
	}
	line = to_nl(left);
	if ((ft_strchr(left, '\n') + 1) != NULL)
		left = after_nl(left);
	return (line);
}
