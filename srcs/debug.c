/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:27:10 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/12 15:25:40 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    PrintWindowEvent(const SDL_Event *ev)
{
    if (ev->type == SDL_WINDOWEVENT)
    {
        switch (ev->window.event)
        {
            case SDL_WINDOWEVENT_SHOWN:
                SDL_Log("Window %d shown", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_HIDDEN:
                SDL_Log("Window %d hidden", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_EXPOSED:
                SDL_Log("Window %d exposed", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_MOVED:
                SDL_Log("Window %d moved to %d,%d",
                        ev->window.windowID, ev->window.data1,
                        ev->window.data2);
                break;
            case SDL_WINDOWEVENT_RESIZED:
                SDL_Log("Window %d resized to %dx%d",
                        ev->window.windowID, ev->window.data1,
                        ev->window.data2);
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                SDL_Log("Window %d size changed to %dx%d",
                        ev->window.windowID, ev->window.data1,
                        ev->window.data2);
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                SDL_Log("Window %d minimized", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                SDL_Log("Window %d maximized", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_RESTORED:
                SDL_Log("Window %d restored", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_ENTER:
                SDL_Log("Mouse entered window %d",
                        ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_LEAVE:
                SDL_Log("Mouse left window %d", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                SDL_Log("Window %d gained keyboard focus",
                        ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
                SDL_Log("Window %d lost keyboard focus",
                        ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_CLOSE:
                SDL_Log("Window %d closed", ev->window.windowID);
                break;
    #if SDL_VERSION_ATLEAST(2, 0, 5)
            case SDL_WINDOWEVENT_TAKE_FOCUS:
                SDL_Log("Window %d is offered a focus", ev->window.windowID);
                break;
            case SDL_WINDOWEVENT_HIT_TEST:
                SDL_Log("Window %d has a special hit test", ev->window.windowID);
                break;
    #endif
            default:
                SDL_Log("Window %d got unknown event %d",
                        ev->window.windowID, ev->window.event);
                break;
        }
    }
}
