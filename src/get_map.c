/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/09 13:36:40 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>
#include <stdlib.h>

int	count_lines(char **argv, t_program *program)
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
			program->map->read = ft_strjoin(program->map->read, line);
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
	program->map->length = 0;
	program->map->height = 0;
	program->map->map = ft_split(program->map->read, '\n');
	program->map->length = ft_strlen(program->map->map[0]);
	program->map->height = count_lines(argv, program);
}

void	ft_map(t_program *program, char **argv)
{
	program->map = malloc (sizeof(t_program));
	if (!program->map)
		return ;
	program->map->lines = count_lines(argv, program);
	program->map->map = malloc(sizeof(char *) * program->map->lines + 1);
	if (!program->map->map)
		return ;
	check_map(program, argv);
}
