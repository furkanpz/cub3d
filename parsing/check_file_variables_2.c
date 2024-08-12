#include "../inc/cub3d.h"

void ft_check_variables_if(char **test, t_get_file *files)
{
		if (!ft_strncmp_2("NO", test[0]) && files->no == NULL)
			files->no = test[1];
		if (!ft_strncmp_2("SO", test[0]) && files->so == NULL)
			files->so = test[1];
		if (!ft_strncmp_2("WE", test[0]) && files->we == NULL)
			files->we = test[1];
		if (!ft_strncmp_2("EA", test[0]) && files->ea == NULL)
			files->ea = test[1];
		if (!ft_strncmp_2("F", test[0]) && files->f == NULL)
			files->f = ft_split(test[1],',');
		if (!ft_strncmp_2("C", test[0]) && files->c == NULL)
			files->c = ft_split(test[1],',');
		files->count += 1;
}

void ft_check_var_init(t_parse *parse, t_get_file *files)
{
	parse->c = 0;
	parse->j = 0;
	files->count = 0;
}