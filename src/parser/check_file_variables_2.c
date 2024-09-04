#include "../inc/cub3d.h"

char **ft_split_2(char *s, char c)
{
	char **ret;
	int i;
	char **ret2;

	i = 0;
	ret = ft_split(s, c);
	while (ret[i])
		i++;
	ret2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (ret[i])
	{
		ret2[i] = ft_strtrim(ret[i]," ");
		i++;
	}
	ret2[i] = NULL;
	freepchar(ret);
	return (ret2);
}


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
		{
				files->f = ft_split_2(test[1],',');
				printf("f:%s\n",files->f[0]);
		printf("f2:%s\n",files->f[1]);
		}
		if (!ft_strncmp_2("C", test[0]) && files->c == NULL)
		{
			files->c = ft_split_2(test[1],',');
		printf("c:%s\n",files->c[0]);
		printf("c2:%s\n",files->c[1]);
		}
		files->count += 1;
}

void ft_check_var_init(t_parse *parse, t_get_file *files)
{
	parse->c = 0;
	parse->j = 0;
	files->count = 0;
}