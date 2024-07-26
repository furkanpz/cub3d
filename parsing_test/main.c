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


void ft_check_variables(char **file, t_parse *parse, t_game *cub3d, t_get_file *files)
{
	char **test;
	(void)cub3d;

	parse->c = 0;
	parse->j = 0;
	files->count = 0;
	while (parse->c < parse->i)
	{
		test = ft_split(file[parse->c], ' ');
		if (test[0] && (ft_strchr(test[0], '1') || ft_strchr(test[0], '0')))
			break ;
		while (test[parse->j])
			parse->j++;
		if (parse->j != 2)
		{			
			parse->c++;
			continue;
		}
		if (!ft_strncmp("NO", test[0], ft_strlen(test[0])) && files->no == NULL)
		{
			files->no = test[1];
			files->count += 1;
		}
		if (!ft_strncmp("SO", test[0], ft_strlen(test[0])) && files->so == NULL)
		{
			files->so = test[1];
			files->count += 1;
		}
		if (!ft_strncmp("WE", test[0], ft_strlen(test[0])) && files->we == NULL)
		{
			files->we = test[1];
			files->count += 1;
		}
		if (!ft_strncmp("EA", test[0], ft_strlen(test[0])) && files->ea == NULL)
		{
			files->ea = test[1];
			files->count += 1;
		}
		if (!ft_strncmp("F", test[0], ft_strlen(test[0])) && files->f == NULL)
		{
			files->f = ft_split(test[1],',');
			files->count += 1;
		}
		if (!ft_strncmp("C", test[0], ft_strlen(test[0])) && files->c == NULL)
		{
			files->c = ft_split(test[1],',');
			files->count += 1;
		}
		parse->j = 0;
		parse->c++;
	}
	if (files->count != 6)
	{	
		printf("ERROR!\n");
		return ;
	}
	print_file(files);
}

void init_file(t_get_file *file)
{
	file->so = NULL;
	file->we = NULL;
	file->f = NULL;
	file->c = NULL;
	file->no = NULL;
	file->ea = NULL;
}

void ft_read_cub(char *map, t_game *cub3d)
{
	char **tmp;
	char *temp;
	t_parse parse;
	t_get_file file;

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
	init_file(&file);
	ft_check_variables(tmp, &parse, cub3d, &file);
}
