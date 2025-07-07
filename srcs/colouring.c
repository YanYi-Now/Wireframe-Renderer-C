#include "../include/mesh.h"

static void	choose_color(t_point *p, t_mesh *data)
{
	double	percentile;

	if (data->max_z == data->min_z)
		percentile = 1.0;
	else
		percentile = (p->z - data->min_z) / (data->max_z - data->min_z);
	if (percentile <= 0.2)
		p->color = 0x25de1b;
	else if (percentile <= 0.4)
		p->color = 0x8354ca;
	else if (percentile <= 0.6)
		p->color = 0xff6ec9;
	else if (percentile <= 0.8)
		p->color = 0xf84472;
	else
		p->color = 0x6cdcf2;
}

void	color_initial_points(t_mesh *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->points[i][j].z < data->min_z)
				data->min_z = data->points[i][j].z;
			if (data->points[i][j].z > data->max_z)
				data->max_z = data->points[i][j].z;
		}
	}
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
			choose_color(&data->points[i][j], data);
	}
}

int	color_new_points(float x, float y, t_point p1, t_point p2)
{
	int		red;
	int		green;
	int		blue;
	double	portion;

	if ((int)x == p1.x || p1.color == p2.color)
		return (p1.color);
	else if ((int)x == p2.x)
		return (p2.color);
	else
	{
		if (mabs(p2.x - p1.x) > mabs(p2.y - p1.y))
			portion = (x - p1.x) / (p2.x - p1.x);
		else
			portion = (y - p1.y) / (p2.y - p1.y);
		red = (int)(((p1.color >> 16) & 0xFF) * (1 - portion) + \
						((p2.color >> 16) & 0xFF) * (portion));
		green = (int)(((p1.color >> 8) & 0xFF) * (1 - portion) + \
						((p2.color >> 8) & 0xFF) * (portion));
		blue = (int)((p1.color & 0xFF) * (1 - portion) + \
						(p2.color & 0xFF) * (portion));
		return ((red << 16) | (green << 8) | blue);
	}
}
