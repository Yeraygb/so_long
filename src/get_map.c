/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/12/06 13:07:04 by ygonzale         ###   ########.fr       */
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
		check_empty_map(program);
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

void	check_empty_map(t_program *program)
{
	if (!program->line)
	{
		ft_putendl_fd("Wrong map: Empty map", 2);
		exit (0);
	}
}

void	check_map(t_program *program)
{
	int	i;

	i = 0;
	while (program->map.read[i])
	{
		if (program->map.read[i] == '\n')
		{	
			if (program->map.read[0] == '\n')
			{
				ft_putendl_fd("Empty line", 2);
				exit (0);
			}
			if (program->map.read[i + 1] == '\n')
			{
				ft_putendl_fd("Empty line", 2);
				exit (0);
			}
		}
		i++;
	}
	program->map.length = 0;
	program->map.height = 0;
	program->map.map = ft_split(program->map.read, '\n');
	program->map.length = ft_strlen(program->map.map[0]);
	program->map.height = program->map.lines;
}

void	ft_map(t_program *program, char **argv)
{
	program->map.lines = count_lines(argv, program);
	check_map(program);
	check_rectangle(program);
	error_char_map(program);
	check_empty_fd(program);
	check_walls(program);
	error_char_map(program);
}

void	check_empty_fd(t_program *program)
{
	if (program->map.length == 0 || program->map.height == 0)
	{
		ft_putendl_fd("Error: Empty map", 2);
		exit(0);
	}
}
