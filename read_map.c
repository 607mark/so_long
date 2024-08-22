/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:01:09 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/22 13:42:46 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_check(char *map)
{
	if (ft_strncmp((map + ft_strlen(map) - 4), ".ber", 4))
	{
		ft_printf("Error\nIncorrect file extension.");
		return (0);
	}
	return (1);
}

int	fd_check(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nIncorrect file name or path.");
		return (0);
	}
	return (1);
}

void	count_height(t_map *map)
{
	while (1)
	{
		map->line = NULL;
		map->line = get_next_line(map->fd);
		if (!map->line)
			break ;
		else
		{
			map->height++;
			free(map->line);
		}
	}
}

int	add_map(t_map *map)
{
	int	i;

	i = 0;
	map->tiles = malloc(map->height * sizeof(char *));
	if (!map->tiles)
		return (0);
	while (i < map->height)
	{
		map->line = NULL;
		map->line = get_next_line(map->fd);
		if (!map->line)
			return (0);
		else
		{
			if (ft_strchr(map->line, '\n'))
				*(ft_strchr(map->line, '\n')) = '\0';
			map->tiles[i] = map->line;
			i++;
		}
	}
	map->width = ft_strlen(map->tiles[0]);
	map->win.w = map->width * SIZE;
	map->win.h = map->height * SIZE;
	return (1);
}

int	read_map(char *s, t_map *map)
{
	if (!extension_check(s))
		return (0);
	map->file = s;
	map->fd = open(s, O_RDONLY);
	if (!fd_check(map->fd))
	{
		close(map->fd);
		return (0);
	}
	count_height(map);
	close(map->fd);
	if (map->height == 0)
		return (!ft_printf("Error\nFile is empty"));
	map->fd = open(s, O_RDONLY);
	if (!add_map(map))
	{
		ft_printf("Error\nMemory allocation failed\n");
		close(map->fd);
		return (0);
	}
	close(map->fd);
	return (1);
}
