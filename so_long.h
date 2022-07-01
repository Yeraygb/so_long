/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:57 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/01 11:53:32 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# define BUFFER_SIZE 1

typedef struct s_map
{
	char	**map;
	ssize_t	fd;
	int		row;
	int		col;
}	t_map;

void	ft_putendl_fd(char *s, int fd);
void	check_errors(int argc, char **argv);
void	create_map(t_map *s_map, char **argv);
size_t	ft_strlen(const char *str);

#endif