/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:06 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 20:52:13 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int main(int ac, char **av)
{
	t_map map;

	ft_bzero(&map, sizeof(map));
	check_input(ac, av);
	if (!read_map(av[1], &map) || !(valid_map(&map)))
		exit(EXIT_FAILURE);
	free_arrs(&map, map.height, "");	

	exit(EXIT_SUCCESS);

}
