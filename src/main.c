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

static void		readsize(t_wolf3d *w, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		exit(EXIT_FAILURE);
	size = ft_strsplittoint(line, ' ');
	w->map.size_x = size[0];
	w->map.size_y = size[1];
}

static void		readmap(t_wolf3d *w, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * w->map.size_x);
	if (worldmap == NULL)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	w->map.map = worldmap;
}

static void		readfile(t_wolf3d *w)
{
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("42", O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	readsize(w, fd);
	readmap(w, fd);
	close(fd);
}

int				main(int argc, char **argv)
{
	t_wolf3d	w;

	if (argc == 1)
		argv[0] = argv[1];
	w.env.mlx = mlx_init();
	w.env.win = mlx_new_window(w.env.mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3D");
	w.im.img = NULL;
	w.player.pos.x = 5;
	w.player.pos.y = 5;
	w.player.dir.x = -1;
	w.player.dir.y = 0;
	w.ray.plane.x = 0;
	w.ray.plane.y = 0.80;
	w.env.time = 0;
	w.env.oldtime = 0;
	readfile(&w);
	mlx_loop_hook(w.env.mlx, &loop_hook, &w);
	mlx_hook(w.env.win, 2, (1L << 0), &key_press, &w);
	mlx_hook(w.env.win, 3, (1L << 1), &key_release, &w);
	mlx_hook(w.env.win, 17, 0, red_x_press, &w);
	mlx_mouse_hook(w.env.win, mouse_hook, w.env.win);
	mlx_loop(w.env.mlx);
	return (0);
}
