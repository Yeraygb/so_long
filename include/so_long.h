/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:57 by ygonzale          #+#    #+#             */
/*   Updated: 2022/09/13 12:49:20 by ygonzale         ###   ########.fr       */
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
	char	*exit_game;
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

typedef struct s_program
{
	void		*mlx_pointer;
	void		*window;
	char		*line;
	char		*save_x;
	t_map		map;
	t_format	format;
	t_sprites	sprites;
	t_image		floor;
	t_image		wall;
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

//-.-.-.-.-.-.-mlx-.-.-.-.-.-.-//

/*
void	*mlx_new_image(void *mlx_ptr, int width, int height);
void	*mlx_xpm_file_to_image(void *mlx_pointer, char *relative_path, \
		int *width, int *height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, \
		int *endian);
int		mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);
int		mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
int		mlx_key_hook(void *win_ptr, int (*f)(), void *param);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
*/

#endif