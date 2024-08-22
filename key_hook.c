/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:53:01 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/22 13:41:10 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_move(t_map *map, int y, int x)
{
	map->y = map->start_y + y;
	map->x = map->start_x + x;
}

static void	apply_move(t_map *map)
{
	ft_printf("Move #%d\n", ++map->moves);
	map->img.duck->instances[0].y = map->y * SIZE;
	map->img.duck->instances[0].x = map->x * SIZE;
	map->start_y = map->y;
	map->start_x = map->x;
}

static int	collect(t_map *map)
{
	long unsigned int	i;

	i = 0;
	apply_move(map);
	while (i < map->img.egg->count)
	{
		if (map->img.egg->instances[i].x == map->x * SIZE
			&& map->img.egg->instances[i].y == map->y * SIZE)
		{
			map->tiles[map->y][map->x] = '0';
			map->collectibles--;
			return (map->img.egg->instances[i].enabled = 0);
		}
		i++;
	}
	return (0);
}

static void	move(t_map *map, int y, int x)
{
	assign_move(map, y, x);
	if (map->tiles[map->y][map->x] == '1')
		return ;
	else if (map->tiles[map->y][map->x] == '0')
		apply_move(map);
	else if (map->tiles[map->y][map->x] == 'C')
		collect(map);
	else if (map->tiles[map->y][map->x] == 'E')
	{
		apply_move(map);
		if (map->collectibles == 0)
			clean_exit(map, "You won!");
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_exit(map, "Window was closed.");
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move(map, -1, 0);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move(map, +1, 0);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move(map, 0, -1);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move(map, 0, +1);
}
