#include "../inc/cub3d.h"
#include "test.h"

void get_map_size(t_game *cub3d, char *map)
{
	int i;
	char *s;
	int fd;

	i = 0;
	fd = open(map, O_RDONLY, 0644);
	if (fd == -1)
		ft_error_msg(map, 0);
	s = get_next_line(fd);
	if (s)
		cub3d->map.size.x = ft_strlen(s);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	cub3d->map.size.y = i;
	close(fd);
}



void print_file(t_get_file *file)
{
	printf("F: ");
	for (int x = 0; file->f[x]; x++)
		printf("%s ",file->f[x]);
	printf("\n");
	printf("C: ");
	for (int x = 0; file->c[x]; x++)
		printf("%s ",file->c[x]);
	printf("\n");
	printf("EA: %s\n",file->ea);
	printf("NO: %s\n",file->no);
	printf("SO: %s\n",file->so);
	printf("WE: %s\n",file->we);
}

int ft_check_map_4(t_get_file *file)
{
	t_parse p;

	p.i = 0;
	while (file->map[p.i])
	{
		p.c = 0;
		while (file->map[p.i][p.c])
		{
			if (!ft_strchr("10NSEW_",file->map[p.i][p.c]))
				return (-1);
			p.c++;
		}
		p.i++;
	}
	return (0);
}

int ft_check_map_3(t_get_file *file)
{
	t_parse p;

	p.i = 0;
	while (file->map[p.i])
	{
		p.c = 0;
		while (file->map[p.i][p.c])
		{
			if (file->map[p.i][p.c] == '_' && ++p.c)
				continue;
			if (p.i > 0 && ft_strchr("0NSEW",file->map[p.i][p.c])
			&& (file->map[p.i - 1][p.c] == '_' || !ft_strchr("10NSEW",file->map[p.i - 1][p.c])))
				return (-1);
			p.c++;
		}
		p.i++;
	}
	if (ft_check_map_4(file) == -1)
		printf("ERROR3\n");
	return (0);
}

int ft_check_map_2(t_get_file *file)
{
	t_parse p;

	p.i = 0;
	while (file->map[p.i])
	{
		p.c = 0;
		while (file->map[p.i][p.c])
		{
			if (file->map[p.i][p.c] == '_' && ++p.c)
				continue;
			if (p.i == 0 && file->map[p.i][p.c] != '1')
				return (-1);
			if ((p.c == 0 && file->map[p.i][p.c] != '1')
			|| (p.c == (int)ft_strlen(file->map[p.i]) - 1
			&& file->map[p.i][p.c] != '1'))
				return (-1);
			p.c++;
		}
		p.i++;
	}
	if (ft_check_map_3(file) == -1)
		printf("ERROR 2");
	return (0);
}

char *set_new_map_column(char *map, t_get_file *file)
{
	char *ret;
	size_t	dsize;
	size_t	i;
	size_t	c;

	dsize = ft_strlen(map) + 1;
	ret = malloc(sizeof(char) * (file->lmapsize + 2));
	if (!ret)
		return (NULL);
	ret[0] = '_';
	i = 0;
	c = 0;
	while (++i < dsize)
		ret[i] = map[c++];
	while (i < file->lmapsize)
		ret[i++] = '_';
	ret[i] = '\0';
	free(map);
	return (ret);
}
void set_p(t_get_file *file, t_parse *p)
{
	file->pcount += 1;
	file->p.x = p->c;
	file->p.y = p->i;
	file->p.d = file->map[file->p.y][file->p.x];
	file->map[file->p.y][file->p.x] = '0';
}

int ft_check_map(t_get_file *file)
{
	t_parse p;

	p.i = 0;
	file->pcount = 0;
	while (file->map[p.i])
	{
		p.c = 0;
		while (file->map[p.i][p.c])
		{
			if (ft_strlen(file->map[p.i]) < file->lmapsize)
				file->map[p.i] = set_new_map_column(file->map[p.i], file);
			if (file->map[p.i][p.c] == 32)
				file->map[p.i][p.c] = '_';
			if (ft_strchr("NSEW",file->map[p.i][p.c]))
				set_p(file, &p);
			if (!ft_strchr("10NSEW_", file->map[p.i][p.c]))
				return (-1);
			p.c++;
		}
		p.i++;
	}
	file->mapy = p.i;
	file->pmap.y = file->mapy;
	flood_fill(file);
	if (file->pcount != 1 || file->fferror == 1)
		return (-1);
	return (0);
}






