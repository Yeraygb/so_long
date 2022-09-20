/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:01:08 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/20 12:07:40 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include<unistd.h>

void	free_double_array(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

void	counts(t_program *program)
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
		if (program->map.read[i] != 'P' && program->map.read[i] != 'C' \
			&& program->map.read[i] != 'E' && program->map.read[i] != '0' \
			&& program->map.read[i] != '1' && program->map.read[i] != '\n')
		{
			printf("Wrong map\n");
			exit(1);
		}
		i++;
	}
}

int	check_collects(t_program *program)
{
	if (program->counter.collec_count == program->counter.c)
		return (1);
	return (0);
}
