/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:30:58 by fhosgor           #+#    #+#             */
/*   Updated: 2024/09/20 17:51:21 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define PI		3.14159265358979323846
# define EPSILON	1e-3

typedef enum e_bool
{
	error = -1,
	false,
	true
}	t_bool;

typedef union u_color
{
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	};
	unsigned int	value;
}	t_color;

typedef struct s_img
{
	void	*img;
	t_color	*data;
	int		bits_per_pixel;
	int		size_line;
	int		line_count;
	int		endian;
}	t_img;

typedef struct s_win
{
	void	*win;
	int		width;
	int		height;
}	t_win;

typedef struct s_mlx
{
	void		*mlx;
	t_win		win;
	t_img		img;
	int			time;
}	t_mlx;

typedef union u_vec2i
{
	struct
	{
		int	x;
		int	y;
	};
	int	data[2];
}	t_vec2i;

typedef union u_vec2
{
	struct
	{
		float	x;
		float	y;
	};
	float	data[2];
}	t_vec2;

typedef struct s_draw_line
{
	t_vec2	delta;
	float	inc;
	float	side_check;
	float	x;
	float	y;
}	t_draw_line;


static const t_vec2	g_south = (t_vec2){.x = 0, .y = 1};
static const t_vec2	g_north = (t_vec2){.x = 0, .y = -1};
static const t_vec2	g_east = (t_vec2){.x = -1, .y = 0};
static const t_vec2	g_west = (t_vec2){.x = 1, .y = 0};
static const t_vec2	g_vec2_null = (t_vec2){.x = 0, .y = 0};
static const t_vec2	g_vec2_i = (t_vec2){.x = 1, .y = 0};
static const t_vec2	g_vec2_j = (t_vec2){.x = 0, .y = 1};

float	ft_vec2_mag(t_vec2 vec);
t_vec2	ft_vec2_sub(t_vec2	vec1, t_vec2 vec2);
t_vec2	ft_vec2_mul(t_vec2 vec, float mul);
t_vec2	ft_vec2_add(t_vec2 vec1, t_vec2 vec2);
t_vec2	ft_vec2_inv(t_vec2 vec);
t_vec2	ft_vec2_rot(t_vec2 vec, float deg);
t_vec2	ft_vec2_norm(t_vec2 vec);
t_bool	ft_vec2_equ(t_vec2 vec1, t_vec2 vec2);
float	ft_vec2_dist(t_vec2 point1, t_vec2 point2);
t_vec2	ft_vec2_div(t_vec2 vec, float div);

#endif