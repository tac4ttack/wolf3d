/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:04:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/07 23:33:25 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

private static Image resizeImage(Image src, int screenWidth, int screenHeight)
{
//	int srcWidth = src.getWidth();
//	int srcHeight = src.getHeight();
	Image tmp = Image.createImage(screenWidth, srcHeight);
	Graphics g = tmp.getGraphics();
	int ratio = (srcWidth << 16) / screenWidth;
	int pos = ratio >> 1;

	// Horizontal Resize
	for (int x = 0; x < screenWidth; x++)
	{
		g.setClip(x, 0, 1, srcHeight);
		g.drawImage(src, x - (pos >> 16), 0, Graphics.LEFT | Graphics.TOP);
		pos += ratio;
	}
	Image resizedImage = Image.createImage(screenWidth, screenHeight);
	g = resizedImage.getGraphics();
	ratio = (srcHeight << 16) / screenHeight;
	pos = ratio >> 1;
	//Vertical resize
	for (int y = 0; y < screenHeight; y++) {
		g.setClip(0, y, screenWidth, 1);
		g.drawImage(tmp, 0, y - (pos >> 16), Graphics.LEFT | Graphics.TOP);
		pos += ratio;
	}
	return resizedImage;
}

SDL_Texture		*resize_image(SDL_Texture *src, int dst_w, int dst_h)
{
	SDL_Texture res;
	int			*src_w;
	int			*src_h;
	int			ratio;
	int			pos;
	int			x;
	int			y;
	
	x = 0;
	y = 0;
	SDL_QueryTexture(src, NULL, NULL, &src_w, &src_h);
	if (!(res = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, dst_w, src_h))
		env_error(e, "Error creating the result texture");
	ratio = (src_width << 16) / dst_w;
	pos = ratio >> 1;
	// horizontal scale
	while (x < dst_w)
	{
		g.setClip(x, 0, 1, srcHeight);
		g.drawImage(src, x - (pos >> 16), 0, Graphics.LEFT | Graphics.TOP);
		pos += ratio;
		x++;
	}
	Image resizedImage = Image.createImage(screenWidth, screenHeight);
	g = resizedImage.getGraphics();
	ratio = (src_h << 16) / dst_h;
	pos = ratio >> 1;
	//Vertical resize
	while(y < dst_h)
	{
		g.setClip(0, y, screenWidth, 1);
		g.drawImage(tmp, 0, y - (pos >> 16), Graphics.LEFT | Graphics.TOP);
		pos += ratio;
		y++;
	}
	return (res);
}
