/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:59:31 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/08 17:30:05 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				key_press(int keycode, t_wolf3d *w)
{
	if (keycode == 123)
		w->player.move.left = 1;
	if (keycode == 126)
		w->player.move.up = 1;
	if (keycode == 124)
		w->player.move.right = 1;
	if (keycode == 125)
		w->player.move.down = 1;
	if (keycode == 262)
		w->player.sprint = 1;
	return (0);
}

int				key_release(int keycode, t_wolf3d *w)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 123)
		w->player.move.left = 0;
	if (keycode == 126)
		w->player.move.up = 0;
	if (keycode == 124)
		w->player.move.right = 0;
	if (keycode == 125)
		w->player.move.down = 0;
	if (keycode == 262)
		w->player.sprint = 0;
	return (0);
}

static void		turn(t_wolf3d *w, char dir)
{
	double	tmpdir;
	double	tmpplane;
	int		coef;

	coef = 1;
	tmpdir = w->player.dir.x;
	tmpplane = w->ray.plane.x;
	if (dir == 'R')
		coef = -1;
	w->player.dir.x = w->player.dir.x * cos(coef * w->player.rspeed)
		- w->player.dir.y * sin(coef * w->player.rspeed);
	w->player.dir.y = tmpdir * sin(coef * w->player.rspeed)
		+ w->player.dir.y * cos(coef * w->player.rspeed);
	w->ray.plane.x = w->ray.plane.x * cos(coef * w->player.rspeed)
		- w->ray.plane.y * sin(coef * w->player.rspeed);
	w->ray.plane.y = tmpplane * sin(coef * w->player.rspeed)
		+ w->ray.plane.y * cos(coef * w->player.rspeed);
}

void			move(t_wolf3d *w)
{
	if (w->player.move.up)
	{
		if (!(w->map.map[(int)(w->player.pos.x + w->player.dir.x
			* w->player.mspeed)][(int)(w->player.pos.y)]))
			w->player.pos.x += w->player.dir.x * w->player.mspeed;
		if (!(w->map.map[(int)(w->player.pos.x)][(int)(w->player.pos.y
			+ w->player.dir.y * w->player.mspeed)]))
			w->player.pos.y += w->player.dir.y * w->player.mspeed;
	}
	if (w->player.move.left)
		turn(w, 'L');
	if (w->player.move.right)
		turn(w, 'R');
	if (w->player.move.down)
	{
		if (!(w->map.map[(int)(w->player.pos.x - w->player.dir.x
			* w->player.mspeed)][(int)(w->player.pos.y)]))
			w->player.pos.x -= w->player.dir.x * w->player.mspeed;
		if (!(w->map.map[(int)(w->player.pos.x)][(int)(w->player.pos.y
			- w->player.dir.y * w->player.mspeed)]))
			w->player.pos.y -= w->player.dir.y * w->player.mspeed;
	}
	if (w->player.sprint)
		w->player.mspeed *= 0.05;
}
