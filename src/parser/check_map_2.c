/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:22:13 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/11 18:22:19 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_size(t_game *cub3d, char *map)
{
	int		i;
	char	*s;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY, 0644);
	if (fd == -1)
		ft_error_msg(map, 0);
	s = get_next_line(fd);
	if (s)
		cub3d->map.size.x = ft_strlen(s);
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	cub3d->map.size.y = i;
	close(fd);
}

void	set_p(t_get_file *file, t_parse *p)
{
	file->pcount += 1;
	file->p.x = p->c;
	file->p.y = p->i;
	file->p.d = file->map[file->p.y][file->p.x];
	file->map[file->p.y][file->p.x] = '0';
}
