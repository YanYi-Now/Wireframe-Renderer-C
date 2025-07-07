#include "../include/mesh.h"

static void	my_mlx_pixel_put(t_mesh *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->pixel_buffer + \
				(y * data->bytes_per_line + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	bresenham(t_mesh *data, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	int		larger_change;
	int		temp;
	t_point	save_p1;

	larger_change = (int) max(mabs(p2.x - p1.x), mabs(p2.y - p1.y));
	x_step = (p2.x - p1.x) / larger_change;
	y_step = (p2.y - p1.y) / larger_change;
	temp = 0;
	save_p1 = p1;
	while ((temp < larger_change))
	{
		my_mlx_pixel_put(data, (int)p1.x, \
						(int)p1.y, color_new_points(p1.x, p1.y, save_p1, p2));
		p1.x += x_step;
		p1.y += y_step;
		temp ++;
	}
}

static t_point	process(t_point p, t_mesh *data)
{
	p.y *= data->zoom;
	p.x *= data->zoom;
	p.z *= data->zoom;
	rotate_x(&p.y, &p.z, data->alpha);
	rotate_y(&p.x, &p.z, data->beta);
	rotate_z(&p.x, &p.y, data->gamma);
	if (data->iso == 1)
		iso_proj(&p.x, &p.y, p.z);
	p.y += (HEIGHT - data->map_height * data->zoom) / 2 + data->shift_y;
	p.x += MENU + (WIDTH - data->map_width * data->zoom) / 2 + data->shift_x;
	return (p);
}

static void	paint_over(t_mesh *data)
{
	int	i;
	int	j;
	int	*img;

	img = (int *)data->pixel_buffer;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (j < MENU)
				img[i * WIDTH + j] = 0x241c38;
			else
				img[i * WIDTH + j] = 0x241c3f;
			j++;
		}
		i++;
	}
}

void	draw_map(t_mesh *data)
{
	int	x;
	int	y;

	paint_over(data);
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (y < data->map_height - 1)
			{
				bresenham(data, process(data->points[y][x], data), \
					process(data->points[y + 1][x], data));
			}
			if (x < data->map_width - 1)
			{
				bresenham(data, process(data->points[y][x], data), \
					process(data->points[y][x + 1], data));
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	draw_menu(data);
}
