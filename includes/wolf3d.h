/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:52:48 by tkelest           #+#    #+#             */
/*   Updated: 2018/08/08 09:10:54 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <time.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*dat;

	double		time;
	double		oldtime;
	long int	frametime;
}				t_env;

typedef struct	s_map
{
	int			**map;
	int			display;
	int			size_x;
	int			size_y;
}				t_map;

typedef struct	s_window
{
	double		win_x_size;
	double		win_y_size;
}				t_window;

typedef struct	s_im
{
	int			size;
	int			endian;
	int			bpp;

	void		*img;
	char		*d;
	int			bp;
	int			s;
	int			e;
}				t_im;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_coordint
{
	int			x;
	int			y;
}				t_coordint;

typedef struct	s_move
{
	int	up;
	int	left;
	int	right;
	int	down;
}				t_move;

typedef struct	s_player
{
	double		x;
	double		y;
	double		xdirection;
	double		ydirection;
	double		rotate;

	t_coord		pos;
	t_coord		dir;
	t_coordint	step;
	t_move		move;
	double		rspeed;
	double		mspeed;
	double		hcamera;
	int			hit;
	int			wallside;
	int			sprint;
}				t_player;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		sidedist;
	t_coord		disd;
	t_coordint	posmap;
	int			lheight;
	int			ystart;
	int			yend;
}				t_ray;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_wolf3d
{
	t_env		env;
	t_window	window;
	t_player	player;
	t_map		map;
	t_im		im;
	t_ray		ray;
	t_rgb		rgb;
}				t_wolf3d;

void			get_timeframe(t_wolf3d *w);
int				expose_hook(t_wolf3d *w);
int				loop_hook(t_wolf3d *w);
int				key_release(int keycode, t_wolf3d *w);
int				key_press(int keycode, t_wolf3d *w);
void			move(t_wolf3d *w);
void			colors(t_wolf3d *w, t_rgb *c);
void			drawline(int x, t_wolf3d *w, t_rgb *c);
int				mouse_hook(int button, int x, int y);
int				red_x_press(void *p);
void			get_timeframe(t_wolf3d *w);

#endif
