/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:49:58 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/15 16:30:33 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_bresenham_o1(t_point p1, t_point p2, int *img)
{
	int	dx;
	int	dy;
	int	e;

	e = p2.x - p1.x;
	dx = 2 * e;
	dy = 2 * (p2.y - p1.y);
	while (p1.x <= p2.x)
	{
		fill_pixel(img, p1.x, p1.y);
		p1.x++;
		e -= dy;
		if (e < 0)
		{
			p1.y++;
			e += dx;
		}
	}
	fill_pixel(img, p2.x, p2.y);
}

void	fdf_bresenham_o2(t_point p1, t_point p2, int *img)
{
	int	dx;
	int	dy;
	int	e;

	e = p2.y - p1.y;
	dy = 2 * e;
	dx = 2 * (p2.x - p1.x);
	while (p1.y != p2.y)
	{
		fill_pixel(img, p1.x, p1.y);
		p1.y++;
		e -= dx;
		if (e < 0)
		{
			p1.x++;
			e += dy;
		}
	}
	fill_pixel(img, p2.x, p2.y);
}

void	fdf_bresenham_o3(t_point p1, t_point p2, int *img)
{
	int	dx;
	int	dy;
	int	e;

	e = p2.y - p1.y;
	dy = 2 * e;
	dx = 2 * (p2.x - p1.x);
	while (p1.y != p2.y)
	{
		fill_pixel(img, p1.x, p1.y);
		p1.y++;
		e += dx;
		if (e <= 0)
		{
			p1.x--;
			e += dy;
		}
	}
	fill_pixel(img, p2.x, p2.y);
}

void	fdf_bresenham_o4(t_point p1, t_point p2, int *img)
{
	int	dx;
	int	dy;
	int	e;

	e = p2.x - p1.x;
	dx = 2 * e;
	dy = 2 * (p2.y - p1.y);
	while (p1.x != p2.x)
	{
		fill_pixel(img, p1.x, p1.y);
		p1.x--;
		e += dy;
		if (e >= 0)
		{
			p1.y++;
			e += dx;
		}
	}
	fill_pixel(img, p2.x, p2.y);
}
