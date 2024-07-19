#include "inc/cub3d.h"

void get_mapsize(t_data *cub3d, char *map)
{
	int fd;
	int size;
	char *s;

	fd = open(map, O_RDONLY, 0644);
	if (fd == -1)
	{
		printf("Cub3D : %s: Map reading failed!", map);
		exit(1);
	}
	size = 0;
	s = get_next_line(fd);
	while (s)
	{
		size++;
		free(s);
		s = get_next_line(fd);
	}
	cub3d->mapy = size;
	close (fd);
}

void get_map(t_data *cub3d, char *map)
{
	int fd;
	int i;

	i = 0;
	get_mapsize(cub3d, map);
	fd = open(map, O_RDONLY, 0644);
	cub3d->maps = malloc(sizeof(char *) * (cub3d->mapy + 1));
	while (i < cub3d->mapy)
		cub3d->maps[i++] = get_next_line(fd);
	cub3d->maps[i] = NULL;
}

void get_char_pos(t_data *cub3d)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (cub3d->maps[y])
	{
		while (cub3d->maps[y][x])
		{
			if (ft_strchr("NSEW", cub3d->maps[y][x]))
			{
				cub3d->px = x;
				cub3d->py = y;
				break;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void game_init(t_data *cub3d, t_img *img)
{
	cub3d->mlx = mlx_init();
	cub3d->mwin = mlx_new_window(cub3d->mlx, 1280, 800, "cub3d");
	img->img = mlx_new_image(cub3d->mlx, 1280, 800);
	img->data = mlx_get_data_addr(img->img, &img->bitsp, &img->sizeline, &img->endian);
	cub3d->img = img;
}

int main(int ac, char **av)
{
	t_data cub3d;
	t_img	img;
	
	if (ac != 2)
	{
		printf("usage: ./cub3d mapname.cub");
		exit(1);
	}
	//get_map(&cub3d, av[1]);
	//get_char_pos(&cub3d);
	//game_init(&cub3d, &img);
	//set_img(&img);
	//mlx_put_image_to_window(cub3d.mlx,cub3d.mwin,img.img, 0, 0);
	//mlx_loop(cub3d.mlx);
}