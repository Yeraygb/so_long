/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:50 by ygonzale          #+#    #+#             */
/*   Updated: 2022/12/06 13:09:39 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_argc_errors(int argc)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Number of argument invalid", 2);
		exit(1);
	}
}

void	error_char_map(t_program *program)
{
	program->counter.p = 0;
	program->counter.c = 0;
	program->counter.e = 0;
	counts(program);
	if (program->counter.p < 1 || program->counter.p > 1)
	{
		ft_putendl_fd("Wrong map, not found character", 2);
		exit(1);
	}
	if (program->counter.c < 1)
	{
		ft_putendl_fd("Wrong map, not found collectable", 2);
		exit(1);
	}
	if (program->counter.e < 1 || program->counter.e > 1)
	{
		ft_putendl_fd("Wrong map, not found exit", 2);
		exit(1);
	}
}

void	check_rectangle(t_program *program)
{
	int	i;

	i = 0;
	while (program->map.map[i])
	{
		if ((int)ft_strlen(program->map.map[i]) != program->map.length)
		{
			printf("The map is no rectangle\n");
			exit (1);
		}
		i++;
	}
}

void	check_ber(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]) - 1;
	if ((argv[1][i] != 'r') || (argv[1][i - 1] != 'e')
		|| (argv[1][i - 2] != 'b') || (argv[1][i - 3] != '.'))
	{
		ft_putendl_fd("The extension is incorrect", 2);
		exit (1);
	}
}
