/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:15:07 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/21 00:17:50 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display_tile(t_map *map, mlx_image_t *image, int y, int x)
{
	if(mlx_image_to_window(map->win.mlx, image, x * TILE_SIZE, y * TILE_SIZE) == -1)
		clean_exit(map, "Failed on mlx_image_to_window");
}

void render_tile(t_map *map, char c, int y, int x)
{
	if (c == '1')
		display_tile(map, map->img.wall, y, x);
	if (c != '1')
		display_tile(map, map->img.grass, y, x);
	else if (c == 'P')
		display_tile(map, map->img.duck, y, x);
	else if (c == 'C')
		display_tile(map, map->img.egg, y, x);
	else if (c == 'E')
		display_tile(map, map->img.nest, y, x);

}
void render_map(t_map *map)
{
 	int     i;
        int     j;

        i = 0;
        while (i < map->height)
        {
                j = 0;
                while(j < map->width)
                {
                        render_tile(map, map->tiles[i][j], i, j);
                        j++;
                }
                i++;
        }
}
