/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/04 15:02:09 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/* int	map_long()
{
	ft_strlen;
} */

int	count_lines(char **argv)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("Error to open map", 2);
	else
	{
		line = get_next_line(fd);
		while (line)
		{
			count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (count++);
}

void	ft_map(t_program *program, char **argv)
{
	int	lines;

	program->map = malloc (sizeof(t_map));
	if (!program->map)
	{
		free(program->map);
		return ;
	}
	lines = count_lines(argv);
	program->map->map = malloc(sizeof(char *) * lines + 1);
	if (!program->map->map)
	{
		free_double_array(program->map->map);
		return ;
	}
}
