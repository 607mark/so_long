/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:01:09 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 20:53:28 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int extension_check(char *map)
{
	if (ft_strncmp((map + ft_strlen(map) - 4), ".ber", 4))
	{
		ft_printf("Error\nIncorrect file extension");
		return (0);
	}
	return (1);
}

int fd_check(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nIncorrect file name or path");
		return 0;
	}
	return (1);
}

void count_height(t_map *map)
{
	while (1)
	{
		map->line = NULL;
		map->line = get_next_line(map->fd);
		if (!map->line)
			break;
		else
		{
			map->height++;
			free(map->line);
		}
	}
}

int add_map(t_map *map)
{
	int	i;
	
	printf("%d\n", map->height);
	if (map->height < 1)
		return (0);
	i = 0;
	map->tiles = malloc(map->height * sizeof(char *));
	if (!map->tiles)
		return (0);
	while (i < map->height)
	{
		map->line = NULL;
		map->line = get_next_line(map->fd);
		if (!map->line)
			break;
		else
		{
			if(ft_strchr(map->line, '\n'))
				*(ft_strchr(map->line, '\n')) = '\0';
			map->tiles[i] = map->line;
			i++;
		}
	}
	return (1);
}

void print_map(t_map *map)
{
    if (map == NULL || map->tiles == NULL)
    {
        ft_printf("Invalid map or tiles pointer.\n");
        return;
    }

    for (int i = 0; i < map->height; i++)  // Iterate through each row
    {
        if (map->tiles[i] != NULL)
        {
            ft_printf("%s\n", map->tiles[i]);  // Print each row (string)
        }
        else
        {
            ft_printf("(null)\n");  // Handle case where a row might be NULL
        }
    }
}

int read_map(char *s, t_map *map)
{

	if (!extension_check(s))
		return (0);
	map->fd = open(s, O_RDONLY);
	if (!fd_check(map->fd))
	{
		close(map->fd);
		return (0);
	}
	count_height(map);
	close(map->fd);
	map->fd = open(s, O_RDONLY);
	if (!add_map(map))
	{
		close(map->fd);
		return (0);
	}
	close(map->fd);
	print_map(map);
	return (1);
}
