#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>


#include <MLX42/MLX42.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_map
{
	int fd;
	char *line;
	t_list *start;

	mlx_t	*mlx;
	char	**tiles;
	int	starts;
	int	ends;
	int	collectibles;
	int	width;
	int	height;
	int	x;
	int	y;
	int	start_x;
	int	start_y;

}	t_map;

int read_map(char *s, t_map *map);

#endif
