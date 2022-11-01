
#include "../include/so_long.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

/* void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
} */

void	flood_fill(t_program *program)
{
	fill(program->map.map, size, begin, tab[begin.y][begin.x]);
}

/* void	way(t_program *program)
{
	if (program->map.map[y][x] == '0')
	{

		program->map.way = 1;
	}
	if (program->map.map[y][x] == 'C')
		program->map.way = 1;
	if (program->map.map[y][x] == 'E')
		program->map.way = 1;
	way
}

void	searchingway(t_program *program)
{
	int	x;
	int	y;
	
	x = 0;
	program->map.way == 1;
	while (program->map.map[y])
	{
		y = 0;
		while (program->map.map[y][x])
		{
			if (program->map.map[y][x] == 'P')
				way(program);
			x++;
		}
		y++;
	}
	if (program->map.way == 0)
	{
		ft_putendl_fd("Wrong map: no way", 2);
		exit (0);
	}
} */