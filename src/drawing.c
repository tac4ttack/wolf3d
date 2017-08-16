/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:38:42 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/16 19:07:25 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	sdl_tex_pix_put(t_env *e, int x, int y,  int color)
{
	int	i;

	if (x < e->w_w && y < e->w_h && x > 0 && y > 0)
	{
		i = ((x * (4)) + (y * 20));
		if (SDL_BYTEORDER == SDL_LIL_ENDIAN)
		{
			e->pix[i] = (color & 0x000000FF);
			e->pix[i + 1] = (color & 0x0000FF00) >> 8;
			e->pix[i + 2] = (color & 0x00FF0000) >> 16;
			e->pix[i + 3] = (color & 0xFF000000) >> 24;
		}
		else
		{
			e->pix[i] = (color & 0x000000FF) >> 24;
			e->pix[i + 1] = (color & 0x0000FF00) >> 16;
			e->pix[i + 2] = (color & 0x00FF0000) >> 8;
			e->pix[i + 3] = (color & 0xFF000000);
		}
	}
}
