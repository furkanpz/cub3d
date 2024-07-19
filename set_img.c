#include "inc/cub3d.h"

void ft_put_pixel(t_img *img, int x, int y, char color)
{
	img->data[x + (img->sizeline * y)] = (char)color;
}

void set_img(t_img *img)
{
	int i;
	int c;

	i = 0;
	c = 20;

	while (c < 50)
	{
		while (i < img->sizeline)
		{
			ft_put_pixel(img,i,c,100);
			i++;
		}
		i = 0;
		c++;
	}
}
