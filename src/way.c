/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:37:36 by ygonzale          #+#    #+#             */
/*   Updated: 2022/12/15 10:57:54 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		count;
	char	*s2;

	count = 0;
	while (s1[count])
		count++;
	s2 = malloc(sizeof(char) * (count + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	player_postion(t_program *program, t_variables *variables)
{
	int	i;
	int	j;

	i = 0;
	while (program->map.map[i])
	{
		j = 0;
		while (program->map.map[i][j])
		{
			if (program->map.map[i][j] == 'P')
			{
				variables->x = j;
				variables->y = i;
			}
			j++;
		}
		i++;
	}
}

void	freetheway(char **tempmap)
{
	int	i;

	i = 0;
	while (tempmap[i])
	{
		free(tempmap[i]);
		i++;
	}
	free(tempmap);
}

int	do_you_know_the_way(t_program *program)
{
	t_variables	variables;
	char		**tempmap;
	int			i;

	tempmap = malloc((program->map.height + 1) * sizeof(char *));
	if (!tempmap)
		return (0);
	i = 0;
	while (program->map.map[i])
	{
		tempmap[i] = ft_strdup(program->map.map[i]);
		i++;
	}
	tempmap[i] = 0;
	player_postion(program, &variables);
	if (!way(program, tempmap, variables.y, variables.x))
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	freetheway(tempmap);
	return (1);
}

int	way(t_program *program, char **temp, int y, int x)
{
	static int	collectable = 0;
	static int	count_exit = 0;

	if (temp[y][x] == 'E')
	{
		temp[y][x] = '?';
		count_exit++;
	}
	if (count_exit == 1 && collectable == program->counter.c)
		return (1);
	else
	{
		if (temp[y][x] != '1' && temp[y][x] != '?' && temp[y][x] != 'E')
		{
			if (temp[y][x] == 'C')
				collectable++;
			temp[y][x] = '?';
			if (way(program, temp, y + 1, x) || way(program, temp, y + 1, x) \
				|| way(program, temp, y - 1, x) || way(program, temp, y, x + 1) \
				|| way(program, temp, y, x - 1))
				return (1);
		}
	}
	return (0);
}
