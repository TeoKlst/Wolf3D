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

static void		initray(t_wolf3d *w, int x)
{
	w->player.hcamera = 2 * x / (double)(WIN_WIDTH) - 1;
	w->ray.pos.x = w->player.pos.x;
	w->ray.pos.y = w->player.pos.y;
	w->ray.dir.x = w->player.dir.x + w->ray.plane.x * w->player.hcamera;
	w->ray.dir.y = w->player.dir.y + w->ray.plane.y * w->player.hcamera;
	w->ray.posmap.x = (int)w->ray.pos.x;
	w->ray.posmap.y = (int)w->ray.pos.y;
	w->ray.disd.x = sqrt(1 + (w->ray.dir.y * w->ray.dir.y)
		/ (w->ray.dir.x * w->ray.dir.x));
	w->ray.disd.y = sqrt(1 + (w->ray.dir.x * w->ray.dir.x)
		/ (w->ray.dir.y * w->ray.dir.y));
	w->player.hit = 0;
}

static void		raydir(t_wolf3d *w)
{
	if (w->ray.dir.x < 0)
	{
		w->player.step.x = -1;
		w->ray.sidedist.x = (w->ray.pos.x - w->ray.posmap.x) * w->ray.disd.x;
	}
	else
	{
		w->player.step.x = 1;
		w->ray.sidedist.x = (w->ray.posmap.x + 1.0
		- w->ray.pos.x) * w->ray.disd.x;
	}
	if (w->ray.dir.y < 0)
	{
		w->player.step.y = -1;
		w->ray.sidedist.y = (w->ray.pos.y - w->ray.posmap.y) * w->ray.disd.y;
	}
	else
	{
		w->player.step.y = 1;
		w->ray.sidedist.y = (w->ray.posmap.y + 1.0
		- w->ray.pos.y) * w->ray.disd.y;
	}
}

static void		dda(t_wolf3d *w)
{
	while (w->player.hit == 0)
	{
		if (w->ray.sidedist.x < w->ray.sidedist.y)
		{
			w->ray.sidedist.x += w->ray.disd.x;
			w->ray.posmap.x += w->player.step.x;
			w->player.wallside = 0;
		}
		else
		{
			w->ray.sidedist.y += w->ray.disd.y;
			w->ray.posmap.y += w->player.step.y;
			w->player.wallside = 1;
		}
		if (w->map.map[w->ray.posmap.x][w->ray.posmap.y] > 0)
			w->player.hit = 1;
	}
}

static void		compute(t_wolf3d *w)
{
	double	distwall;

	if (w->player.wallside == 0)
		distwall = fabs((w->ray.posmap.x - w->ray.pos.x
		+ (1 - w->player.step.x) / 2) / w->ray.dir.x);
	else
		distwall = fabs((w->ray.posmap.y - w->ray.pos.y
					+ (1 - w->player.step.y) / 2) / w->ray.dir.y);
	w->ray.lheight = abs((int)(WIN_HEIGHT / distwall));
	w->ray.ystart = (-1 * (w->ray.lheight)) / 2 + WIN_HEIGHT / 2;
	if (w->ray.ystart < 0)
		w->ray.ystart = 0;
	w->ray.yend = w->ray.lheight / 2 + WIN_HEIGHT / 2;
	if (w->ray.yend >= WIN_HEIGHT)
		w->ray.yend = WIN_HEIGHT - 1;
}

int				loop_hook(t_wolf3d *w)
{
	t_rgb	c;
	int		x;

	if (w->im.img != NULL)
	{
		mlx_destroy_image(w->env.mlx, w->im.img);
		w->im.img = NULL;
	}
	w->im.img = mlx_new_image(w->env.mlx, WIN_WIDTH, WIN_HEIGHT);
	x = 0;
	while (x < WIN_WIDTH)
	{
		initray(w, x);
		raydir(w);
		dda(w);
		compute(w);
		colors(w, &c);
		drawline(x, w, &c);
		x++;
	}
	get_timeframe(w);
	move(w);
	mlx_put_image_to_window(w->env.mlx, w->env.win, w->im.img, 0, 0);
	return (0);
}
