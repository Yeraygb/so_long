/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:37:36 by ygonzale          #+#    #+#             */
/*   Updated: 2022/12/14 11:26:26 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	do_you_know_the_way(t_program *program)
{
	char	**tempmap;
	int		i;
	int		j;

	i = 0;
	tempmap = malloc(program->map.height +1 * sizeof(char *));
	if (!tempmap)
		return (0);
	while (i < program->map.height)
	{
		j = 0;
		tempmap[i] = malloc (program->map.length + 1 * sizeof(char));
		while (program->map.map[i][j])
		{
			tempmap[i][j] = program->map.map[i][j];
			j++;
		}
		i++;
	}
	if (!check_correct_way(program, tempmap))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (0);
}

int	check_correct_way(t_program *program, char **tempmap)
{
	
}
