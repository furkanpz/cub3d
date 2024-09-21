/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:38:50 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/21 15:50:19 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <time.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "vector.h"
# include "ft_inputs.h"

# define HEIGHT			800
# define WIDTH			800
# define TILE_SIZE		40
# define PLAYER_RAD		6
# define PLAYER_SIZE	0.2
# define MAX_RAY_LENGHT	100

typedef struct s_vector
{
	size_t	type_size;
	size_t	buffer_size;
	size_t	lenght;
	char	buffer[1];
}	t_vector;

typedef struct s_tile_map
{
	char	*tiles;
	t_vec2i	size;
}	t_tile_map;

typedef struct s_player
{
	float	move_speed;
	float	camera_speed;
	t_vec2	pos;
	t_vec2	dir;
}	t_player;

typedef enum e_face
{
	north,
	west,
	south,
	east
}	t_face;

typedef struct s_hit
{
	t_face	face;
	t_vec2	pos;
}	t_hit;

typedef struct s_input
{
	t_bool	w_key;
	t_bool	a_key;
	t_bool	s_key;
	t_bool	d_key;
	t_bool	right_key;
	t_bool	left_key;
	t_bool	esc_key;
}	t_input;

typedef struct s_point
{
	int			x;
	int			y;
	char		d;
}				t_point;

typedef struct s_get_file
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**f;
	char	**c;
	char	**map;
	char	*map_file;
	size_t	lmapsize;
	size_t	mapy;
	size_t	pcount;
	t_point	p;
	t_point	pmap;
	int		fferror;
	int		count;

}				t_get_file;

typedef struct s_game
{
	t_hit		collisions[WIDTH];
	float		coll_deg[WIDTH];
	double		delta_time;
	t_tile_map	map;
	t_player	player;
	t_input		inputs;
	t_img		tex_north;
	t_img		tex_west;
	t_img		tex_south;
	t_img		tex_east;
	t_color		floor;
	t_color		ceil;
	t_mlx		mlx;
	t_mlx		debug;
	t_bool		fl_cntrl;
	t_bool		cl_cntrl;
	t_get_file	file;
}	t_game;

typedef struct s_raycast
{
	float	x;
	float	y;
	int		offset;
	int		step;
	float	dist;
	t_hit	hit;
}	t_raycast;

static const t_color	g_red = (t_color){.value = 0x00ff0000};
static const t_color	g_green = (t_color){.value = 0x0000ff00};
static const t_color	g_blue = (t_color){.value = 0x000000ff};
static const t_color	g_dark_blue = (t_color){.value = 0x0000008b};
static const t_color	g_white = (t_color){.value = 0x00ffffff};
static const t_color	g_black = (t_color){.value = 0x00000000};
static const t_color	g_gray = (t_color){.value = 0x00808080};
static const t_color	g_magenta = (t_color){.value = 0x00ff00ff};
static const t_color	g_cyan = (t_color){.value = 0x0000ffff};
static const t_color	g_yellow = (t_color){.value = 0x00ffff00};

struct s_draw_hlpr
{
	t_game	*cub3d;
	t_img	*tex;
	float	line_height;
	float	tex_x;
	int		index;
};

//---------------------- Debug --------------------------

void	init_debug(t_game *cub3d);
void	draw_tile(t_img *debug, char tile, int x, int y);
void	draw_map(t_game *cub3d);
void	draw_rays(t_game *cub3d);
void	draw_player(t_game *cub3d);
void	debug_point(t_img *img, t_vec2 point);
void	update_debug(t_game *cub3d);

//---------------------- Raycast --------------------------

void	raycast(t_game *cub3d, t_vec2 start, t_vec2 dir, t_hit *out);

//---------------------- Init --------------------------

void	init_game(t_game *cub3d);
void	init_map(t_game *cub3d);

//---------------------- Texture --------------------------

void	rotate_index(t_img *tex);
void	mirror_tex(t_img *tex);
float	get_tex_y(t_img *tex, float i, float height);
void	draw_tex_helper(int *i, float *tex_y, \
	float *full_height, float *line_height);
t_color	*get_tex_data(t_img *tex, float tex_x);

//---------------------- Update --------------------------

int		update(void *param);

//----------------- Bresenham Line Algorithm -----------------------

void	ft_draw_line(t_mlx *dt, t_vec2 pt1, t_vec2 pt2, t_color color);

//----------------------- Draw -----------------

void	draw_background(t_game *cub3d);
void	draw_walls(t_game *cub3d);

//----------------------- Controller -----------------

int		key_press_handler(int keycode, t_game *cub3d);
int		key_release_handler(int keycode, t_game *cub3d);
void	player_movement(t_game *cub3d, t_vec2 dir);
void	player_camera(t_game *cub3d, t_bool rotate_dir);

//----------------------- PARSE --------------------

typedef struct s_parse
{
	int	i;
	int	c;
	int	k;
	int	j;
	int	fd;
}			t_parse;

float	ft_deg_to_rad(float deg);
float	ft_rad_to_deg(float rad);
void	ft_put_pixel(t_img *img, int x, int y, t_color color);
void	ft_fill_img(t_win *win, t_img *img, t_color color);
void	ft_swap_int(int *a, int *b);
float	ft_lerp(float val, float min, float max);
float	ft_normalize(float val, float min, float max);
char	**ft_split_2(char *s, char c);
int		ft_read_cub(char *map, t_game *cub3d);
int		ft_check_variables(char **file, char **file2, \
t_parse *parse, t_get_file *files);
int		ft_get_file_size(char *map);
void	get_map_size(t_game *cub3d, char *map);
void	ft_error_msg(char *av, int type);
void	ft_check_var_init(t_parse *parse, t_get_file *files, char ***test);
void	ft_check_variables_if(char **test, t_get_file *files);
int		ft_check_file_struct(t_get_file *file);
void	flood_fill(t_get_file *file);
int		freepchar(char **str);
int		ft_strncmp_2(const char *s1, const char *s2);
int		ft_check_cub(char *str);
void	print_file(t_get_file *file);
char	*tab_to_space(char *str);
void	set_p(t_get_file *file, t_parse *p);
void	get_map_size(t_game *cub3d, char *map);
void	ft_check_variables_if2(char **test, t_get_file *files);
char	**ft_check_val_ret(char **file, t_parse *parse);
int		ft_check_var_if_2(char **test, t_get_file *files);
int		ft_check_var_if(char **test);
void	free_file(t_get_file *file);
int		ft_check_map(t_get_file *file);
int		ft_exit(void *cub3d);
#endif