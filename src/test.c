/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:04:50 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/17 14:22:12 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

////////////////////////////////////////////////////////////////////////////////
// FULL SDL Based functions ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void  		Render_Scramble_SDL(t_env *env)
{
    SDL_Rect rect;
    int ca,cr,cg,cb;
    int res;
    unsigned int value;
    int i,j;

    rect.w=1;
    rect.h=1;
    for (i=0;i<env->w_w; i++)
	{
		for(j=0;j<env->w_h;j++)
		{
	    	rect.x=i;
	    	rect.y=j;
	    	res = SDL_RenderReadPixels(env->ren,&rect,SDL_PIXELFORMAT_ARGB8888,&value,32*env->w_w);
			(res < 0 ? error(NULL, "Error reading pixels format") : res);
			ca = rand()%256;
			cr = rand()%256;
			cg = rand()%256;
			cb = rand()%256;
	    	SDL_SetRenderDrawColor(env->ren,cr,cg,cb,ca);
	    	SDL_RenderDrawPoint(env->ren,i,j);
		}
    }
    SDL_RenderPresent(env->ren);
}

void		Render_Rand_Rect_SDL(t_env *env)
{
	//	Randomly generate rectangles (SDL struct) with random color & positions
	//	It uses the SDL_RenderFillRect function wich is optimised

	int colr, colg, colb;
	SDL_Rect r;
	int i;

	i = 0;
	SDL_SetRenderDrawBlendMode(env->ren,SDL_BLENDMODE_BLEND);
	while (i < 30)
	{
		r.x = rand()%env->w_w;
		r.y = rand()%env->w_h;
		r.w = rand()%(env->w_w - r.x);
		r.h = rand()%(env->w_h - r.y);
		colr = rand()%256;
		colg = rand()%256;
		colb = rand()%256;
		SDL_SetRenderDrawColor(env->ren,colr,colg,colb,20);
		SDL_RenderFillRect(env->ren,&r);
		i++;
	}
	SDL_RenderPresent(env->ren);
}///////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TAC made functions //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// RANDOMLY GENERATED RECTANGLES USING MY RECTANGLE STRUCTURE //////////////////
void		Render_Fill_Rect(SDL_Renderer *ren, t_rec rec)
{
	//	Fills a rectangle (my struct) using only SDL_RenderDrawPoint
	//	to directly draw on the renderer, some kind of slow method
	int	i;
	int j;

	i = rec.w;
	j = rec.h;
	while (j >= 0)
	{
		while (i >= 0)
		{
			SDL_RenderDrawPoint(ren, rec.p.x + i, rec.p.y + j);
			i--;
		}
		i = rec.w;
		j--;
	}
}
void		Render_Rand_Rect(t_env *env)
{
	//	Randomly generate rectangles (my struct) with random color & positions
	//	It uses the homemade Rect_Fill function wich draw directly to the render
	t_hue	h;
	t_rec	r;
	int		i;

	i = 0;
	SDL_SetRenderDrawBlendMode(env->ren, SDL_BLENDMODE_BLEND);
	while(i < 30)
	{
		r.p.x = rand()%BWID;
		r.p.y = rand()%BHEI;
		r.w = rand()%(BWID - (int)r.p.x);
		r.h = rand()%(BHEI - (int)r.p.y);
		h.r = rand()%256;
		h.g = rand()%256;
		h.b = rand()%256;
		SDL_SetRenderDrawColor(env->ren, h.r, h.g, h.b, 20);
		Render_Fill_Rect(env->ren, r);
		i++;
	}
	SDL_RenderPresent(env->ren);
}///////////////////////////////////////////////////////////////////////////////


// RANDOMLY GENERATED RECTANGLES USING SDL RECT STRUCTURE //////////////////////
void		Render_Fill_SDLRect(SDL_Renderer *ren, SDL_Rect rec)
{
	//	Fills a rectangle (SDL struct) using only SDL_RenderDrawPoint
	//	to directly draw on the renderer, some kind of slow method
	int	i;
	int j;

	i = rec.w;
	j = rec.h;
	while (j >= 0)
	{
		while (i >= 0)
		{
			SDL_RenderDrawPoint(ren, rec.x + i, rec.y + j);
			i--;
		}
		i = rec.w;
		j--;
	}
}
void		Render_Rand_SDLRect(t_env *env)
{
	//	Randomly generate rectangles (SDL struct) with random color & positions
	//	It uses the homemade Rect_Fill function wich draw directly to the render
	t_hue		h;
	SDL_Rect	r;
	int			i;

	i = 0;
	SDL_SetRenderDrawBlendMode(env->ren, SDL_BLENDMODE_BLEND);
	while(i < 30)
	{
		r.x = rand()%env->w_w;
		r.y = rand()%env->w_h;
		r.w = rand()%(env->w_w - r.x);
		r.h = rand()%(env->w_h - r.y);
		h.r = rand()%256;
		h.g = rand()%256;
		h.b = rand()%256;
		SDL_SetRenderDrawColor(env->ren, h.r, h.g, h.b, 20);
		Render_Fill_SDLRect(env->ren, r);
		i++;
	}
	SDL_RenderPresent(env->ren);
}///////////////////////////////////////////////////////////////////////////////


// TEXTURE DRAWING /////////////////////////////////////////////////////////////
void	Texture_Draw(t_env *e)
{
	Uint32 * pixels, *p;
	Uint8 r,g,b;
	int x,y;

	pixels = (Uint32*) malloc(e->w_w*e->w_h*sizeof(Uint32));

	if (!pixels) {fprintf(stderr,"Erreur allocation\n"); return;}
	p = pixels;
	for(y=0;y<e->w_h;y++)
	{
		for(x=0;x<e->w_w;x++)
		{
			r = 255 * y / e->w_h;
			g = 255 * x / e->w_w;
			b = 255 * (x+y) / (e->w_w + e->w_h);
			*p=set_color(0,r,g,b);
			p++;
		}
	}
	SDL_UpdateTexture(e->tex, NULL, pixels, e->w_w * sizeof (Uint32));
	SDL_RenderCopy(e->ren, e->tex, NULL, NULL);
	SDL_RenderPresent(e->ren);
//	SDL_DestroyTexture(e->tex);
	free(pixels);
//	ft_putendl("finished drawing");
}///////////////////////////////////////////////////////////////////////////////
