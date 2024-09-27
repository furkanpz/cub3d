/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:55:06 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/27 17:20:16 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
