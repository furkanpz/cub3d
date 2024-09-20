/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:41:35 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/20 14:22:47 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"




float	ft_map(float val, t_map map)
{
	return (ft_lerp(ft_normalize(val, map.min_i, map.min_o),
			map.min_o, map.max_o));
}

t_map	ft_map_init(float min_i, float max_i, float min_o, float max_o)
{
	t_map	map;

	map.max_i = max_i;
	map.max_o = max_o;
	map.min_i = min_i;
	map.min_o = min_o;
	return (map);
}
