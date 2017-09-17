/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:10:48 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 16:19:25 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_vertical_line(t_env *e, t_vec2 p, int y, t_rgb rgb)
{
	while (p.y < y)
	{
		img_pixel_put(e, p.x, p.y, rgb);
		p.y++;
	}
}

void	img_pixel_put(t_env *e, int x, int y, t_rgb rgb)
{
	int pos;

	if (x >= 0 && x < e->win_w && y >= 0 && y < e->win_h)
	{
		pos = (x * e->img.opp) + (y * e->img.sl);
		e->img.img[pos] = rgb.b;
		e->img.img[pos + 1] = rgb.g;
		e->img.img[pos + 2] = rgb.r;
	}
}

void	img_init(t_env *e)
{
	error(((int)(e->img.adr = mlx_new_image(e->mlx, e->win_w, e->win_h))));
	e->img.img = mlx_get_data_addr(e->img.adr, &e->img.bpp,
			&e->img.sl, &e->img.endian);
	e->img.opp = e->img.bpp / 8;
}

t_rgb	set_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb = (t_rgb) { r, g, b };
	return (rgb);
}
