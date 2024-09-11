/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:24 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/11 18:28:33 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strncmp_2(const char *s1, const char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s1))
		&& !ft_strncmp(s1, s2, ft_strlen(s2)))
		return (0);
	return (1);
}

void	ft_check_variables_if2(char **test, t_get_file *files)
{
	if ((!ft_strncmp_2("NO", test[0]) && files->no == NULL)
		|| (!ft_strncmp_2("SO", test[0]) && files->so == NULL)
		|| (!ft_strncmp_2("WE", test[0]) && files->we == NULL)
		|| (!ft_strncmp_2("EA", test[0]) && files->ea == NULL)
		|| (!ft_strncmp_2("F", test[0]) && files->f == NULL)
		|| (!ft_strncmp_2("C", test[0]) && files->c == NULL)
	)
		ft_check_variables_if(test, files);
}

char	**ft_check_val_ret(char **file, t_parse *parse)
{
	char	**test;

	test = malloc(sizeof(char *) * ((parse->i - parse->c) + 1));
	if (!test)
		return (NULL);
	parse->j = 0;
	while (parse->c < parse->i)
	{
		if (file[parse->c][0] == '\0')
		{
			parse->c++;
			continue ;
		}
		test[parse->j] = tab_to_space(file[parse->c]);
		parse->c++;
		parse->j++;
	}
	test[parse->j] = NULL;
	freepchar(file);
	return (test);
}

int	ft_check_var_if(char **test)
{
	if ((test[0] && (ft_strchr(test[0], '1') || ft_strchr(test[0], '0')))
		|| (test[1]
			&& (ft_strncmp_2("NO", test[0]) != 0
				&& ft_strncmp_2("SO", test[0]) != 0
				&& ft_strncmp_2("WE", test[0]) != 0
				&& ft_strncmp_2("EA", test[0]) != 0
				&& ft_strncmp_2("C", test[0]) != 0
				&& ft_strncmp_2("F", test[0]) != 0)
			&& (ft_strchr(test[1], '1') || ft_strchr(test[1], '0'))))
		return (freepchar(test));
	return (0);
}

int	ft_check_var_if_2(char **test, t_get_file *files)
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
		return (freepchar(test));
	return (0);
}
