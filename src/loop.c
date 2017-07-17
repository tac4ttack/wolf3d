/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/17 16:39:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void win_events(t_env *env)
{
	if (env->eve.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		env->w_w = env->eve.window.data1;
		env->w_h = env->eve.window.data2;
	}
}

void	keypress_events(t_env *env)
{
	if (env->eve.key.type == SDL_KEYDOWN)
		(env->eve.key.keysym.sym == 27 ? ft_exit(env) : 0);
}


Uint8	main_loop(t_env *env)
{
	if (env)
		while (env->run)
		{
			while (SDL_PollEvent(&env->eve))
			{
				(env->eve.type == SDL_WINDOWEVENT ? win_events(env) : 0);
				(env->eve.type == SDL_KEYDOWN ? keypress_events(env) : 0);
//				(e->debug ? DebugFunkyFuncts() : 0);
				(env->eve.type == SDL_QUIT ? env->run = 0 : 0);
				(env->run == 0 ? ft_exit(env) : 0);
			}
			Render_Rand_Rect_SDL(env);
		}
	return (0);
}
