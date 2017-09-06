/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:34:59 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 16:42:59 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_dash_left(t_data *d)
{
	d->pos.Py = d->pos.Py - sin(ft_get_radian(d->pos.a + 90)) * 2;
	d->pos.Px = d->pos.Px + cos(ft_get_radian(d->pos.a + 90)) * 2;
	if (d->map[(int)floor(d->pos.Py / 64)][(int)floor(d->pos.Px / 64)] == 1)
		ft_dash_right(d);
}

void		ft_move_up(t_data *d)
{
	d->pos.Py = d->pos.Py - sin(ft_get_radian(d->pos.a)) * 2;
	d->pos.Px = d->pos.Px + cos(ft_get_radian(d->pos.a)) * 2;
	if (d->map[(int)floor(d->pos.Py / 64)][(int)floor(d->pos.Px / 64)] == 1)
		ft_move_down(d);
}

void		ft_move_down(t_data *d)
{
	d->pos.Py = d->pos.Py + sin(ft_get_radian(d->pos.a)) * 2;
	d->pos.Px = d->pos.Px - cos(ft_get_radian(d->pos.a)) * 2;
	if (d->map[(int)floor(d->pos.Py / 64)][(int)floor(d->pos.Px / 64)] == 1)
		ft_move_up(d);
}

void		ft_move_left(t_data *d)
{
	d->pos.a = d->pos.a + 2;
	if (d->pos.a > 359)
		d->pos.a -= 359;
}

void		ft_move_right(t_data *d)
{
	d->pos.a = d->pos.a - 2;
	if (d->pos.a < 1)
		d->pos.a += 359;
}
