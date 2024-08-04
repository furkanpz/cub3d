#include "../inc/cub3d.h"

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

int ft_check_variables(char **file, char **file2, t_parse *parse, t_get_file *files)
{
	char **test;

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
	files->map = ft_check_val_ret(file2, parse);
	if (!files->map)
		return (-1);
	return (1);
}
