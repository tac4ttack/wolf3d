/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 11:48:11 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:10:37 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				ft_draw_background(t_data e)
{
	int				i;
	unsigned int	c;

	i = 0;
	c = mlx_get_color_value(e.ptr, CIEL);
	while (i <= (WIN_Y / 2) * e.sizeline)
	{
		e.data[i] = (c & 0xFF);
		e.data[i + 1] = (c & 0xFF00) >> 8;
		e.data[i + 2] = (c & 0xFF0000) >> 16;
		i = i + 4;
	}
	c = mlx_get_color_value(e.ptr, SOL);
	while (i <= WIN_Y *e.sizeline)
	{
		e.data[i] = (c &0xFF);
		e.data[i + 1] = (c & 0xFF00) >> 8;
		e.data[i + 2] = (c & 0xFF0000) >> 16;
		i = i + 4;
	}
}

void				ft_get_wall(t_data *e)
{
	t_draw			d;

	d.angle = e->pos.a - 30;
	d.win_x = WIN_X;
	while (d.win_x > 0)
	{
		d.win_x--;
		if (d.angle > 359.0)
			d.angle -= 359.0;
		if (d.angle < 1.0)
			d.angle += 359.0;
		d.H = ft_get_ray_horizon(e, (d.angle));
		d.V = ft_get_ray_vertical(e, (d.angle));
		d.small = (d.H < d.V)? d.H : d.V;
		d.ray = (d.H < d.V)? 'H' : 'V';
		d.small = d.small * cos(ft_get_radian(e->pos.a - d.angle));
		ft_draw_column(e, d);
		d.angle = d.angle + ALPHA;
	}
}

void				ft_draw_column(t_data *e, t_draw d)
{
	float			height;
	int				i;
	int				j;

	height = (64 / d.small * ((WIN_X / 2) ));
	if (height > WIN_Y)
		height = WIN_Y;
	if (height < 1.0)
		height = 1.0;
	i = (WIN_Y / 2) - height / 2;
	ft_draw_put(e, d, i, -1);
	j = (WIN_Y / 2) + 1 + height / 2;
	ft_draw_put(e, d, j, 1);
}

void				ft_draw_put(t_data *e, t_draw d, int i, int direction)
{
	int		c;

	c = (WIN_Y / 2);
	while (c != i)
	{
		if (d.ray == 'H' && (d.angle <= 180.0 && d.angle >= 0.0))
			ft_pixel_img(e, d.win_x, c, MUR_N);
		else if (d.ray == 'H')
			ft_pixel_img(e, d.win_x, c, MUR_S);
		if (d.ray == 'V' && (d.angle >= 90.0 && d.angle <= 270.0))
			ft_pixel_img(e, d.win_x, c, MUR_O);
		else if (d.ray == 'V')
			ft_pixel_img(e, d.win_x, c, MUR_E);
		c += direction;
	}
}

int					ft_pixel_img(t_data *e, int x, int y, int color)
{
	unsigned int	color2;
	int				i;

	color2 = mlx_get_color_value(e->ptr, color);
	i = (y * e->sizeline) + (x * (e->bpp / 8 ));
	e->data[i] = (color2 & 0xFF);
	i++;
	if (e->bpp >= 16)
		e->data[i] = ((color2 & 0xFF00) >> 8);
	i++;
	if (e->bpp >= 32)
		e->data[i] = ((color2 & 0xFF0000) >> 16);
	return (0);
}
