/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:38:42 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/06 21:07:29 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdl_tex_pix_put(t_env *e, int x, int y,  int color)
{
	int	i;

	if (x < WW && y < WH && x >= 0 && y >= 0)
	{
		i = (x + (y * WW));
		if (SDL_BYTEORDER == SDL_LIL_ENDIAN)
			e->pix[i] = color;
		else
		{
			color = flip_color_byte_order(color);
			e->pix[i] = color;
		}
	}
}

void			sdl_tex_line_hor(t_env *e, t_ldpt p1, t_ldpt p2, int c)
{
	int			i;
	int			cumul;
	t_ldpt	p;

	i = 1;
	p.x = p1.x;
	p.y = p1.y;
	sdl_tex_pix_put(e, p.x, p.y, c);
	cumul = ft_abs(p2.x - p1.x) / 2;
	while (i <= ft_abs(p2.x - p1.x))
	{
		i++;
		p.x += ((p2.x - p1.x) > 0) ? 1 : -1;
		cumul += ft_abs(p2.y - p1.y);
		if (cumul >= ft_abs(p2.x - p1.x))
		{
			cumul -= ft_abs(p2.x - p1.x);
			p.y += ((p2.y - p1.y) > 0) ? 1 : -1;
		}
		sdl_tex_pix_put(e, p.x, p.y, c);
	}
}

void			sdl_tex_line_ver(t_env *e, t_ldpt p1, t_ldpt p2, int c)
{
	int			i;
	int			cumul;
	t_ldpt	p;

	i = 1;
	p.x = p1.x;
	p.y = p1.y;
	sdl_tex_pix_put(e, p.x, p.y, c);
	cumul = ft_abs(p2.y - p1.y) / 2;
	while (i <= ft_abs(p2.y - p1.y))
	{
		i++;
		p.y += ((p2.y - p1.y) > 0) ? 1 : -1;
		cumul += ft_abs(p2.x - p1.x);
		if (cumul >= ft_abs(p2.y - p1.y))
		{
			cumul -= ft_abs(p2.y - p1.y);
			p.x += ((p2.x - p1.x) > 0) ? 1 : -1;
		}
		sdl_tex_pix_put(e, p.x, p.y, c);
	}
}

void	sdl_tex_line(t_env *e, t_ldpt pt1, t_ldpt pt2, int color)
{
	if (ft_abs(pt2.x - pt1.x) > ft_abs(pt2.y - pt1.y))
		sdl_tex_line_hor(e, pt1, pt2, color);
	else
		sdl_tex_line_ver(e, pt1, pt2, color);
}
