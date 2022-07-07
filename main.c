/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:17:28 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/07 16:32:21 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	s_program;

	check_errors(argc, argv);
	ft_map(&s_program, argv);
	s_program.mlx_pointer = mlx_init();
	s_program.format->format = mlx_new_window(s_program.mlx_pointer, \
		s_program.map->length * 64, s_program.map->height * 64, "POKEMON'T");
	*mlx_xpm_file_to_image(s_program.mlx_pointer, , \
		s_program.map->length, s_program.map->height);
}
