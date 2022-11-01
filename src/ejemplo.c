void	pathfindrec(t_data *map, int dy, int dx, int **mapint)
{
	if (map->tdm[dy][dx] == 'P' || map->isway == 1)
	{
		map->isway = 1;
		return ;
	}
	if (map->tdm[dy - 1][dx] != '1' && mapint[dy - 1][dx] < 1)
	{
		mapint[dy - 1][dx] = mapint[dy][dx] + 1;
		pathfindrec(map, dy - 1, dx, mapint);
	}
	if (map->tdm[dy + 1][dx] != '1' && mapint[dy + 1][dx] < 1)
	{
		mapint[dy + 1][dx] = mapint[dy][dx] + 1;
		pathfindrec(map, dy + 1, dx, mapint);
	}
	if (map->tdm[dy][dx + 1] != '1' && mapint[dy][dx + 1] < 1)
	{
		mapint[dy][dx + 1] = mapint[dy][dx] + 1;
		pathfindrec(map, dy, dx + 1, mapint);
	}
	if (map->tdm[dy][dx - 1] != '1' && mapint[dy][dx - 1] < 1)
	{
		mapint[dy][dx - 1] = mapint[dy][dx] + 1;
		pathfindrec(map, dy, dx - 1, mapint);
	}
}

void	pathnumber(t_data *map, int dy, int dx)
{
	int	**mapint;
	int	i;
	int	j;

	i = -1;
	mapint = (int **)malloc(sizeof(int *) * map->ymax);
	while (++i < map->ymax)
	{
		mapint[i] = (int *)malloc(sizeof(int) * map->xmax);
		j = -1;
		while (++j < map->xmax)
			mapint[i][j] = 0;
	}
	mapint[dy][dx] = 1;
	pathfindrec(map, dy, dx, mapint);
	i = -1;
	while (++i < map->ymax)
	{
		free(mapint[i]);
	}
	free(mapint);
}

void	pathfind(t_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->tdm[++i])
	{
		j = -1;
		while (map->tdm[i][++j])
		{
			if (map->tdm[i][j] == 'E' || map->tdm[i][j] == 'C')
			{
				map->isway = 0;
				pathnumber(map, i, j);
				if (map->isway != 1)
				{
					if (map->tdm[i][j] == 'E')
						error_printf("No valid path to exit!", map);
					if (map->tdm[i][j] == 'C')
						error_printf("No valid path to coin!", map);
				}
			}
		}
	}
}