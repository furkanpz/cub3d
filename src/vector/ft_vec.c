#include "cub3d.h"

float	ft_deg_to_rad(float deg)
{
	return ((deg / 180) * PI);
}


float	ft_vec2_dist(t_vec2 point1, t_vec2 point2)
{
	float	dist_x;
	float	dist_y;

	dist_x = fabs(point1.x - point2.x);
	dist_y = fabs(point1.y - point2.y);
	return (sqrtf(powf(dist_x, 2) + powf(dist_y, 2)));
}

float	ft_vec2_mag(t_vec2 vec)
{
	t_vec2	vec_null;

	vec_null.x = 0;
	vec_null.y = 0;
	return (ft_vec2_dist(vec_null, vec));
}

t_vec2	ft_vec2_sub(t_vec2	vec1, t_vec2 vec2)
{
	t_vec2	vec_res;

	vec_res.x = vec1.x - vec2.x;
	vec_res.y = vec1.y - vec2.y;
	return (vec_res);
}

t_vec2	ft_vec2_mul(t_vec2 vec, float mul)
{
	t_vec2	vec_res;

	vec_res.x = vec.x * mul;
	vec_res.y = vec.y * mul;
	return (vec_res);
}

t_vec2	ft_vec2_add(t_vec2 vec1, t_vec2 vec2)
{
	t_vec2	vec_res;

	vec_res.x = vec1.x + vec2.x;
	vec_res.y = vec1.y + vec2.y;
	return (vec_res);
}
t_vec2	ft_vec2_inv(t_vec2 vec)
{
	t_vec2	vec2_res;

	vec2_res.x = -vec.x;
	vec2_res.y = -vec.y;
	return (vec2_res);
}

float	ft_rad_to_deg(float rad)
{
	return (rad * (180 / PI));
}


t_vec2	ft_vec2_rot(t_vec2 vec, float deg)
{
	t_vec2	res;
	float	rad;

	rad = ft_deg_to_rad(deg);
	res.x = ((vec.x * cos(rad)) - (vec.y * sin(rad)));
	res.y = ((vec.x * sin(rad)) + (vec.y * cos(rad)));
	return (res);
}

t_vec2	ft_vec2_div(t_vec2 vec, float div)
{
	t_vec2	vec_res;

	if (div == 0)
		return ((t_vec2){.x = 0, .y = 0});
	vec_res.x = vec.x / div;
	vec_res.y = vec.y / div;
	return (vec_res);
}


t_vec2	ft_vec2_norm(t_vec2 vec)
{
	return (ft_vec2_div(vec, ft_vec2_mag(vec)));
}

void	ft_put_pixel(t_img *img, int x, int y, t_color color)
{
	img->data[x + (img->size_line * y)] = color;
}


void	ft_fill_img(t_win *win, t_img *img, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < win->width)
	{
		j = 0;
		while (j < win->height)
		{
			ft_put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

t_bool	ft_vec2_equ(t_vec2 vec1, t_vec2 vec2)
{
	if (fabs(vec1.x) - fabs(vec2.x) < EPSILON
		&& fabs(vec1.y) - fabs(vec2.y) < EPSILON)
		return (true);
	return (false);
}

void	ft_swap_int(int *a, int *b)
{
	if (a == b)
		return ;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

float	ft_lerp(float val, float min, float max)
{
	return ((val * (max - min)) + min);
}

float	ft_normalize(float val, float min, float max)
{
	if (max == min)
		return (1);
	return ((val - min) / (max - min));
}
