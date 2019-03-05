/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:58:06 by tkelest           #+#    #+#             */
/*   Updated: 2018/12/04 13:59:45 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				mouse_hook(int button, int x, int y)
{
	printf("mouse %d (%d:%d)\n", button, x, y);
	return (0);
}

int				red_x_press(void *p)
{
	(void)p;
	exit(0);
}

void			get_timeframe(t_wolf3d *w)
{
	struct timeval time;

	w->env.oldtime = w->env.time;
	gettimeofday(&time, NULL);
	w->env.time = time.tv_sec * 1000 + time.tv_usec / 1000;
	w->env.frametime = w->env.time - w->env.oldtime;
	w->player.mspeed = w->env.frametime * 0.003;
	w->player.rspeed = w->env.frametime * 0.005;
}
