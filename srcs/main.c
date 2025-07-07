#include "../include/mesh.h"

static void	init_data(t_mesh *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->zoom = 1;
	data->shift_x = 0;
	data->shift_y = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->iso = 1;
	data->min_z = 2147483647;
	data->max_z = -2147483648;
}

void	set_zoom(t_mesh *data)
{
	float	numerator;
	float	denominator;

	numerator = HEIGHT / data->map_height / 2;
	denominator = WIDTH / data->map_width / 2;
	data->zoom = min(numerator, denominator);
	if (data->zoom < 4)
		data->zoom = 2.5;
}

int	close_window(t_mesh *data)
{
	int		i;

	if (data->points)
	{
		i = 0;
		while (i < data->map_height)
		{
			free(data->points[i]);
			i++;
		}
		free(data->points);
	}
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data)
		free(data);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mesh	*data;

	(void)argc;
	data = malloc(sizeof(t_mesh));
	init_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel_buffer = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->bytes_per_line, &data->endian);
	read_map(argv[1], data);
	set_zoom(data);
	color_initial_points(data);
	draw_map(data);
	mlx_key_hook(data->win, handle_keys, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}
