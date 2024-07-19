#include "../inc/cub3d.h"
#include "test.h"

void ft_error_msg(char *av, int type)
{
	if (type == 0)
	{	
		printf("cub3d: %s: map error!", av);
		exit(1);
	}
}

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

int ft_get_file_size(char *map)
{
	int i;
	char *s;
	int fd;

	i = 0;
	fd = open(map, O_RDONLY, 0644);
	if (fd == -1)
		ft_error_msg(map, 0);
	s = get_next_line(fd);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}


void ft_check_variables(char **file, t_parse *parse, t_game *cub3d)
{
	char **test;
	parse->c = 0;
	parse->j = 0;
	printf("%i\n",parse->i);
	while (parse->c < parse->i)
	{
		test = ft_split(file[parse->c], ' ');
		printf("a\n");
		while (test[parse->j])
			parse->j++;
		if (parse->j >= 3)
			return ;
		if (!ft_strncmp("NO", test[0], ft_strlen(test[0])))
			init_tex(cub3d, &cub3d->tex_north, test[1]);
		if (!ft_strncmp("SO", test[0], ft_strlen(test[0])))
			init_tex(cub3d, &cub3d->tex_south, test[1]);
		if (!ft_strncmp("WE", test[0], ft_strlen(test[0])))
			init_tex(cub3d, &cub3d->tex_west, test[1]);
		if (!ft_strncmp("EA", test[0], ft_strlen(test[0])))
			init_tex(cub3d, &cub3d->tex_east, test[1]);
		parse->j = 0;
		parse->c++;
	}
}

void ft_read_cub(char *map, t_game *cub3d)
{
	char **tmp;
	char *temp;
	t_parse parse;

	parse.c = 0;
	parse.i = ft_get_file_size(map);
	parse.fd = open(map, O_RDONLY, 0644);
	tmp = malloc(sizeof(char *) * (parse.i + 1));
	while (parse.c < parse.i)
	{
		temp = get_next_line(parse.fd);
		tmp[parse.c] = ft_strtrim(temp,"\t \n");
		free(temp);
		parse.c++;
	}
	tmp[parse.c] = NULL;
	close(parse.fd);
	ft_check_variables(tmp, &parse, cub3d);
}
