/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:29:15 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/16 15:14:58 by ygonzale         ###   ########.fr       */
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
		i = a_d(keycode, program);
	if (keycode == 1)
		i = w_s(keycode, program);
	if (keycode == 2)
		i = a_d(keycode, program);
	if (keycode == 13)
		i = w_s(keycode, program);
	if (i == 1)
	{
		get_sprites(program);
	}
	return (1);
}

int	a_d(int keycode, t_program *program)
{
	int	x;
	int	y;

	x = program->pj.width;
	y = program->pj.height;
	if (keycode == 0)
	{
/* 		if (program->map.map[y][x - 1] == '1')
			return (0); */
		program->map.map[y][x + 1] = '0';
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
			"./sprites/pjfront.xpm", &x, &y);
	}
	if (keycode == 2)
	{
/* 		if (program->map.map[y][x + 1] == '1')
			return (0); */
		program->map.map[y][x - 1] = '0';
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
			"./sprites/pjfront.xpm", &x, &y);
	}
	return (1);
}

int	w_s(int keycode, t_program *program)
{
	int	x;
	int	y;

	x = program->pj.width;
	y = program->pj.height;
	if (keycode == 1)
	{
/* 		if (program->map.map[++y][x] == '1')
			return (0); */
		program->map.map[y - 1][x] = '0';
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
			"./sprites/pjfront.xpm", &x, &y);
	}
	if (keycode == 13)
	{
/* 		if (program->map.map[--y][x] == '1')
			return (0); */
		printf("hola\n");
		//printf("%s", program->map.map[y]);
		printf("%c", program->map.map[y + 1][x]);
		program->map.map[y + 1][x] = '0';
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
			"./sprites/pjfront.xpm", &x, &y);
	}
	return (1);
}

void	exit_program(t_program *program)
{
	mlx_destroy_window(program->mlx_pointer, program->format.format);
}
