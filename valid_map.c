/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:30:00 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 20:50:57 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int symbols_check(t_map *map)
{
	int	i;
	int	j;
	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (map->tiles[i][j])
		{
			if (!(ft_strchr((const char *)"01CEP", map->tiles[i][j])))
			{
				ft_printf("Error\nForbidden symbol");
				return (0);
			}	
			j++;
		}
		i++;
	}
	return (1);
}

int shape_check(t_map *map)
{
	int	i;
	
	i = 1;
	while(i < map->height)
	{
		if (ft_strlen(map->tiles[i]) != ft_strlen(map->tiles[0]))
		{
			ft_printf("Error\nThe map is not rectangular\n");
			return (0);
		}
		i++;
	}
	map->width = ft_strlen(map->tiles[0]);
	return (1);
}

void check_walls(t_map *map, int *flag)
{
	int	i;

	i = 0;
	while(i < map->height)
	{
		if(map->tiles[i][0] != '1')
			(*flag)++;
		i++;
	}
	i = 0;
	while(i < map->height)
	{
		if(map->tiles[i][map->width - 1] != '1')
			(*flag)++;
		i++;
	}
}

int borders_check(t_map *map)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while(map->tiles[0][i])
	{
		if (map->tiles[0][i] != '1')
			flag++;
		i++;
	}
	i = 0;
	while(map->tiles[map->height - 1][i])
	{
		if (map->tiles[map->height - 1][i] != '1')
			flag++;
		i++;
	}
	check_walls(map, &flag);
	if (flag)
		ft_printf("Error\nWalls are missing");
	return (!flag);
}

int valid_map(t_map *map)
{
	if (!symbols_check(map) || !shape_check(map) || !borders_check(map) || !char_check(map))
	{
		free_arrs(map, map->height, "");
		return (0);
	}
	return (1);
}
