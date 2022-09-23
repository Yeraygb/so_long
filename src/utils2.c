/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:15:50 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/23 15:30:38 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	a_hook(t_program *program, int x, int y)
{
	x = program->position_x;
	y = program->position_y;
	program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
	"./sprites/pjleft.xpm", &program->pj.width, &program->pj.height);
	if (program->map.map[y][x - 1] == '1')
		return (0);
	if (program->map.map[y][x - 1] == 'E' && check_collects(program) == 0)
		return (0);
	x--;
	move(program, x, y);
	program->map.map[y][x + 1] = '0';
	return (1);
}

int	d_hook(t_program *program, int x, int y)
{
	x = program->position_x;
	y = program->position_y;
	program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
	"./sprites/pjright.xpm", &program->pj.width, &program->pj.height);
	if (program->map.map[y][x + 1] == '1')
		return (0);
	if (program->map.map[y][x + 1] == 'E' && check_collects(program) == 0)
		return (0);
	x++;
	move(program, x, y);
	program->map.map[y][x - 1] = '0';
	return (1);
}

int	w_hook(t_program *program, int x, int y)
{
	x = program->position_x;
	y = program->position_y;
	program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
	"./sprites/pjback.xpm", &program->pj.width, &program->pj.height);
	if (program->map.map[y - 1][x] == '1')
		return (0);
	if (program->map.map[y - 1][x] == 'E' && check_collects(program) == 0)
		return (0);
	y--;
	move(program, x, y);
	program->map.map[y + 1][x] = '0';
	return (1);
}

int	s_hook(t_program *program, int x, int y)
{
	x = program->position_x;
	y = program->position_y;
	program->sprites.pj = mlx_xpm_file_to_image(program->mlx_pointer, \
	"./sprites/pjfront.xpm", &program->pj.width, &program->pj.height);
	if (program->map.map[y + 1][x] == '1')
		return (0);
	if (program->map.map[y + 1][x] == 'E' && check_collects(program) == 0)
		return (0);
	y++;
	move(program, x, y);
	program->map.map[y - 1][x] = '0';
	return (1);
}

void	move_count(t_program *program)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putstr_fd(ft_itoa(program->counter.move_count), 1);
	ft_putstr_fd("\n", 1);
	mlx_string_put(program->mlx_pointer, program->format.format, \
		16, 36, -255, "hola");
}
