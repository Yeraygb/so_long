/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/08 14:30:32 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	count_lines(char **argv)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error to open map");
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
	return (count);
}

void	check_map(t_program *program, char **argv)
{
	int		fd;
	char	*size;
	char	**split_map;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ;
	program->map->map = malloc(sizeof(char **) * 1);
	if (!(program->map)->map)
		return ;
	size = get_next_line (fd);
	split_map = ft_split(size, '\n');
	free(size);
	program->map->length = ft_strlen(split_map[0]);
	program->map->height = count_lines(argv);
	close(fd);
}

void	ft_map(t_program *program, char **argv)
{
	int	lines;

	program->map = malloc (sizeof(t_program));
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
	check_map(program, argv);
}
