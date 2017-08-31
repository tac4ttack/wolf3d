/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/31 11:35:58 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_frame(t_env *e)
{
	int x;

	x = 0;
	while (x < e->w_w)
	{
		init_ray(e, x);		// initialisation rayon, semble OK
		convert_dir(e);		// conversion direction en radian, semble OK
		calc_step(e);		//calc_step
		//	calc_dda(e);		// calcul du point d'intersection avec algo dda
		// calcul taille mur a dessiner
		// calcul couleur a appliquer
		// dessin du mur
		x++;
	}
	// fonction mouvement
}

Uint8	main_loop(t_env *e)
{
	if (e)
		SDL_SetRenderDrawBlendMode(e->ren,SDL_BLENDMODE_BLEND);
		while (e->run)
		{
			while (SDL_PollEvent(&e->eve))
			{
				(e->eve.type == SDL_WINDOWEVENT ? win_events(e) : 0);
				(e->eve.type == SDL_KEYDOWN ? keypress_events(e) : 0);
				(e->debug ? PrintWindowEvent(&e->eve) : 0);
				(e->eve.type == SDL_QUIT ? e->run = 0 : 0);
				(e->run == 0 ? quit(e) : 0);
			}
		//	draw_frame(e);
			Render_Rand_Rect_SDL(e);
		//	SDL_UpdateTexture(e->tex, NULL, e->pix, e->w_w * sizeof (Uint32));
		//	SDL_RenderCopy(e->ren, e->tex, NULL, NULL);
		//	SDL_RenderPresent(e->ren);
		}
	return (0);
}
