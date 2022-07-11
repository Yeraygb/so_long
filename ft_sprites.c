/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:31 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/08 14:20:08 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_sprites(t_program *program)
{
	program->floor = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/floor.xpm", &program->floor->width, &program->floor->height);
	program->wall = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/walls.xpm", &program->wall->width, &program->wall->height);
}
