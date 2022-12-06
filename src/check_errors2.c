/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:54:31 by ygonzale          #+#    #+#             */
/*   Updated: 2022/12/06 12:44:57 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_walls(t_program *program)
{
	int	i;
	int	n;
	int	m;

	i = 0;
	n = 0;
	m = 0;
	while (program->map.map[i])
	{
		if ((program->map.map[i][program->map.length - 1] != '1' \
			|| program->map.map[i][0] != '1') \
			&& program->map.map[i][program->map.length - 1] != '\n')
		{
			ft_putendl_fd("The map have no wall complete", 2);
			exit (1);
		}
		i++;
	}
	wall_first_line(program);
	wall_last_line(program);
}

void	wall_first_line(t_program *program)
{
	int	i;

	i = 0;
	while (program->map.map[0][i])
	{
		if (program->map.map[0] && (program->map.map[0][i] != '1'))
		{
			ft_putendl_fd("The map have no wall complete", 2);
			exit (1);
		}
		i++;
	}
}

void	wall_last_line(t_program *program)
{
	int	i;

	i = 0;
	while (program->map.map[program->map.height - 1][i])
	{
		if (program->map.map[program->map.height - 1] \
			&& (program->map.map[program->map.height - 1][i] != '1'))
		{
			ft_putendl_fd("The map have no wall complete", 2);
			exit (1);
		}
		i++;
	}	
}
