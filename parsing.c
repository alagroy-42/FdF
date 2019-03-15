/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:16:29 by alagroy-          #+#    #+#             */
/*   Updated: 2019/03/12 14:59:22 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_lines(int fd)
{
	int		nb_lines;
	char	*line;

	nb_lines = 0;
	while (get_next_line(fd, &line) == 1)
	{
		nb_lines++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (nb_lines);
}

int		fdf_parse_line(char *line, int **map, int line_index, int *size_line)
{
	char		**split;
	int			i;
	static int	old_line = -1;

	i = 0;
	if (!(split = ft_strsplit(line, ' ')))
		return (1);
	while (split[i])
		i++;
	if (i != old_line && old_line != -1)
		return (1);
	if (!(map[line_index] = (int *)malloc((i + 1) * sizeof(int))))
		return (1);
	*size_line = i;
	old_line = i;
	i = -1;
	while (++i < old_line)
		map[line_index][i] = ft_atoi(split[i]);
	ft_free_2dstr(split);
	return (0);
}

int		**fdf_make_map(int fd, char *file, int *size)
{
	int		i;
	int		**map;
	int		nb_lines;
	char	*line;

	i = -1;
	nb_lines = ft_count_lines(fd);
	if (!(map = (int **)malloc((nb_lines + 1) * sizeof(int *))))
		exit(EXIT_FAILURE);
	map[nb_lines] = NULL;
	fd = open(file, O_RDONLY);
	while (++i < nb_lines && fd != 0)
	{
		if (get_next_line(fd, &line) == 1)
			fdf_parse_line(line, map, i, size) ? fdf_error(map, i) : 1;
		free(line);
		line = NULL;
	}
	return (map);
}
