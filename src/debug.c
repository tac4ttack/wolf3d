/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:27:10 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:45:09 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print_info(t_env *e)
{
	ft_putstr("\nWindow's width = ");
	ft_putnbr(WW);
	ft_putstr(" | height = ");
	ft_putnbr(WH);
	ft_putendl("\nPlayer position:");
	ft_putstr("Grid_x = ");
	ft_putnbr(e->player.grid.x);
	ft_putstr(" | Grid_y = ");
	ft_putnbr(e->player.grid.y);
	ft_putstr("\nMap_x = ");
	ft_putnbr(e->player.pix.x);
	ft_putstr(" | Map_y = ");
	ft_putnbr(e->player.pix.y);
	ft_putchar('\n');
	ft_putstr("Player dir is ");
	ft_putnbr(e->player.dir);
	ft_putchar('\n');
	ft_putstr("Tile Width = ");
	ft_putnbr(TW);
	ft_putstr(" | Tile Height = ");
	ft_putnbr(TH);
	ft_putchar('\n');
}

void		print_input(int key)
{
	ft_putstr("Input is ");
	ft_putnbr(key);
	ft_putchar('\n');
}

void		print_window_events_b(const SDL_Event *ev)
{
	if (ev->window.event == SDL_WINDOWEVENT_MINIMIZED)
		SDL_Log("Window %d minimized", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_MAXIMIZED)
		SDL_Log("Window %d maximized", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_RESTORED)
		SDL_Log("Window %d restored", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_ENTER)
		SDL_Log("Mouse entered window %d", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_LEAVE)
		SDL_Log("Mouse left window %d", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		SDL_Log("Window %d gained keyboard focus", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		SDL_Log("Window %d lost keyboard focus", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_CLOSE)
		SDL_Log("Window %d closed", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_TAKE_FOCUS)
		SDL_Log("Window %d is offered a focus", ev->window.windowID);
	if (ev->window.event == SDL_WINDOWEVENT_HIT_TEST)
		SDL_Log("Window %d has special hit test", ev->window.windowID);
	else
		SDL_Log("Window %d got unknown event %d",
				ev->window.windowID, ev->window.event);
}

void		print_window_events_a(const SDL_Event *ev)
{
	if (ev->type == SDL_WINDOWEVENT)
	{
		if (ev->window.event == SDL_WINDOWEVENT_SHOWN)
			SDL_Log("Window %d shown", ev->window.windowID);
		if (ev->window.event == SDL_WINDOWEVENT_HIDDEN)
			SDL_Log("Window %d hidden", ev->window.windowID);
		if (ev->window.event == SDL_WINDOWEVENT_EXPOSED)
			SDL_Log("Window %d exposed", ev->window.windowID);
		if (ev->window.event == SDL_WINDOWEVENT_MOVED)
			SDL_Log("Window %d moved to %d,%d", ev->window.windowID,
					ev->window.data1, ev->window.data2);
		if (ev->window.event == SDL_WINDOWEVENT_RESIZED)
			SDL_Log("Window %d resized to %dx%d", ev->window.windowID,
					ev->window.data1, ev->window.data2);
		if (ev->window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
			SDL_Log("Window %d size changed to %dx%d", ev->window.windowID,
					ev->window.data1, ev->window.data2);
		print_window_events_b(ev);
	}
}
