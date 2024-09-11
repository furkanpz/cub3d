/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:06 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/11 18:22:47 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// BURA BAKILACAK!!

// int	ft_check_map_4(t_get_file *file)
// {
// 	t_parse	p;

// 	p.i = 0;
// 	while (file->map[p.i])
// 	{
// 		p.c = 0;
// 		while (file->map[p.i][p.c])
// 		{
// 			if (!ft_strchr("10NSEW_", file->map[p.i][p.c]))
// 				return (-1);
// 			p.c++;
// 		}
// 		p.i++;
// 	}
// 	return (0);
// }

// int	ft_check_map_3(t_get_file *file)
// {
// 	t_parse	p;

// 	p.i = 0;
// 	while (file->map[p.i])
// 	{
// 		p.c = 0;
// 		while (file->map[p.i][p.c])
// 		{
// 			if (file->map[p.i][p.c] == '_' && ++p.c)
// 				continue;
// 			if (p.i > 0 && ft_strchr("0NSEW", file->map[p.i][p.c])
// 			&& (file->map[p.i - 1][p.c] == '_'
// 			|| !ft_strchr("10NSEW",file->map[p.i - 1][p.c])))
// 				return (-1);
// 			p.c++;
// 		}
// 		p.i++;
// 	}
// 	if (ft_check_map_4(file) == -1)
// 		return (-1);
// 	return (0);
// }

// int ft_check_map_2(t_get_file *file)
// {
// 	t_parse p;

// 	p.i = 0;
// 	while (file->map[p.i])
// 	{
// 		p.c = 0;
// 		while (file->map[p.i][p.c])
// 		{
// 			if (file->map[p.i][p.c] == '_' && ++p.c)
// 				continue;
// 			if (p.i == 0 && file->map[p.i][p.c] != '1')
// 				return (-1);
// 			if ((p.c == 0 && file->map[p.i][p.c] != '1')
// 			|| (p.c == (int)ft_strlen(file->map[p.i]) - 1
// 			&& file->map[p.i][p.c] != '1'))
// 				return (-1);
// 			p.c++;
// 		}
// 		p.i++;
// 	}
// 	if (ft_check_map_3(file) == -1)
// 		return (-1);
// 	return (0);
// }

char	*set_new_map_column(char *map, t_get_file *file)
{
	char	*ret;
	size_t	dsize;
	size_t	i;
	size_t	c;

	dsize = ft_strlen(map) + 1;
	ret = malloc(sizeof(char) * (file->lmapsize + 2));
	if (!ret)
		return (NULL);
	ret[0] = '_';
	i = 0;
	c = 0;
	while (++i < dsize)
		ret[i] = map[c++];
	while (i < file->lmapsize)
		ret[i++] = '_';
	ret[i] = '\0';
	free(map);
	return (ret);
}

int	ft_check_map(t_get_file *file)
{
	t_parse	p;

	p.i = -1;
	file->pcount = 0;
	while (file->map[++p.i])
	{
		p.c = -1;
		while (file->map[p.i][++p.c])
		{
			if (ft_strlen(file->map[p.i]) < file->lmapsize)
				file->map[p.i] = set_new_map_column(file->map[p.i], file);
			if (file->map[p.i][p.c] == 32)
				file->map[p.i][p.c] = '_';
			if (ft_strchr("NSEW", file->map[p.i][p.c]))
				set_p(file, &p);
			if (!ft_strchr("10NSEW_", file->map[p.i][p.c]))
				return (-1);
		}
	}
	file->mapy = p.i;
	file->pmap.y = file->mapy;
	flood_fill(file);
	if (file->pcount != 1 || file->fferror == 1)
		return (-1);
	return (0);
}
