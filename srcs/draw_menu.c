#include "../include/mesh.h"

void	draw_menu(t_mesh *data)
{
	int	y;

	y = 0;
	mlx_string_put(data->mlx, data->win, 50, y += 50, 0xFFFFFF, "Menu");
	mlx_string_put(data->mlx, data->win, 50, y += 30, 0xFFFFFF, "Zoom: +  / -");
	mlx_string_put(data->mlx, data->win, 50, y += 30, 0xFFFFFF, \
					"Move: Arrow Keys");
	mlx_string_put(data->mlx, data->win, 50, y += 30, 0xFFFFFF, \
					"Rotate X-Axis: A / D");
	mlx_string_put(data->mlx, data->win, 50, y += 20, 0xFFFFFF, \
					"Rotate Y-Axis: S / W");
	mlx_string_put(data->mlx, data->win, 50, y += 20, 0xFFFFFF, \
					"Rotate Z-Axis: Z / X");
	mlx_string_put(data->mlx, data->win, 50, y += 30, 0xFFFFFF, \
					"Isometric Mode: I");
	mlx_string_put(data->mlx, data->win, 50, y += 20, 0xFFFFFF, \
					"Parallel Mode: P");
	mlx_string_put(data->mlx, data->win, 50, y += 30, 0xFFFFFF, "Restore: R");
	mlx_string_put(data->mlx, data->win, 50, y += 30, 0xFFFFFF, \
					"Close Window: Esc");
}
