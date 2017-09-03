/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:10:48 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 16:19:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse_pos(int x, int y, t_env *e)
{
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}

void	mouse_look(t_env *e)
{
	float			angle;
	float			dif;
	static float	old = 0;
	static float	old_angle = 0;

	dif = e->mouse.x - old;
	old = e->mouse.x;
	angle = PIOVER4 * 0.5 * dif;
	angle = (angle + old_angle) / 2.0;
	old_angle = angle;
	vec2_rotate(&e->cam.dir, angle);
	vec2_rotate(&e->cam.pln, angle);
}

void	mouse_look_free(t_env *e)
{
	float	angle;
	float	dif;

	dif = e->mouse.x - (e->win_w / 2);
	angle = dif / 100;
	vec2_rotate(&e->cam.dir, angle);
	vec2_rotate(&e->cam.pln, angle);
}
