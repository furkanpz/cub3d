/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:39:35 by fhosgor           #+#    #+#             */
/*   Updated: 2024/09/20 14:45:29 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	ft_vec2_inv(t_vec2 vec)
{
	t_vec2	vec2_res;

	vec2_res.x = -vec.x;
	vec2_res.y = -vec.y;
	return (vec2_res);
}

t_vec2	ft_vec2_rot(t_vec2 vec, float deg)
{
	t_vec2	res;
	float	rad;

	rad = ft_deg_to_rad(deg);
	res.x = ((vec.x * cos(rad)) - (vec.y * sin(rad)));
	res.y = ((vec.x * sin(rad)) + (vec.y * cos(rad)));
	return (res);
}

t_vec2	ft_vec2_div(t_vec2 vec, float div)
{
	t_vec2	vec_res;

	if (div == 0)
		return ((t_vec2){.x = 0, .y = 0});
	vec_res.x = vec.x / div;
	vec_res.y = vec.y / div;
	return (vec_res);
}

t_vec2	ft_vec2_norm(t_vec2 vec)
{
	return (ft_vec2_div(vec, ft_vec2_mag(vec)));
}

t_bool	ft_vec2_equ(t_vec2 vec1, t_vec2 vec2)
{
	if (fabs(vec1.x) - fabs(vec2.x) < EPSILON
		&& fabs(vec1.y) - fabs(vec2.y) < EPSILON)
		return (true);
	return (false);
}
