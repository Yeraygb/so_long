/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:31 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/09 13:41:54 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_sprites(t_program *program)
{
	int	x;
	int	y;

	y = 0;
	printf("entra en get sprites");
	save_images(program);
	while (y < (program->map)->height)
	{
		x = 0;
		while ((program->map)->map[x][y])
		{
			sprites_to_windows(program, x, y);
			x++;
		}
		y++;
	}
}

void	save_images(t_program *program)
{
	printf("entra en save images");
	program->sprites->floor = mlx_xpm_file_to_image(program->mlx_pointer, \
		"sprites/floor.xpm", &program->floor->width, &program->floor->height);
	program->sprites->wall = mlx_xpm_file_to_image(program->mlx_pointer, \
		"sprites/walls.xpm", &program->wall->width, &program->wall->height);
}

void	sprites_to_windows(t_program *program, int x, int y)
{
	if ((program->map)->map[x][y] == '0')
	{
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites->floor, x * 64, y * 64);
	}
	if ((program->map)->map[x][y] == '1')
	{
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites->wall, x * 64, y * 64);
	}
}
