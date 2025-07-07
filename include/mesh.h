#ifndef MESH_H
# define MESH_H

# define WIDTH 1200
# define HEIGHT 800
# define MENU 250
# define WINDOW_NAME "Wire Mesh"
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_mesh
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*pixel_buffer;
	int		bits_per_pixel;
	int		bytes_per_line;
	int		endian;
	int		map_width;
	int		map_height;
	t_point	**points;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	int		min_z;
	int		max_z;
	double	zoom;
	int		shift_y;
	int		shift_x;
	double	alpha;
	double	beta;
	double	gamma;
	int		iso;
}	t_mesh;

void	set_zoom(t_mesh *data);
void	color_initial_points(t_mesh *data);
int		read_map(char *path, t_mesh *data);
void	draw_map(t_mesh *data);
void	draw_menu(t_mesh *data);
int		color_new_points(float x, float y, t_point p1, t_point p2);
int		handle_keys(int keysym, t_mesh *data);
int		close_window(t_mesh *data);
void	rotate_x(float *y, float *z, double alpha);
void	rotate_y(float *x, float *z, double beta);
void	rotate_z(float *x, float *y, double gamma);
void	iso_proj(float *x, float *y, float z);
float	mabs(float num);
float	min(float a, float b);
float	max(float a, float b);

#endif
