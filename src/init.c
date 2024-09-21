/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:36:34 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/21 15:53:46 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_game *cub3d)
{
	cub3d->player.pos.x = (float)cub3d->file.p.x + 0.4;
	cub3d->player.pos.y = (float)cub3d->file.p.y + 0.4;
	if (cub3d->file.p.d == 'S')
		cub3d->player.dir = g_south;
	if (cub3d->file.p.d == 'N')
		cub3d->player.dir = g_north;
	if (cub3d->file.p.d == 'E')
		cub3d->player.dir = g_east;
	if (cub3d->file.p.d == 'W')
		cub3d->player.dir = g_west;
	cub3d->player.move_speed = 10;
	cub3d->player.camera_speed = 100;
}

void	init_map(t_game *cub3d)
{
	cub3d->map.size.x = cub3d->file.lmapsize;
	cub3d->map.size.y = cub3d->file.mapy;
	cub3d->map.tiles = cub3d->file.map_file;
	if (cub3d->map.tiles == NULL)
	{
		printf("cub3d: MLX Texture Error\n");
		exit(EXIT_FAILURE);
	}
}

static void	init_tex(t_game *cub3d, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub3d->mlx.mlx, path,
			&tex->size_line, &tex->line_count);
	if (tex->img == NULL)
	{
		printf("cub3d: MLX Texture Error\n");
		exit(EXIT_FAILURE);
	}
	tex->data = (t_color *)mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
	tex->size_line /= (tex->bits_per_pixel / 8);
	rotate_index(tex);
}

void	init_win(t_game *cub3d)
{
	if (cub3d->mlx.mlx == NULL)
		exit(EXIT_FAILURE);
	cub3d->mlx.win.height = HEIGHT;
	cub3d->mlx.win.width = WIDTH;
	cub3d->mlx.win.win = mlx_new_window(cub3d->mlx.mlx,
			WIDTH, HEIGHT, "cub3d - game");
	if (cub3d->mlx.win.win == NULL)
		exit(EXIT_FAILURE);
	cub3d->mlx.img.img = mlx_new_image(cub3d->mlx.mlx,
			cub3d->mlx.win.width, cub3d->mlx.win.height);
	cub3d->mlx.img.data = (t_color *)mlx_get_data_addr(cub3d->mlx.img.img,
			&cub3d->mlx.img.bits_per_pixel,
			&cub3d->mlx.img.size_line, &cub3d->mlx.img.endian);
	cub3d->mlx.img.size_line /= 4;
}

void	init_game(t_game *cub3d)
{
	cub3d->inputs = (t_input){0};
	cub3d->mlx.mlx = mlx_init();
	cub3d->floor = (t_color){.red = ft_atoi(cub3d->file.f[0]), \
	.green = ft_atoi(cub3d->file.f[1]), \
	.blue = ft_atoi(cub3d->file.f[2])};
	cub3d->ceil = (t_color){.red = ft_atoi(cub3d->file.c[0]), \
	.green = ft_atoi(cub3d->file.c[1]), \
	.blue = ft_atoi(cub3d->file.c[2])};
	init_tex(cub3d, &cub3d->tex_south, cub3d->file.so);
	init_tex(cub3d, &cub3d->tex_west, cub3d->file.we);
	init_tex(cub3d, &cub3d->tex_north, cub3d->file.no);
	init_tex(cub3d, &cub3d->tex_east, cub3d->file.ea);
	mirror_tex(&cub3d->tex_north);
	mirror_tex(&cub3d->tex_east);
	init_win(cub3d);
	init_player(cub3d);
	init_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx, cub3d->mlx.win.win,
		cub3d->mlx.img.img, 0, 0);
	mlx_do_key_autorepeatoff(cub3d->mlx.mlx);
}
