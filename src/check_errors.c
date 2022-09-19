/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:44:50 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/19 15:15:40 by ygonzale         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (program->map.read[i])
	{
		if (program->map.read[i] == 'P')
			program->counter.p++;
		if (program->map.read[i] == 'C')
			program->counter.c++;
		if (program->map.read[i] == 'E')
			program->counter.e++;
		i++;
	}
}
