#include "../include/mesh.h"

static int	get_width(char *path)
{
	int		fd;
	char	*line;
	int		width;
	int		new_num;
	int		k;

	fd = open(path, O_RDONLY, 0);
	line = get_next_line(fd);
	k = -1;
	width = 0;
	new_num = 1;
	while (line[++k])
	{
		if (line[k] != ' ' && new_num)
		{
			width++;
			new_num = 0;
		}
		else if (line[k] == ' ')
			new_num = 1;
	}
	free(line);
	close(fd);
	return (width);
}

static int	get_height(char *path)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	store_coordinates(char *row, t_point **points, int i)
{
	int	j;
	int	k;
	int	new_num;

	j = 0;
	k = 0;
	new_num = 1;
	while (row[k])
	{
		if (row[k] != ' ' && new_num)
		{
			points[i][j].x = (float)j;
			points[i][j].y = (float)i;
			points[i][j].z = (float)ft_atoi(&row[k]);
			j++;
			new_num = 0;
		}
		else if (row[k] == ' ')
			new_num = 1;
		k++;
	}
}

static void	get_points(char *path, t_point **points)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		store_coordinates(line, points, i);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	read_map(char *path, t_mesh *data)
{
	int	i;

	data->map_width = get_width(path);
	data->map_height = get_height(path);
	data->points = (t_point **)malloc(sizeof(t_point *) * data->map_height);
	if (!data->points)
		return (1);
	i = 0;
	while (i < data->map_height)
	{
		data->points[i] = (t_point *)malloc(sizeof(t_point) * data->map_width);
		if (!data->points[i])
			return (1);
		i++;
	}
	get_points(path, data->points);
	return (0);
}
