/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:31 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/19 12:26:42 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_sprites(t_program *program)
{
	int	x;
	int	y;

	y = 0;
	while (y < program->map.height)
	{
		x = 0;
		while (x < program->map.length)
		{
			sprites_to_windows(program, x, y);
			x++;
		}
		y++;
	}
}

void	save_images(t_program *program)
{
	program->sprites.floor = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/floor.xpm", &program->floor.width, &program->floor.height);
	program->sprites.wall = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/walls.xpm", &program->wall.width, &program->wall.height);
	program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/pjfront.xpm", &program->pj.width, &program->pj.height);
	program->sprites.collect = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/collectable.xpm", &program->collect.width, \
		&program->collect.height);
	program->sprites.exit = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/exit.xpm", &program->exit.width, &program->exit.height);
}

void	sprites_to_windows(t_program *program, int x, int y)
{
	mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
		program->sprites.floor, x * 64, y * 64);
	if ((program->map).map[y][x] == '1')
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites.wall, x * 64, y * 64);
	if ((program->map).map[y][x] == 'P')
	{
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites.pj, x * 64 + 10, y * 64 + 10);
		program->position_x = x;
		program->position_y = y;
	}
	if ((program->map).map[y][x] == 'C')
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites.collect, x * 64 + 20, y * 64 + 20);
	if ((program->map).map[y][x] == 'E')
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites.exit, x * 64 + 16, y * 64 + 16);
}
