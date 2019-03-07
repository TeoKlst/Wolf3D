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

static void		set_colors(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

static void		mlx_image_put_pixel(void *mlx, t_im *i,
				t_coordint p, t_rgb *c)
{
	if (i->e)
	{
		i->d[p.y * i->s + p.x * i->bp / 8] = mlx_get_color_value(mlx, c->r);
		i->d[p.y * i->s + p.x * i->bp / 8 + 1] = mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + p.x * i->bp / 8 + 2] = mlx_get_color_value(mlx, c->b);
	}
	else
	{
		i->d[p.y * i->s + i->bp / 8 * p.x] = mlx_get_color_value(mlx, c->b);
		i->d[p.y * i->s + i->bp / 8 * p.x + 1] = mlx_get_color_value(mlx, c->g);
		i->d[p.y * i->s + i->bp / 8 * p.x + 2] = mlx_get_color_value(mlx, c->r);
	}
}

void			drawline(int x, t_wolf3d *w, t_rgb *c)
{
	t_coordint	p;
	t_rgb		skyfloor;

	p.x = x;
	w->im.d = mlx_get_data_addr(w->im.img, &w->im.bp, &w->im.s, &w->im.e);
	set_colors(&skyfloor, 100, 100, 100);
	p.y = 0;
	while (p.y < w->ray.ystart)
	{
		mlx_image_put_pixel(w, &(w->im), p, &skyfloor);
		p.y++;
	}
	p.y = w->ray.ystart;
	while (p.y < w->ray.yend)
	{
		mlx_image_put_pixel(w, &(w->im), p, c);
		p.y++;
	}
	set_colors(&skyfloor, 50, 50, 50);
	p.y = w->ray.yend;
	while (p.y < WIN_HEIGHT)
	{
		mlx_image_put_pixel(w, &(w->im), p, &skyfloor);
		p.y++;
	}
}

void			colors(t_wolf3d *w, t_rgb *c)
{
	if (w->player.wallside == 0)
	{
		if (w->player.step.x < 0)
			set_colors(c, 0, 0, 200);
		else
			set_colors(c, 100, 0, 255);
	}
	if (w->player.wallside > 0)
	{
		if (w->player.step.y < 0)
			set_colors(c, 200, 100, 0);
		else
			set_colors(c, 0, 200, 200);
	}
}
