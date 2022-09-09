/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:17:28 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/09 13:14:23 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_program	s_program;

	check_argc_errors(argc);
	ft_map(&s_program, argv);
	s_program.mlx_pointer = mlx_init();
	s_program.format.format = mlx_new_window(s_program.mlx_pointer, \
		s_program.map->length * 64, s_program.map->height * 64, "POKEMON'T");
	get_sprites(&s_program);
	mlx_loop(s_program.mlx_pointer);
}
