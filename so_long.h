/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:57 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/01 16:35:58 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
# define BUFFER_SIZE 1

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	t_map	map;
}	t_game;

void	ft_putendl_fd(char *s, int fd);
void	check_errors(int argc, char **argv);
void	ft_map(t_game *game, char **argv);
size_t	ft_strlen(const char *str);

#endif