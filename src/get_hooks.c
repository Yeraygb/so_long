/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:29:15 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/14 16:17:07 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hooks(int keycode, t_program *program)
{
	int	i;

	i = 0;
	if (keycode == 0)
		i = a_d(keycode, program);
	if (keycode == 1)
		i = w_s(keycode, program);
	if (keycode == 2)
		i = a_d(keycode, program);
	if (keycode == 13)
		i = w_s(keycode, program);
/* 	if (keycode == 53)
	{
		exit_program();
	} */
	return (1);
}

void	a_d(int keycode, t_program *program)
{
	int	x;
	int	y;

	x = program->pj.width;
	y = program->pj.height;
	if (keycode == 0)
	{
		if (program->map.map[y][--x] == '1')
			return (0);
		program->map.map[y][x + 1] == '0';
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
			"./sprites/character.xpm", &program->pj.width, &program->pj.height);
	}
	if (keycode == 2)
	{
		if (program->map.map[y][++x] == '1')
			return (0);
		program->map.map[y][x - 1] == '0';
		program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
			"./sprites/character.xpm", &program->pj.width, &program->pj.height);
	}
}

void	w_s(int keycode, t_program *program)
{
	int	x;
	int	y;

	x = program->pj.width;
	y = program->pj.height;
	if (keycode == 1)
	{
	}
}

//void	exit_program()
