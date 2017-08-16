/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:37:08 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/24 14:20:11 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				fdf_img_pix_put(t_env *env, int x, int y, int color)
{
	int			i;

	if (x < env->s_w && y < env->s_h && x > 0 && y > 0)
	{
		i = ((x * (env->bpp / 8)) + (y * env->s_l));
		if (env->endian == 0)
		{
			env->scene[i] = (color & 0x000000FF);
			env->scene[i + 1] = (color & 0x0000FF00) >> 8;
			env->scene[i + 2] = (color & 0x00FF0000) >> 16;
			env->scene[i + 3] = (color & 0xFF000000) >> 24;
		}
		else
		{
			env->scene[i] = (color & 0x000000FF) >> 24;
			env->scene[i + 1] = (color & 0x0000FF00) >> 16;
			env->scene[i + 2] = (color & 0x00FF0000) >> 8;
			env->scene[i + 3] = (color & 0xFF000000);
		}
	}
	return (0);
}

void			fdf_img_line_hor(t_env *env, t_fpoint p1, t_fpoint p2, int c)
{
	int			i;
	int			cumul;
	t_fpoint	p;

	i = 1;
	p.x = p1.x;
	p.y = p1.y;
	fdf_img_pix_put(env, p.x, p.y, c);
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
		fdf_img_pix_put(env, p.x, p.y, c);
	}
}

void			fdf_img_line_ver(t_env *env, t_fpoint p1, t_fpoint p2, int c)
{
	int			i;
	int			cumul;
	t_fpoint	p;

	i = 1;
	p.x = p1.x;
	p.y = p1.y;
	fdf_img_pix_put(env, p.x, p.y, c);
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
		fdf_img_pix_put(env, p.x, p.y, c);
	}
}

void			fdf_img_line(t_env *env, t_fpoint p1, t_fpoint p2, int c)
{
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y))
		fdf_img_line_hor(env, p1, p2, c);
	else
		fdf_img_line_ver(env, p1, p2, c);
}
