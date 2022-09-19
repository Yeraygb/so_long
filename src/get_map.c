/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/19 13:41:30 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	count_lines(char **argv, t_program *program)
{
	program->count = 0;
	program->fd = open(argv[1], O_RDONLY);
	if (program->fd == -1)
	{
		printf("Error to open map\n");
		exit(1);
	}
	else
	{
		program->line = get_next_line(program->fd);
		program->save_x = ft_substr(program->line, 0, ft_strlen(program->line));
		program->map.read = malloc(sizeof(char));
		program->map.read[0] = '\0';
		while (program->line)
		{
			program->map.read = ft_strjoin(program->map.read, program->line);
			program->count++;
			free(program->line);
			program->line = get_next_line(program->fd);
		}
		close(program->fd);
	}
	return (program->count);
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
	//error_map(program);
}
