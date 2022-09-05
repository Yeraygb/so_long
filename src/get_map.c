/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/05 15:05:09 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
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

	program->map->length = 0;
	program->map->height = 0;
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
	program->map = malloc (sizeof(t_program));
	if (!program->map)
	{
		free(program->map);
		return ;
	}
	program->map->lines = count_lines(argv);
	//count_lines(argv, program)
	program->map->map = malloc(sizeof(char *) * program->map->lines + 1);
	if (!program->map->map)
	{
		free_double_array(program->map->map);
		return ;
	}
	check_map(program, argv);
}
