/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:29:15 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/23 13:31:22 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	teclas_hooks(int keycode, t_program *program)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	if (keycode == 53)
		exit_program(program);
	if (keycode == 0)
		i = a_hook(program, x, y);
	if (keycode == 1)
		i = s_hook(program, x, y);
	if (keycode == 2)
		i = d_hook(program, x, y);
	if (keycode == 13)
		i = w_hook(program, x, y);
	if (i == 1)
	{
		program->counter.move_count++;
		move_count (program);
		get_sprites(program);
	}
	return (1);
}

/* int	horizontal(int keycode, t_program *program, int x, int y)
{
	x = program->position_x;
	y = program->position_y;
	if (keycode == 0)
	{
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/pjleft.xpm", &program->pj.width, &program->pj.height);
		if (program->map.map[y][x - 1] == '1')
			return (0);
		if (program->map.map[y][x - 1] == 'E' && check_collects(program) == 0)
			return (0);
		x--;
		move(program, x, y);
		program->map.map[y][x + 1] = '0';
	}
	if (keycode == 2)
	{
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/pjright.xpm", &program->pj.width, &program->pj.height);
		if (program->map.map[y][x + 1] == '1')
			return (0);
		if (program->map.map[y][x + 1] == 'E' && check_collects(program) == 0)
			return (0);
		x++;
		move(program, x, y);
		program->map.map[y][x - 1] = '0';
	}
	return (1);
} */

/* int	vertical(int keycode, t_program *program, int x, int y)
{
	x = program->position_x;
	y = program->position_y;
	if (keycode == 1)
	{
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/pjfront.xpm", &program->pj.width, &program->pj.height);
		if (program->map.map[y + 1][x] == '1')
			return (0);
		if (program->map.map[y + 1][x] == 'E' && check_collects(program) == 0)
			return (0);
		y++;
		move(program, x, y);
		program->map.map[y - 1][x] = '0';
	}
	if (keycode == 13)
	{
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/pjback.xpm", &program->pj.width, &program->pj.height);
		if (program->map.map[y - 1][x] == '1')
			return (0);
		if (program->map.map[y - 1][x] == 'E' && check_collects(program) == 0)
			return (0);
		y--;
		move(program, x, y);
		program->map.map[y + 1][x] = '0';
	}
	return (1);
} */

void	exit_program(t_program *program)
{
	int	i;

	i = 0;
	mlx_destroy_window(program->mlx_pointer, program->format.format);
	free(program->mlx_pointer);
	while (program->map.map[i])
	{
		free(program->map.map[i]);
		i++;
	}
	free(program->map.map);
	free(program->map.read);
	exit (0);
}

int	move(t_program *program, int x, int y)
{
	if (program->map.map[y][x] == 'C')
		program->counter.collec_count++;
	if (program->map.map[y][x] == '0' || program->map.map[y][x] == 'C')
		program->map.map[y][x] = 'P';
	if (program->map.map[y][x] == 'E' && check_collects(program) == 1)
		exit_program(program);
	return (1);
}
