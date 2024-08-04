#include "../inc/cub3d.h"

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

void ft_check_var_init(t_parse *parse, t_get_file *files)
{
	parse->c = 0;
	parse->j = 0;
	files->count = 0;
}