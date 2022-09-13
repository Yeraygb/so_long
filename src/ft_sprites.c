/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:31 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/13 14:55:13 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_sprites(t_program *program)
{
	int	x;
	int	y;

	y = 0;
	printf("entra en get sprites\n");
	save_images(program);
	printf("height:%d\n", program->map.height);
	while (y < program->map.height)
	{
		x = 0;
		//printf("entra en el bucle\n");
		while (x < program->map.length)
		{
			sprites_to_windows(program, x, y);
			x++;
			//printf("x y: %d , %d\n", x, y);
		}
		//printf("height2:%d\n", program->map.height);
		y++;
	}
	printf("saveimage\n");
}

void	save_images(t_program *program)
{
	printf("entra en save images\n");
	program->sprites.floor = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/floor.xpm", &program->floor.width, &program->floor.height);
	printf("floor:%s\n", program->sprites.floor);
	program->sprites .wall = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/walls.xpm", &program->wall.width, &program->wall.height);
	printf("walls:%s\n", program->sprites.wall);
}

void	sprites_to_windows(t_program *program, int x, int y)
{
	//printf("entra en sprite window\n");
	mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
		program->sprites.floor, x * 64, y * 64);
	//printf("x y: %d , %d\n", x, y);
	//printf("map: %c\n", (program->map.map)[x][y]);
/* 	if ((program->map).map[x][y] == '1')
	{
		mlx_put_image_to_window(program->mlx_pointer, program->format.format, \
			program->sprites.wall, x * 64, y * 64);
	}
	*/
}
