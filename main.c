/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:15:06 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/17 16:07:31 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_input(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("ERROR: no arguments were passed\n");
		exit(EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		ft_printf("ERROR: too many arguments\n");
		exit(EXIT_FAILURE);
	}
}

int main(int ac, char **av)
{
	t_map map;

	ft_bzero(&map, sizeof(map));
	check_input(ac, av);
	if (!read_map(av[1], &map || !map_valid(&map))
		exit(EXIT_FAILURE);
	

	exit(EXIT_SUCCESS);

}
