/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshabano <mshabano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:01:09 by mshabano          #+#    #+#             */
/*   Updated: 2024/08/13 18:33:59 by mshabano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int read_map(char *map)
{

		int fd = open(map, O_RDONLY);
		if (fd < 0)
		{
			printf("Open failed\n");
			return 0;
		}
		printf("\n\n\tOpened file %s\n", map);
		char	*line;
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("Next_line = %s", line);
			free(line);
		}
		printf("\n");
		close(fd);
	}
	return 0;
}
