/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:14:20 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 23:32:57 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_map *map, int y, int x)
{
	if (map->tiles[y][x] == '1' || map->tiles[y][x] == '*')
		return;
	map->tiles[y][x] = '*';
	fill(map, y, x - 1);
	fill(map, y, x + 1);
	fill(map, y + 1, x);
	fill(map, y - 1, x);
}

int path_find(t_map *map)
{
	t_map map_2;

	ft_bzero(&map_2, sizeof(t_map));
	read_map(map->file, &map_2);
	ft_printf("\n");
	char_loop(&map_2);
	fill(&map_2, map_2.start_y, map_2.start_x);
	print_map(&map_2);
	map_2.starts = 0;
	map_2.exits = 0;
	map_2.collectibles = 0;
	char_loop(&map_2);
	free_arrs(&map_2, map->height, "");
	if(map_2.starts == 0 && map_2.exits == 0 && map_2.collectibles == 0)
		return (1);
	ft_printf("Error\nNo valid path for the map");
	return (0);
	
	
}
