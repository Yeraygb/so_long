/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:43:31 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/08 12:00:55 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_sprites(t_program *program)
{
	int	width;
	int	height;

	program->sprites->floor = mlx_xpm_file_to_image(program->mlx_pointer, \
		"./sprites/background/floor.xpm", &width, &height);
}
