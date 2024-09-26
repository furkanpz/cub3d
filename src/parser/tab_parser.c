/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:48:13 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/26 16:37:47 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_file(t_get_file *file)
{
	if (file->no)
		free(file->no);
	if (file->so)
		free(file->so);
	if (file->we)
		free(file->we);
	if (file->ea)
		free(file->ea);
	if (file->f)
		freepchar(file->f);
	if (file->c)
		freepchar(file->c);
	if (file->map)
		freepchar(file->map);
}

static int	stc(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			count++;
		i++;
	}
	return (count);
}

static void	init_int(int *i, int *j, int *c)
{
	*i = 0;
	*j = 0;
	*c = 0;
}

void	set_str(char *new_str, int *c, int *j)
{
	if (*c == 1)
		while (*j % 4 != 0)
			new_str[(*j)++] = ' ';
	else if (*c == 0)
	{
		while (*c < 4)
		{
			new_str[(*j)++] = ' ';
			*c += 1;
		}
	}
	*c = 0;
}

char	*tab_to_space(char *str)
{
	int		i;
	int		j;
	int		c;
	char	*new_str;
	char	*trim_str;

	init_int(&i, &j, &c);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + (stc(str) * 3) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\t')
			set_str(new_str, &c, &j);
		else
		{
			c = 1;
			new_str[j++] = str[i];
		}
		i++;
	}
	new_str[j] = '\0';
	trim_str = ft_strtrim(new_str, "\n");
	free(new_str);
	return (trim_str);
}
