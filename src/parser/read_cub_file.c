/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:49:58 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/20 14:37:34 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_file(t_get_file *file)
{
	file->so = NULL;
	file->we = NULL;
	file->f = NULL;
	file->c = NULL;
	file->no = NULL;
	file->ea = NULL;
	file->map = NULL;
	file->map_file = NULL;
}

char	**ft_set_temp_map(t_parse *parse, char *map)
{
	char	**tmp;
	char	*temp;

	parse->i = ft_get_file_size(map);
	parse->fd = open(map, O_RDONLY, 0644);
	parse->k = 0;
	parse->c = 0;
	tmp = malloc(sizeof(char *) * (parse->i + 1));
	while (parse->c < parse->i)
	{
		temp = get_next_line(parse->fd);
		parse->j = ft_strlen(temp);
		if (parse->j > parse->k)
			parse->k = parse->j;
		tmp[parse->c] = ft_strtrim(temp, "\t \n");
		free(temp);
		parse->c++;
	}
	tmp[parse->c] = NULL;
	close(parse->fd);
	return (tmp);
}

char	**ft_set_temp_map_2(t_parse *parse, char *map)
{
	char	**tmp;
	char	*temp;

	parse->c = 0;
	parse->i = ft_get_file_size(map);
	parse->fd = open(map, O_RDONLY, 0644);
	tmp = malloc(sizeof(char *) * (parse->i + 1));
	while (parse->c < parse->i)
	{
		temp = get_next_line(parse->fd);
		tmp[parse->c] = ft_strtrim(temp, "\n");
		free(temp);
		parse->c++;
	}
	tmp[parse->c] = NULL;
	close(parse->fd);
	return (tmp);
}

void	ft_map_join(t_get_file *file)
{
	int		i;
	char	*ret;
	char	*temp;

	i = 0;
	ret = ft_strdup("");
	while (file->map[i])
	{
		temp = ret;
		ret = ft_strjoin(ret, file->map[i]);
		free(temp);
		i++;
	}
	freepchar(file->map);
	file->map = NULL;
	file->map_file = ret;
}

int	ft_read_cub(char *map, t_game *cub3d)
{
	char		**tmp;
	char		**tmp2;
	t_parse		parse;
	t_get_file	file;

	if (ft_check_cub(map) == -1)
		return (-1);
	tmp = ft_set_temp_map(&parse, map);
	file.lmapsize = parse.k + 1;
	file.mapy = parse.i;
	tmp2 = ft_set_temp_map_2(&parse, map);
	init_file(&file);
	if (ft_check_variables(tmp, tmp2, &parse, &file) == -1)
	{
		free_file(&file);
		return (-1);
	}
	if (ft_check_file_struct(&file) == -1)
	{
		free_file(&file);
		return (-1);
	}
	ft_map_join(&file);
	cub3d->file = file;
	return (0);
}
