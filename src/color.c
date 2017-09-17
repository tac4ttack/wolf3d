/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:34:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/17 15:31:05 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_hue		set_hue(Uint8 a, Uint8 r, Uint8 g, Uint8 b)
{
	t_hue	ret;

	ret.a = a;
	ret.r = r;
	ret.g = g;
	ret.b = b;
	if (SDL_BYTEORDER == SDL_LIL_ENDIAN)
		ret.h = (((((a << 8) + r) << 8) + g) << 8) + b;
	else
		ret.h = (((((b << 8) + g) << 8) + r) << 8) + a;
	return (ret);
}

Uint32		flip_color_byte_order(int color)
{
	Uint32 swap;

	swap = 0;	
	swap = ((color >> 24) & 0xff) |			// move byte 3 to byte 0
			((color >> 8) & 0xff00) |		// move byte 2 to byte 1
			((color << 8) & 0xff0000) |		// move byte 1 to byte 2
			((color << 24 ) & 0xff000000);	// byte 0 to byte 3
	return (swap);
}

Uint32		set_color(Uint8 a, Uint8 r, Uint8 g, Uint8 b)
{
	int	ret;

	if (SDL_BYTEORDER == SDL_LIL_ENDIAN)
	{
		ret = (b & 0x000000FF);
		ret += (g & 0x0000FF00) >> 8;
		ret += (r & 0x00FF0000) >> 16;
		ret += (a & 0xFF000000) >> 24;
	}
	else
	{
		ret = (b & 0x000000FF) >> 24;
		ret += (g & 0x0000FF00) >> 16;
		ret += (r & 0x00FF0000) >> 8;
		ret += (a & 0xFF000000);
	}
	return (ret);
}
