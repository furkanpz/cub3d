/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:28:12 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/26 16:28:13 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_deg_to_rad(float deg)
{
	return ((deg / 180) * PI);
}

float	ft_rad_to_deg(float rad)
{
	return (rad * (180 / PI));
}

int	ft_exit(void *cub3d)
{
	t_game	*game;

	game = (t_game *)cub3d;
	mlx_destroy_window(game->mlx.mlx, game->mlx.win.win);
	free_file(&game->file);
	free(game->file.map_file);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	cub3d;

	if (argc != 2)
		return (printf("usage: ./cub3d <MAPPATH>\n"), EXIT_FAILURE);
	if (ft_read_cub(argv[1], &cub3d) == -1)
		ft_error_msg(argv[1], 0);
	init_game(&cub3d);
	mlx_hook(cub3d.mlx.win.win, \
		KeyPress, (1 << 0), key_press_handler, &cub3d);
	mlx_hook(cub3d.mlx.win.win, \
		KeyRelease, (1 << 1), key_release_handler, &cub3d);
	mlx_hook(cub3d.mlx.win.win, \
		Destroy, (1 << 17), ft_exit, &cub3d);
	mlx_loop_hook(cub3d.mlx.mlx, update, &cub3d);
	mlx_loop(cub3d.mlx.mlx);
}
