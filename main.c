/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:06 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/21 00:14:41 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void close_window(void *param) {
    t_map *map = (t_map *)param; // Cast the void pointer to t_map
    mlx_close_window(map->win.mlx); // Close the window
    exit(0); // Exit the program
}

// Function to handle key press events
void handle_keypress(mlx_key_data_t keydata, void *param) {
    t_map *map = (t_map *)param; // Cast the void pointer to t_map
    if (keydata.action == MLX_PRESS) { // Check if the key is pressed
        if (keydata.key == MLX_KEY_ESCAPE) { // Check for escape key
            close_window(map); // Close the window if escape is pressed
        }
    }
}

void clean_exit(t_map *map, const char *s)
{
	free_arrs(map, map->height, "");

	ft_printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}
void check_input(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error\nNo arguments were passed\n");
		exit(EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		ft_printf("Error\nToo many arguments\n");
		exit(EXIT_FAILURE);
	}
}

void init_win(t_map *map)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	map->win.mlx = mlx_init(map->win.w, map->win.h, NAME, 1);
	if (!map->win.mlx)
		clean_exit(map, "Failed to mlx_init");
}

int main(int ac, char **av)
{
	t_map	map;
	ft_bzero(&map, sizeof(map));
	check_input(ac, av);
	if (!read_map(av[1], &map) || !(valid_map(&map)))
		exit(EXIT_FAILURE);
	//mlx_close_hook(map.win.mlx, close_window, &map); 
    	//mlx_key_hook(map.win.mlx, handle_keypress, &map);
	init_win(&map);
	init_images(&map);
	render_map(&map);
	mlx_loop(map.win.mlx);
	free_arrs(&map, map.height, "");	
	exit(EXIT_SUCCESS);
}
