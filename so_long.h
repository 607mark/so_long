/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:43:06 by mshabano          #+#    #+#             */
/*   Updated: 2025/01/21 23:36:40 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include <MLX42/MLX42.h>
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

# define SIZE 64
# define NAME "so_long"

# define WALL_IMG_PATH "./img/bush.png"
# define DUCK_IMG_PATH "./img/duck.png"
# define EGG_IMG_PATH "./img/egg.png"
# define GRASS_IMG_PATH "./img/grass.png"
# define NEST_IMG_PATH "./img/nest.png"

typedef struct s_win
{
	mlx_t	*mlx;
	int32_t	h;
	int32_t	w;
}	t_win;

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*duck;
	mlx_image_t	*egg;
	mlx_image_t	*grass;
	mlx_image_t	*nest;
}	t_img;

typedef struct s_map
{
	char	*file;
	int		fd;
	char	*line;
	char	**tiles;
	int		starts;
	int		exits;
	int		collectibles;
	int		moves;
	int		width;
	int		height;
	t_win	win;
	t_img	img;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
}	t_map;

int		read_map(char *s, t_map *map);
int		valid_map(t_map *map);
int		char_check(t_map *map);
int		path_find(t_map *map);
int		free_tiles(t_map *map, int i);
void	clean_exit(t_map *map, const char *s);
void	char_loop(t_map *map);
void	render_map(t_map *map);
void	init_images(t_map *map);
void	keyhook(mlx_key_data_t keydata, void *param);
#endif
