/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:49:11 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 18:35:34 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int free_tiles(t_map *map, int i)
{
	int j;
	
	j = 0;
	while (j < i && map->tiles[j])
	{
		free(map->tiles[j]);
		j++;
	}
	free(map->tiles);
	return (0);
}
