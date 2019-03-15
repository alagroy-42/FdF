/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:36:56 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/15 17:18:29 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/libft.h"
# include "math.h"
# include <fcntl.h>
# define WIN_HEIGHT 1500
# define WIN_WIDTH 2000

typedef enum	e_proj
{
	ISO,
	PAR,
}				t_proj;

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_proj	proj;
	int		size;
	int		**map;
	int		zoom;
	int		depth;
	int		width;
	int		height;
	int		invert;
}				t_fdf;

typedef struct	s_img
{
	void	*ptr;
	int		*img;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_point
{
	int x;
	int	y;
	int	z;
}				t_point;

int				**fdf_make_map(int fd, char *file, int *size);
void			fdf_error(int **map, int size);
t_point			fdf_fill_point(int z, int x, int y, t_fdf fdf);
void			ft_fdf(t_fdf *fdf, int key);
void			fill_pixel(int *img, int x, int y);
void			fdf_bresenham_o1(t_point p1, t_point p2, int *img);
void			fdf_bresenham_o2(t_point p1, t_point p2, int *img);
void			fdf_bresenham_o3(t_point p1, t_point p2, int *img);
void			fdf_bresenham_o4(t_point p1, t_point p2, int *img);
void			fdf_bresenham(t_point p1, t_point p2, int *img);
void			fdf_update_infos(t_fdf *fdf, int key);
void			fdf_iso(t_point point3d, t_point *point, t_fdf fdf);
void			fdf_par(t_point point3d, t_point *point, t_fdf fdf);

#endif
