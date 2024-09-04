#ifndef CUB3D_H
# define CUB3D_H

# include <time.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line_bonus.h"
# include "libft.h"

# define HEIGHT			800
# define WIDTH			800
# define TILE_SIZE		40
# define PLAYER_RAD		6
# define PLAYER_SIZE	0.2
# define MAX_RAY_LENGHT	100

typedef union u_vec2i
{
	struct
	{
		int	x;
		int	y;
	};
	int	data[2];
}	t_vec2i;

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

typedef struct s_get_file{
	char *no;
	char *so;
	char *we;
	char *ea;
	char **f;
	char **c;
	char **map;
	char *map_file;
	size_t	lmapsize;
	size_t mapy;
	size_t pcount;
	t_point p;
	t_point pmap;
	int fferror;
	int count;

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

struct s_draw_hlpr
{
	t_game	*cub3d;
	t_img	*tex;
	float	line_height;
	float	tex_x;
	int		index;
};

static const t_vec2	g_south = (t_vec2){.x = 0, .y = 1};
static const t_vec2	g_north = (t_vec2){.x = 0, .y = -1};
static const t_vec2	g_east = (t_vec2){.x = -1, .y = 0};
static const t_vec2	g_west = (t_vec2){.x = 1, .y = 0};

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
void	draw_tex_helper(int *i, float *tex_y,
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

//----------------------- Map -----------------
int	take_all_things_from_doc(t_game *cub3d);
int	control_names_and_values(char *sub, t_game *cub3d);

//----------------------- PARSE --------------------

typedef struct s_parse{

	int i;
	int c;
	int k;
	int j;
	int fd;

}			t_parse;

char	**ft_split_2(char *s, char c);
int		ft_read_cub(char *map, t_game *cub3d);
int		ft_check_variables(char **file, char **file2, t_parse *parse, t_get_file *files);
int		ft_get_file_size(char *map);
void	get_map_size(t_game *cub3d, char *map);
void	ft_error_msg(char *av, int type);
void	ft_check_var_init(t_parse *parse, t_get_file *files);
void	ft_check_variables_if(char **test, t_get_file *files);
int		ft_check_map(t_get_file *file);
int		ft_check_file_struct(t_get_file *file);
void	flood_fill(t_get_file *file);
void	freepchar(char **str);
int		ft_strncmp_2(const char *s1, const char *s2);

#endif
