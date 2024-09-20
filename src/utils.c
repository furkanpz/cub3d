/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:40:26 by fhosgor           #+#    #+#             */
/*   Updated: 2024/09/20 14:57:22 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
