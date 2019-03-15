/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:12:11 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/15 15:34:39 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(int *img, int x, int y)
{
	if ((y * WIN_WIDTH + x) > -1 && (y * WIN_WIDTH + x) < WIN_WIDTH * WIN_HEIGHT
			&& y < WIN_HEIGHT && y >= 0 && x >= 0 && x < WIN_WIDTH)
		img[y * WIN_WIDTH + x] = 0xffffff;
}

void	fdf_bresenham_iter_iso(t_fdf fdf, t_img img, int i, int j)
{
	t_point	point1;
	t_point	point2;
	t_point	point3;

	while (fdf.map[++i])
	{
		j = -1;
		while (++j < fdf.size)
		{
			fdf_iso(fdf_fill_point(fdf.map[i][j], i, j, fdf), &point1, fdf);
			if (j + 1 < fdf.size)
			{
				fdf_iso(fdf_fill_point(fdf.map[i][j + 1], i, j + 1, fdf),
						&point2, fdf);
				fdf_bresenham(point1, point2, img.img);
			}
			if (fdf.map[i + 1])
			{
				fdf_iso(fdf_fill_point(fdf.map[i + 1][j], i + 1, j, fdf),
						&point3, fdf);
				fdf_bresenham(point1, point3, img.img);
			}
		}
	}
}

void	fdf_bresenham_iter_par(t_fdf fdf, t_img img, int i, int j)
{
	t_point	point1;
	t_point	point2;
	t_point	point3;

	while (fdf.map[++i])
	{
		j = -1;
		while (++j < fdf.size)
		{
			fdf_par(fdf_fill_point(fdf.map[i][j], i, j, fdf), &point1, fdf);
			if (j + 1 < fdf.size)
			{
				fdf_par(fdf_fill_point(fdf.map[i][j + 1], i, j + 1, fdf),
						&point2, fdf);
				fdf_bresenham(point1, point2, img.img);
			}
			if (fdf.map[i + 1])
			{
				fdf_par(fdf_fill_point(fdf.map[i + 1][j], i + 1, j, fdf),
						&point3, fdf);
				fdf_bresenham(point1, point3, img.img);
			}
		}
	}
}

void	ft_fdf(t_fdf *fdf, int key)
{
	t_img	img;

	fdf_update_infos(fdf, key);
	mlx_clear_window(fdf->mlx, fdf->win);
	img.ptr = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.img = (int *)mlx_get_data_addr(img.ptr, &(img.bpp), &(img.size_line),
			&(img.endian));
	if (fdf->proj == ISO)
		fdf_bresenham_iter_iso(*fdf, img, -1, -1);
	else
		fdf_bresenham_iter_par(*fdf, img, -1, -1);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.ptr, 0, 0);
	mlx_destroy_image(fdf->mlx, img.ptr);
}
