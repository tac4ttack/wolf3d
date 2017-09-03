/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:10:48 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 16:20:12 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	vec2_magnitude(t_vec2 vec2)
{
	return (sqrt(vec2.x * vec2.x + vec2.y * vec2.y));
}

void	vec2_normalize(t_vec2 *vec2)
{
	float	magnitude;

	magnitude = vec2_magnitude(*vec2);
	vec2->x /= magnitude;
	vec2->y /= magnitude;
}

t_vec2	vec2_scale(t_vec2 vec2, float scale)
{
	vec2_normalize(&vec2);
	vec2.x *= scale;
	vec2.y *= scale;
	return (vec2);
}

t_vec2	vec2(float x, float y)
{
	t_vec2	vector;

	vector = (t_vec2) { x, y };
	return (vector);
}

t_vec2i	vec2i(t_vec2 vec2)
{
	t_vec2i	vec2i;

	vec2i = (t_vec2i) { (int)vec2.x, (int)vec2.y };
	return (vec2i);
}
