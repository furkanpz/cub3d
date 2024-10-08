/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:52:38 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/21 16:19:16 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_fill(t_get_file *file, char **map, size_t row, size_t col)
{
	if (row < 0 || col < 0)
		return ;
	if (row >= file->mapy + 2 || col >= file->lmapsize)
		return ;
	if (map[row][col] == '1' || map[row][col] == 'X')
		return ;
	if (file->fferror == 1)
		return ;
	if (map[row][col] == '_' || !map[row + 1])
	{
		file->fferror = 1;
		return ;
	}
	map[row][col] = 'X';
	f_fill(file, map, row - 1, col);
	f_fill(file, map, row + 1, col);
	f_fill(file, map, row, col - 1);
	f_fill(file, map, row, col + 1);
}

int	freepchar(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
		free(str);
	str = NULL;
	return (1);
}

char	**temp_map_f(t_get_file *file)
{
	char		**temp_map;
	size_t		i;
	size_t		c;

	c = 0;
	temp_map = malloc(sizeof(char *) * (file->mapy + 3));
	if (!temp_map)
		return (NULL);
	i = 0;
	temp_map[0] = malloc(sizeof(char) * (file->lmapsize + 1));
	while (c < file->lmapsize)
		temp_map[0][c++] = '_';
	temp_map[0][c] = '\0';
	c = 1;
	while (file->map[i])
		temp_map[c++] = ft_strdup(file->map[i++]);
	temp_map[c] = malloc(sizeof(char) * (file->lmapsize + 1));
	i = 0;
	while (i < file->lmapsize)
		temp_map[c][i++] = '_';
	temp_map[c][i] = '\0';
	temp_map[c + 1] = NULL;
	return (temp_map);
}

void	flood_fill(t_get_file *file)
{
	char	**temp_map;

	temp_map = temp_map_f(file);
	file->fferror = 0;
	f_fill(file, temp_map, file->p.y + 1, file->p.x);
	freepchar(temp_map);
}
