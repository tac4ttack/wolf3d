/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 22:29:49 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:41:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Texture		*render_text(t_env *e, char *str, SDL_Color color)
{
	SDL_Surface *txt_surface;
	SDL_Texture *txt_texture;

	txt_surface = TTF_RenderText_Blended(e->ttf, str, color);
	txt_texture = SDL_CreateTextureFromSurface(e->ren, txt_surface);
	return (txt_texture);
}
