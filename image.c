/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 22:20:20 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/20 23:04:28 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t *img_load(t_map *map, const char *path)
{
	mlx_image_t	*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		clean_exit(map, "Failed to load texture");
	image = mlx_texture_to_image(map->win.mlx, texture);
	if (!image)
		clean_exit(map, "Failed to convert texture");
	mlx_delete_texture(texture);
	if(!mlx_resize_image(image, TILE_SIZE, TILE_SIZE))
		clean_exit(map, "Failed to resize image");
	return (image);
}

void init_images(t_map *map)
{
	map->img.wall = img_load(map, WALL_IMG_PATH);
	map->img.duck = img_load(map, DUCK_IMG_PATH);
	map->img.egg = img_load(map, EGG_IMG_PATH);
	map->img.grass = img_load(map, GRASS_IMG_PATH);
	map->img.nest = img_load(map, NEST_IMG_PATH);
}
