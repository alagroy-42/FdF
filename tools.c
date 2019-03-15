/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:41:22 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/15 16:12:36 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_update_infos(t_fdf *fdf, int key)
{
	if (key == 69)
		fdf->zoom++;
	else if (key == 78 && fdf->zoom - 1 > 0)
		fdf->zoom--;
	else if (key == 116)
		fdf->depth++;
	else if (key == 121)
		fdf->depth--;
	if (key == 125)
		fdf->height--;
	else if (key == 126)
		fdf->height++;
	else if (key == 123)
		fdf->width++;
	else if (key == 124)
		fdf->width--;
	else if (key == 31 && fdf->invert == 0)
		fdf->invert = 1;
	else if (key == 31)
		fdf->invert = 0;
}

void	fdf_iso(t_point point3d, t_point *point, t_fdf fdf)
{
	point->x = ((point3d.x - point3d.y) * cos(0.523599)) + (WIN_WIDTH / 6) + (15
		* fdf.width);
	point->y = (-point3d.z + (point3d.x + point3d.y) * sin(0.523599))
		+ (WIN_HEIGHT / 6) + (15 * fdf.height);
}

void	fdf_par(t_point point3d, t_point *point, t_fdf fdf)
{
	point->x = fdf.invert ? point3d.x + (0.5 * point3d.z * cos(0.785398))
		+ WIN_WIDTH / 6 + (15 * fdf.width) : point3d.x - (0.5 * point3d.z
				* cos(0.785398)) + WIN_WIDTH / 6 + (15 * fdf.width);
	point->y = fdf.invert ? point3d.y + (0.5 * point3d.z * sin(0.785398))
		+ WIN_HEIGHT / 6 + (15 * fdf.height) : point3d.y - (0.5 * point3d.z
				* sin(0.785398)) + WIN_HEIGHT / 6 + (15 * fdf.height);
}

t_point	fdf_fill_point(int z, int y, int x, t_fdf fdf)
{
	t_point		point;

	point.x = x * 5 * fdf.zoom;
	point.y = y * 5 * fdf.zoom;
	point.z = z * fdf.depth * fdf.zoom / 3;
	return (point);
}

void	fdf_error(int **map, int size)
{
	ft_free_2da(map, size);
	exit(EXIT_FAILURE);
}
