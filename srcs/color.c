/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:34:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/11 17:28:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

Uint32		set_color(Uint8 a, Uint8 r, Uint8 g, Uint8 b)
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
	return (ret.h);
}
