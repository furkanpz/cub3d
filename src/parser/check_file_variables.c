#include "../inc/cub3d.h"

int ft_strncmp_2(const char *s1, const char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s1))
	&& !ft_strncmp(s1, s2, ft_strlen(s2)))
		return (0);
	return (1);
}

void ft_check_variables_if2(char **test, t_get_file *files)
{
	if ((!ft_strncmp_2("NO", test[0]) && files->no == NULL)
	|| (!ft_strncmp_2("SO", test[0]) && files->so == NULL)
	|| (!ft_strncmp_2("WE", test[0]) && files->we == NULL)
	|| (!ft_strncmp_2("EA", test[0]) && files->ea == NULL)
	|| (!ft_strncmp_2("F", test[0]) && files->f == NULL)
	|| (!ft_strncmp_2("C", test[0]) && files->c == NULL)
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
		if (file[parse->c][0] == '\0')
		{
			parse->c++;
			continue;
		}
		test[parse->j] = ft_strtrim(file[parse->c], "\n");
		parse->c++;
		parse->j++;
	}
	test[parse->j] = NULL;
	freepchar(file);
	return (test);
}

int ft_check_var_if(char **test)
{
	if ((test[0] && (ft_strchr(test[0], '1') || ft_strchr(test[0], '0')))
		|| (test[1] && 
		(
			ft_strncmp_2("NO",test[0]) != 0
			&& ft_strncmp_2("SO",test[0]) != 0
			&& ft_strncmp_2("WE",test[0]) != 0
			&& ft_strncmp_2("EA",test[0]) != 0
			&& ft_strncmp_2("C",test[0]) != 0
			&& ft_strncmp_2("F",test[0]) != 0
		)
			&& (ft_strchr(test[1], '1') || ft_strchr(test[1], '0'))))
		{
			freepchar(test);
			return (1);
		}
	return (0);
}




int ft_check_var_if_2(char **test, t_get_file *files)
{
	if (!test[0])
		return (0);
	if ((!ft_strncmp_2("NO", test[0]) && files->no != NULL)
	|| (!ft_strncmp_2("SO", test[0]) && files->so != NULL)
	|| (!ft_strncmp_2("WE", test[0]) && files->we != NULL)
	|| (!ft_strncmp_2("EA", test[0]) && files->ea != NULL)
	|| (!ft_strncmp_2("F", test[0]) && files->f != NULL)
	|| (!ft_strncmp_2("C", test[0]) && files->c != NULL)
	)
	{
		freepchar(test);
		return (1);
	}
	return (0);
}

void ft_variables_free(t_get_file *files)
{
	printf("NO\n");
	if (files->no)
		free(files->no);
	printf("SO\n");
	if (files->so)
		free(files->so);
	printf("WE\n");
	if (files->we)
		free(files->we);
	if (files->ea)
		free(files->ea);
	printf("EA\n");
	if (files->f)
		freepchar(files->f);
	if (files->c)
		freepchar(files->c);
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
		if (!test[0])
		{
			parse->c++;
			freepchar(test);
			continue;
		}
		if (ft_check_var_if(test) || ft_check_var_if_2(test, files))
			break ;
		while (test[parse->j])
			parse->j++;
		if (++parse->c && parse->j != 2)
		{
			freepchar(test);
			continue;
		}
		ft_check_variables_if2(test,files);
		parse->j = 0;
		freepchar(test);
	}
	freepchar(file);
	if (files->count != 6)
	{
		freepchar(file2);
		return (-1);
	}
	files->map = ft_check_val_ret(file2, parse);
	if (!files->map)
		return (-1);
	return (1);
}
