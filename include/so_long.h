/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:57 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/20 10:28:57 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../minilibx/mlx.h"
# include "get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
	int		lines;
	char	*read;
}	t_map;

typedef struct s_format
{
	void	*format;
}	t_format;

typedef struct s_sprites
{
	char	*pj;
	char	*wall;
	char	*floor;
	char	*collect;
	char	*exit;
}	t_sprites;

typedef struct s_image
{
	void		*pointer;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}	t_image;

typedef struct s_counter
{
	int	p;
	int	c;
	int	e;
	int	move_count;
	int	collec_count;
}	t_counter;

typedef struct s_program
{
	void		*mlx_pointer;
	void		*window;
	char		*line;
	char		*save_x;
	int			fd;
	int			count;
	int			position_x;
	int			position_y;
	t_map		map;
	t_format	format;
	t_sprites	sprites;
	t_image		floor;
	t_image		wall;
	t_image		pj;
	t_image		collect;
	t_image		exit;
	t_counter	counter;
}	t_program;

void	check_argc_errors(int argc);
void	ft_map(t_program *program, char **argv);
void	free_double_array(char **trash);
int		count_lines(char **argv, t_program *program);
void	check_map(t_program *program, char **argv);
char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);
void	get_sprites(t_program *program);
void	save_images(t_program *program);
void	sprites_to_windows(t_program *program, int x, int y);
int		teclas_hooks(int keycode, t_program *program);
void	exit_program(t_program *program);
int		horizontal(int keycode, t_program *program);
int		vertical(int keycode, t_program *program);
int		move(t_program *program, int x, int y);
void	error_map(t_program *program);
void	counts(t_program *program);

#endif