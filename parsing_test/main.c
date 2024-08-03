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

void ft_check_variables_if(char **test, t_get_file *files)
{
		if (!ft_strncmp("NO", test[0], ft_strlen(test[0])) && files->no == NULL)
			files->no = test[1];
		if (!ft_strncmp("SO", test[0], ft_strlen(test[0])) && files->so == NULL)
			files->so = test[1];
		if (!ft_strncmp("WE", test[0], ft_strlen(test[0])) && files->we == NULL)
			files->we = test[1];
		if (!ft_strncmp("EA", test[0], ft_strlen(test[0])) && files->ea == NULL)
			files->ea = test[1];
		if (!ft_strncmp("F", test[0], ft_strlen(test[0])) && files->f == NULL)
			files->f = ft_split(test[1],',');
		if (!ft_strncmp("C", test[0], ft_strlen(test[0])) && files->c == NULL)
			files->c = ft_split(test[1],',');
		files->count += 1;
}
void ft_check_variables_if2(char **test, t_get_file *files)
{
	if ((!ft_strncmp("NO", test[0], ft_strlen(test[0])) && files->no == NULL)
	|| (!ft_strncmp("SO", test[0], ft_strlen(test[0])) && files->so == NULL)
	|| (!ft_strncmp("WE", test[0], ft_strlen(test[0])) && files->we == NULL)
	|| (!ft_strncmp("EA", test[0], ft_strlen(test[0])) && files->ea == NULL)
	|| (!ft_strncmp("F", test[0], ft_strlen(test[0])) && files->f == NULL)
	|| (!ft_strncmp("C", test[0], ft_strlen(test[0])) && files->c == NULL)
	)
		ft_check_variables_if(test,files);
}

void ft_check_var_init(t_parse *parse, t_get_file *files)
{
	parse->c = 0;
	parse->j = 0;
	files->count = 0;
}

char **ft_check_val_ret(char **file, t_parse *parse)
{
	char **test;

	test = malloc(sizeof(char *) * ((parse->i - parse->c) + 1));
	if (!test)
		return (NULL);
	parse->j = 0;
	while (parse->c < parse->i)
	{
		test[parse->j] = file[parse->c];
		parse->c++;
		parse->j++;
	}
	test[parse->j] = NULL;
	return (test);
}

int ft_check_var_if(char **test)
{
	if ((test[0] && (ft_strchr(test[0], '1') || ft_strchr(test[0], '0')))
		|| (test[1] && 
		(
			ft_strncmp("NO",test[0], 2) != 0
			&& ft_strncmp("SO",test[0], 2) != 0
			&& ft_strncmp("WE",test[0], 2) != 0
			&& ft_strncmp("EA",test[0], 2) != 0
			&& ft_strncmp("C",test[0], 1) != 0
			&& ft_strncmp("F",test[0], 1) != 0
		)
			&& (ft_strchr(test[1], '1') || ft_strchr(test[1], '0'))))
		return (1);
	return (0);
}

int ft_check_var_if_2(char **test, t_get_file *files)
{
	if (!test[0])
		return (0);
	if ((!ft_strncmp("NO", test[0], ft_strlen(test[0])) && files->no != NULL)
	|| (!ft_strncmp("SO", test[0], ft_strlen(test[0])) && files->so != NULL)
	|| (!ft_strncmp("WE", test[0], ft_strlen(test[0])) && files->we != NULL)
	|| (!ft_strncmp("EA", test[0], ft_strlen(test[0])) && files->ea != NULL)
	|| (!ft_strncmp("F", test[0], ft_strlen(test[0])) && files->f != NULL)
	|| (!ft_strncmp("C", test[0], ft_strlen(test[0])) && files->c != NULL)
	)
		return (1);
	return (0);
}

int ft_check_variables(char **file, t_parse *parse, t_get_file *files)
{
	char **test;
	char **ret;

	ft_check_var_init(parse, files);
	while (parse->c < parse->i)
	{
		if (files->count == 6)
			break;
		test = ft_split(file[parse->c], ' ');
		if (ft_check_var_if(test) || ft_check_var_if_2(test, files))
			break ;
		while (test[parse->j])
			parse->j++;
		if (++parse->c && parse->j != 2)
			continue;
		ft_check_variables_if2(test,files);
		parse->j = 0;
	}
	if (files->count != 6)
		return (-1);
	ret = ft_check_val_ret(file, parse);
	if (!ret)
		return (-1);
	return (1);
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
	(void)cub3d;

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
	if (ft_check_variables(tmp, &parse, &file) == -1)
	{
		printf("Map Error!");
		return ;
	}
	print_file(&file);
}
