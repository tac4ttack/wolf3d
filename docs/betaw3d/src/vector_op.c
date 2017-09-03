/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:10:48 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 16:20:06 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vec2_rotate(t_vec2 *vec2, float theta)
{
	t_vec2	vec2t;

	theta *= DEG2RAD;
	vec2t.x = vec2->x * cos(theta) - vec2->y * sin(theta);
	vec2t.y = vec2->x * sin(theta) + vec2->y * cos(theta);
	vec2->x = vec2t.x;
	vec2->y = vec2t.y;
}

t_vec2	vec2_add(t_vec2 vec2_a, t_vec2 vec2_b)
{
	t_vec2	vec2;

	vec2.x = vec2_a.x + vec2_b.x;
	vec2.y = vec2_a.y + vec2_b.y;
	return (vec2);
}

t_vec2	vec2_sub(t_vec2 vec2_a, t_vec2 vec2_b)
{
	t_vec2	vec2;

	vec2.x = vec2_a.x - vec2_b.x;
	vec2.y = vec2_a.y - vec2_b.y;
	return (vec2);
}

t_vec2	vec2_mul(t_vec2 vec2_a, t_vec2 vec2_b)
{
	t_vec2	vec2;

	vec2.x = vec2_a.x * vec2_b.x;
	vec2.y = vec2_a.y * vec2_b.y;
	return (vec2);
}

float	vec2_dot(t_vec2 vec2_a, t_vec2 vec2_b)
{
	return ((vec2_a.x * vec2_b.x + vec2_a.y * vec2_b.y));
}
