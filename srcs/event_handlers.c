#include "../include/mesh.h"

static void	zoom(int key, t_mesh *data)
{
	if (key == PLUS)
		(data->zoom)++;
	else if (key == MINUS)
		(data->zoom)--;
}

static void	transform(int key, t_mesh *data)
{
	if (key == UP)
		data->shift_y -= 10;
	else if (key == DOWN)
		data->shift_y += 10;
	else if (key == LEFT)
		data->shift_x -= 10;
	else if (key == RIGHT)
		data->shift_x += 10;
}

static void	rotate(int key, t_mesh *data)
{
	if (key == D)
		data->alpha -= 0.05;
	else if (key == A)
		data->alpha += 0.05;
	else if (key == W)
		data->beta -= 0.05;
	else if (key == S)
		data->beta += 0.05;
	else if (key == X)
		data->gamma -= 0.05;
	else if (key == Z)
		data->gamma += 0.05;
}

static void	restore(t_mesh *data)
{
	set_zoom(data);
	data->shift_x = 0;
	data->shift_y = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->iso = 1;
}

int	handle_keys(int keysym, t_mesh *data)
{
	if (keysym == PLUS || keysym == MINUS)
		zoom(keysym, data);
	else if (keysym == RIGHT || keysym == LEFT || keysym == UP \
		|| keysym == DOWN)
		transform(keysym, data);
	else if (keysym == A || keysym == D || keysym == W \
		|| keysym == S || keysym == Z || keysym == X)
		rotate(keysym, data);
	else if (keysym == P)
		data->iso = 0;
	else if (keysym == I)
		data->iso = 1;
	else if (keysym == R)
		restore(data);
	else if (keysym == ESC)
		close_window(data);
	draw_map(data);
	return (0);
}
