/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:29:16 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/15 16:59:22 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_bresenham_dx_neg(t_point p1, t_point p2, int *img, int dx)
{
	int	dy;

	if (dx != 0)
		if ((dy = p2.y - p1.y) != 0)
			if (dy > 0)
				if (-dy >= dx)
					fdf_bresenham_o4(p1, p2, img);
				else
					fdf_bresenham_o3(p1, p2, img);
			else if (dx <= dy)
				fdf_bresenham_o1(p2, p1, img);
			else
				fdf_bresenham_o2(p2, p1, img);
		else
			while (p1.x-- != p2.x)
				fill_pixel(img, p1.x, p1.y);
	else
		while ((dy = p2.y - p1.y) > 0 ? ++p1.y < p2.y : --p1.y > p2.y)
			fill_pixel(img, p1.x, p1.y);
}

void	fdf_bresenham(t_point p1, t_point p2, int *img)
{
	int	dx;
	int	dy;

	fill_pixel(img, p1.x, p1.y);
	dx = p2.x - p1.x;
	if (dx > 0)
		if ((dy = p2.y - p1.y) != 0)
			if (dy > 0)
				if (dx >= dy)
					fdf_bresenham_o1(p1, p2, img);
				else
					fdf_bresenham_o2(p1, p2, img);
			else if (dx >= -dy)
				fdf_bresenham_o4(p2, p1, img);
			else
				fdf_bresenham_o3(p2, p1, img);
		else
			while (++p1.x != p2.x)
				fill_pixel(img, p1.x, p1.y);
	else
		fdf_bresenham_dx_neg(p1, p2, img, dx);
	fill_pixel(img, p2.x, p2.y);
}
