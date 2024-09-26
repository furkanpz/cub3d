/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:53:44 by fuyar             #+#    #+#             */
/*   Updated: 2024/09/26 17:21:43 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check_cub(char *str)
{
	int	i;
	int	size;

	i = ft_strlen(str) - 1;
	size = i;
	if (i + 1 < 4)
		return (-1);
	while (i != (size - 4))
	{
		if ((i == size && str[i] != 'b')
			|| (i == size - 1 && str[i] != 'u')
			|| (i == size - 2 && str[i] != 'c')
			|| (i == size - 3 && str[i] != '.'))
			return (-1);
		i--;
	}
	return (1);
}

int	ft_check_fd(t_get_file *file)
{
	int	fd;

	fd = open(file->no, O_RDONLY, 0644);
	if (fd == -1)
		return (fd);
	fd = open(file->so, O_RDONLY, 0644);
	if (fd == -1)
		return (fd);
	fd = open(file->we, O_RDONLY, 0644);
	if (fd == -1)
		return (fd);
	fd = open(file->ea, O_RDONLY, 0644);
	if (fd == -1)
		return (fd);
	return (1);
}

int	ft_atoi_cub(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (999);
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (999);
	return (result * sign);
}

int	ft_check_rgb(t_get_file *file)
{
	int	i;

	i = 0;
	while (file->c[i])
	{
		if (ft_atoi_cub(file->c[i]) > 255 || ft_atoi_cub(file->c[i]) < 0)
			return (-1);
		i++;
	}
	if (i != 3)
		return (-1);
	i = 0;
	while (file->f[i])
	{
		if (ft_atoi_cub(file->f[i]) > 255 || ft_atoi_cub(file->f[i]) < 0)
			return (-1);
		i++;
	}
	if (i != 3)
		return (-1);
	return (0);
}

int	ft_check_file_struct(t_get_file *file)
{
	int x;

	x = 0;
	if (ft_check_fd(file) == -1)
		return (-1);
	if (ft_check_rgb(file) == -1)
		return (-1);
	file->pmap.x = file->lmapsize;
	while (file->map[x])
	{
		if (ft_strlen(file->map[x]) > file->lmapsize)
			file->lmapsize = ft_strlen(file->map[x]);
		x++;
	}
	if (ft_check_map(file) == -1)
		return (-1);
	return (0);
}
