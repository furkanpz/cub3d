/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_variables_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:30:17 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/11 18:30:18 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	**ft_split_2(char *s, char c)
{
	char	**ret;
	int		i;
	char	**ret2;

	i = 0;
	ret = ft_split(s, c);
	while (ret[i])
		i++;
	ret2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (ret[i])
	{
		ret2[i] = ft_strtrim(ret[i], " ");
		i++;
	}
	ret2[i] = NULL;
	freepchar(ret);
	free(s);
	return (ret2);
}

void	ft_check_variables_if(char **test, t_get_file *files)
{
	if (!ft_strncmp_2("NO", test[0]) && files->no == NULL)
		files->no = ft_strdup(test[1]);
	if (!ft_strncmp_2("SO", test[0]) && files->so == NULL)
		files->so = ft_strdup(test[1]);
	if (!ft_strncmp_2("WE", test[0]) && files->we == NULL)
		files->we = ft_strdup(test[1]);
	if (!ft_strncmp_2("EA", test[0]) && files->ea == NULL)
		files->ea = ft_strdup(test[1]);
	if (!ft_strncmp_2("F", test[0]) && files->f == NULL)
		files->f = ft_split_2(ft_strdup(test[1]), ',');
	if (!ft_strncmp_2("C", test[0]) && files->c == NULL)
		files->c = ft_split_2(ft_strdup(test[1]), ',');
	files->count += 1;
}

void	ft_check_var_init(t_parse *parse, t_get_file *files, char ***test)
{
	*test = NULL;
	parse->c = 0;
	parse->j = 0;
	files->count = 0;
}

int	ft_check_variables(char **file, char **file2,
t_parse *parse, t_get_file *files)
{
	char	**test;

	ft_check_var_init(parse, files, &test);
	while (parse->c < parse->i)
	{
		if (freepchar(test) && files->count == 6)
			break ;
		test = ft_split(file[parse->c], ' ');
		if (!test[0] && parse->c++)
			continue ;
		if (ft_check_var_if(test) || ft_check_var_if_2(test, files))
			break ;
		while (test[parse->j])
			parse->j++;
		if (++parse->c && parse->j != 2)
			continue ;
		ft_check_variables_if2(test, files);
		parse->j = 0;
	}
	if (freepchar(file) && files->count != 6 && freepchar(file2))
		return (-1);
	files->map = ft_check_val_ret(file2, parse);
	if (!files->map)
		return (-1);
	return (1);
}
