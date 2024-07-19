#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include "../lib/libft/libft.h"
#include "../lib/gnl/get_next_line.h"
#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

typedef struct s_img
{
	void *img;
	int endian;
	int sizeline;
	int bitsp;
	int y;
	char *data;
}				t_img;




typedef struct s_data{

	void	*mlx;
	void	*mwin;
	char	**maps;
	int		mapx;
	int		mapy;
	int		px;
	int		py;
	struct s_img *img;

}				t_data;

void ft_put_pixel(t_img *img, int x, int y, char color);
void set_img(t_img *img);

#endif