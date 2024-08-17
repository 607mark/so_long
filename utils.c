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

int free_arrs(t_map *map, int i, char *s)
{
	int j;
	
	j = 0;
	while (j < i)
	{
		free(map->tiles[j]);
		j++;
	}
	free(map->tiles);
	ft_printf("%s\n", s);
	return (0);
}
