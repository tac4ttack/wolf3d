/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:04:02 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:32:14 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

float		ft_get_ray_horizon(t_data *e, float angle)
{
	t_ray	r;

	if (angle <= 180 && angle >= 0)
	{
		r.ya = -64.0;
		r.point_y = floor(e->pos.Py / 64.0) * (64.0) - 0.000001;
	}
	else
	{
		r.ya = 64.0;
		r.point_y = floor(e->pos.Py / 64.0) * (64.0) + 64.0;
	}
	r.point_x = e->pos.Px + (e->pos.Py - r.point_y) / tan(ft_get_radian(angle));
	r.xa = (-r.ya) / tan(ft_get_radian(angle));
	r.x = (int)floor(r.point_x / 64);
	r.y = (int)floor(r.point_y / 64);
	while ((r.y >= 0 && r.y < e->y_max && r.x >= 0 && r.x < e->x_max)
		   && e->map[r.y][r.x] == 0)
	{
		r.point_y = r.point_y + r.ya;
		r.point_x = r.point_x + r.xa;
		r.x = (int)floor(r.point_x / 64);
		r.y = (int)floor(r.point_y / 64);
	}
	return (fabs((e->pos.Py - r.point_y) / sin(ft_get_radian(angle))));
}

float		ft_get_ray_vertical(t_data *e, float angle)
{
	t_ray	r;

	if (angle >= 90 && angle <= 270)
	{
		r.point_x = floor(e->pos.Px / 64.0) * (64.0) - 0.000001;
		r.xa = -64.0;
	}
	else
	{
		r.point_x = floor(e->pos.Px / 64.0) * (64.0) + 64.0;
		r.xa = 64.0;
	}
	r.ya = (-r.xa) * tan(ft_get_radian(angle));
	r.point_y = e->pos.Py + (e->pos.Px - r.point_x) * tan(ft_get_radian(angle));
	r.x = (int)floor(r.point_x / 64);
	r.y = (int)floor(r.point_y / 64);
	while ((r.y >= 0 && r.y < e->y_max && r.x >= 0 && r.x < e->x_max)
		   && e->map[r.y][r.x] == 0)
	{
		r.point_y = r.point_y + r.ya;
		r.point_x = r.point_x + r.xa;
		r.x = (int)floor(r.point_x / 64);
		r.y = (int)floor(r.point_y / 64);
	}
	return (fabs((e->pos.Px - r.point_x) / cos(ft_get_radian(angle))));
}

float		ft_get_radian(float alpha)
{
	return (PI * alpha / 180);
}
