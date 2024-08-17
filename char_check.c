/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:34:44 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 20:56:00 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void char_increment(t_map *map, char c)
{
	if (c == 'P')
		(map->starts)++;
	else if (c == 'E')
		(map->exits)++;
	else if (c == 'C')
		(map->collectibles)++;
}

int char_check(t_map *map)
{	
	int	i;
	int	j;
	
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			char_increment(map, map->tiles[i][j]);
			j++;
		}
		i++;
	}
	if (map->starts > 1 || map->exits > 1 || map->collectibles < 1)
	{
		ft_printf("Error\nWrong number of players, exits or collectibles");
		return (0);
	}
	return (1);
}
