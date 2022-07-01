/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:18 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/01 11:51:24 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/* int	map_long()
{
	ft_strlen;
} */

void	check_map(t_map *s_map, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("Error to open map", 2);
	s_map->map = malloc();
}
