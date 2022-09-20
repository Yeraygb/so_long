/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:29:15 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/20 10:27:05 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	teclas_hooks(int keycode, t_program *program)
{
	int	i;
	int	x;
	int	y;

	x = program->pj.width;
	y = program->pj.height;
	i = 0;
	y = 0;
	if (keycode == 53)
		exit_program(program);
	if (keycode == 0)
		i = horizontal(keycode, program);
	if (keycode == 1)
		i = vertical(keycode, program);
	if (keycode == 2)
		i = horizontal(keycode, program);
	if (keycode == 13)
		i = vertical(keycode, program);
	if (i == 1)
		get_sprites(program);
	return (1);
}

int	horizontal(int keycode, t_program *program)
{
	int	x;
	int	y;

	x = program->position_x;
	y = program->position_y;
	if (keycode == 0)
	{
		if (program->map.map[y][x - 1] == '1')
			return (0);
		x--;
		move(program, x, y);
		program->map.map[y][x + 1] = '0';
	}
	if (keycode == 2)
	{
		if (program->map.map[y][x + 1] == '1')
			return (0);
		x++;
		move(program, x, y);
		program->map.map[y][x - 1] = '0';
	}
	return (1);
}

int	vertical(int keycode, t_program *program)
{
	int	x;
	int	y;

	x = program->position_x;
	y = program->position_y;
	if (keycode == 1)
	{
		if (program->map.map[y + 1][x] == '1')
			return (0);
		y++;
		move(program, x, y);
		program->map.map[y - 1][x] = '0';
	}
	if (keycode == 13)
	{
		if (program->map.map[y - 1][x] == '1')
			return (0);
		y--;
		move(program, x, y);
		program->map.map[y + 1][x] = '0';
	}
	return (1);
}

void	exit_program(t_program *program)
{
	mlx_destroy_window(program->mlx_pointer, program->format.format);
	exit (1);
}

int	move(t_program *program, int x, int y)
{
	if (program->map.map[y][x] == '0' || program->map.map[y][x] == 'C')
	{
		program->map.map[y][x] = 'P';
	}
	return (1);
}
