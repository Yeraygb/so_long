/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/14 10:28:24 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	count_lines(char **argv, t_program *program)
{
	int		fd;
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error to open map");
	else
	{
		program->line = get_next_line(fd);
		program->save_x = ft_substr(program->line, 0, ft_strlen(program->line));
		program->map.read = malloc(sizeof(char));
		program->map.read[0] = '\0';
		while (program->line)
		{
			printf("line:%s\n", program->line);
			program->map.read = ft_strjoin(program->map.read, program->line);
			count++;
			free(program->line);
			program->line = get_next_line(fd);
		}
		close(fd);
	}
	printf("count:%d\n", count);
	return (count);
}

void	check_map(t_program *program, char **argv)
{
	program->map.length = 0;
	program->map.height = 0;
	program->map.map = ft_split(program->map.read, '\n');
	program->map.length = ft_strlen(program->map.map[0]);
	program->map.height = program->map.lines;
}

void	ft_map(t_program *program, char **argv)
{
	program->map.lines = count_lines(argv, program);
	check_map(program, argv);
}

/* 	program->map.map = malloc(sizeof(char *) * program->map.lines + 1);
	if (!program->map.map)
		return ; */
	//program->map.map = malloc (sizeof(t_program));
	/* if (!program->map)
		return ; */
	//printf("line:%zu\n", ft_strlen(program->line));
	//printf("save_x:%zu\n", ft_strlen(program->save_x));
/* 	while (y < program->map.lines)
	{
		program->map.map[y] = malloc(sizeof(char) \
			* ft_strlen(program->save_x) + 1);
		y++;
	}	 */