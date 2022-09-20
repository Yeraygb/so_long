/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:50 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/19 15:51:54 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_argc_errors(int argc)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_putendl_fd("Number of argument invalid\n", 2);
		exit(1);
	}
}

void	error_map(t_program *program)
{
	program->counter.p = 0;
	program->counter.c = 0;
	program->counter.e = 0;
	counts(program);
	if (program->counter.p < 1 || program->counter.p > 1)
	{
		printf("Wrong map, not found character\n");
		exit(1);
	}
	if (program->counter.c < 1)
	{
		printf("Wrong map, not found collectable\n");
		exit(1);
	}
	if (program->counter.e < 1)
	{
		printf("Wrong map, not found exit\n");
		exit(1);
	}
}
