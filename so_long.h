/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:57 by ygonzale          #+#    #+#             */
/*   Updated: 2022/07/08 15:10:09 by ygonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# define BUFFER_SIZE 1

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
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
	t_map		*map;
	t_format	*format;
	t_image		*floor;
	t_image		*wall;
}	t_program;

void	check_errors(int argc);
void	ft_map(t_program *program, char **argv);
void	free_double_array(char **trash);
int		count_lines(char **argv);
void	check_map(t_program *program, char **argv);
void	get_sprites(t_program *program);

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