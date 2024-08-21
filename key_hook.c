/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:53:01 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/21 22:44:11 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int collect(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->img.egg->count)
	{
		if (map->img.egg->instances[i].x == map->x * SIZE &&
			map->img.egg->instances[i].y == map->y * SIZE)
		{	
			map->tiles[map->y][map->x] = '0';
			map->collectibles--;
			return (map->img.egg->instances[i].enabled = 0);
		}
			i++;
	}
}

void apply_move(t_map *map)
{

	int	y;
	int	x;

	y = map->y;
	x = map->x;
	print_map(map);
	map->moves++;
	ft_printf("Colle: %d\n", map->collectibles);
	ft_printf("Move #%d\n", map->moves);
	map->img.duck->instances[0].y = y * SIZE;
	map->img.duck->instances[0].x = x * SIZE;
	map->start_y = y;
	map->start_x = x;
}

void move(t_map *map)
{
	int	y;
	int	x;
	
	y = map->y;
	x = map->x;
	if (map->tiles[y][x] == '1')
		return ;
	else if (map->tiles[y][x] == '0')
		apply_move(map);
	else if (map->tiles[y][x] == 'C')
	{
		ft_printf("TEST \n%d\n", collect(map));
		apply_move(map);
	}
	else if (map->tiles[y][x] == 'E')
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
		clean_exit(map, "");
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		map->y = map->start_y - 1;
		map->x = map->start_x;
		move(map);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{

		map->y = map->start_y + 1;
		map->x = map->start_x;
		move(map);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{

		map->y = map->start_y;
		map->x = map->start_x - 1;
		move(map);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{

		map->y = map->start_y;
		map->x = map->start_x + 1;
		move(map);
	}
}
