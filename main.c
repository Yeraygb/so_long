/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:17:28 by ygonzale          #+#    #+#             */
/*   Updated: 2022/12/14 13:57:57 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_program	program;

	program.counter.collec_count = 0;
	program.counter.move_count = 0;
	check_argc_errors(argc);
	check_ber(argv);
	ft_map(&program, argv);
	if (!do_you_know_the_way(&program))
		return (0);
	program.mlx_pointer = mlx_init();
	program.format.format = mlx_new_window(program.mlx_pointer, \
		program.map.length * 64, program.map.height * 64, "POKEMON'T");
	save_images(&program);
	get_sprites(&program);
	mlx_key_hook(program.format.format, teclas_hooks, &program);
	mlx_hook(program.format.format, 17, 0, (void *)exit, 0);
	mlx_loop(program.mlx_pointer);
	return (0);
}
