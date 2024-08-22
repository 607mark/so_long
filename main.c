/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:06 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/22 13:35:26 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_window(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	clean_exit(map, "Window was closed.");
}

void	clean_exit(t_map *map, const char *s)
{
	if (map->img.wall)
		mlx_delete_image(map->win.mlx, map->img.wall);
	if (map->img.duck)
		mlx_delete_image(map->win.mlx, map->img.duck);
	if (map->img.egg)
		mlx_delete_image(map->win.mlx, map->img.egg);
	if (map->img.grass)
		mlx_delete_image(map->win.mlx, map->img.grass);
	if (map->img.nest)
		mlx_delete_image(map->win.mlx, map->img.nest);
	if (map->tiles)
		free_tiles(map, map->height);
	if (map->win.mlx)
		mlx_terminate(map->win.mlx);
	ft_printf("%s\n", s);
	exit(EXIT_SUCCESS);
}

static void	check_input(int ac, t_map *map)
{
	if (ac < 2)
		clean_exit(map, "Error\nNo arguments were passed.");
	else if (ac > 2)
		clean_exit(map, "Error\nToo many arguments.");
}

static void	init_win(t_map *map)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	map->win.mlx = mlx_init(map->win.w, map->win.h, NAME, 1);
	if (!map->win.mlx)
		clean_exit(map, "Failed to mlx_init.");
}

int	main(int ac, char **av)
{
	t_map	map;

	ft_bzero(&map, sizeof(map));
	check_input(ac, &map);
	if (!read_map(av[1], &map) || !valid_map(&map))
		clean_exit(&map, "");
	init_win(&map);
	init_images(&map);
	render_map(&map);
	mlx_close_hook(map.win.mlx, close_window, &map);
	mlx_key_hook(map.win.mlx, keyhook, &map);
	mlx_loop(map.win.mlx);
	clean_exit(&map, "");
}
