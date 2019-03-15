/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:08:53 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/15 18:33:45 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_win(int key, void *param)
{
	if (key == 53)
	{
		mlx_destroy_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		ft_free_2da(((t_fdf *)param)->map, ((t_fdf *)param)->size);
		while (1)
			;
		exit(EXIT_SUCCESS);
	}
	else
		ft_fdf((t_fdf *)param, key);
	return (0);
}

int		fdf_close(void *param)
{
	ft_free_2da(((t_fdf *)param)->map, ((t_fdf *)param)->size);
	exit(EXIT_SUCCESS);
	return (0);
}

t_fdf	fdf_init(int fd, char *name, char *proj)
{
	t_fdf	fdf;

	fdf.map = fdf_make_map(fd, name, &(fdf.size));
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, name);
	if (!ft_strcmp(proj, "iso"))
		fdf.proj = ISO;
	else if (!ft_strcmp(proj, "par"))
		fdf.proj = PAR;
	else
		fdf_error(fdf.map, fdf.size);
	fdf.depth = 4;
	fdf.height = 0;
	fdf.width = 0;
	fdf.zoom = 8;
	fdf.invert = 0;
	return (fdf);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**map;
	t_fdf	fdf;

	map = NULL;
	if (ac != 3)
		exit(EXIT_SUCCESS);
	if (((fd = open(av[1], O_RDONLY)) == -1) || (read(fd, av[0], 0) == -1))
		exit(EXIT_SUCCESS);
	fdf = fdf_init(fd, av[1], av[2]);
	mlx_do_key_autorepeaton(fdf.mlx);
	ft_fdf(&fdf, 0);
	mlx_hook(fdf.win, 2, 0, &close_win, &fdf);
	mlx_hook(fdf.win, 17, (1L << 17), &fdf_close, &fdf);
	mlx_loop(fdf.mlx);
	ft_free_2da(fdf.map, fdf.size);
	return (0);
}
