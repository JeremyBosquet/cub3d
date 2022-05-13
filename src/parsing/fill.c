/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:23:34 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 22:04:37 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_textures(t_data *d, char *line, t_dir *dir)
{
	int	fd;

	fd = open_files(line);
	close_files(fd);
	if (!d->cell[*dir].tex.path)
	{
		d->cell[*dir].tex.path = ft_strdup(line);
		if (!d->cell[*dir].tex.path)
			error(OUT_OF_MEM);
		create_textures(d, &d->cell[*dir].tex, d->cell[*dir].tex.path);
	}
}

void	fill_colors(t_data *d, char *line, t_dir *dir)
{
	int	i;

	check_data_colors(line);
	i = 0;
	str_to_rgb(&d->cell[*dir].rgb.r, &line[i]);
	i += ft_strlen_charset(&line[i], ',') + 1;
	str_to_rgb(&d->cell[*dir].rgb.g, &line[i]);
	i += ft_strlen_charset(&line[i], ',') + 1;
	str_to_rgb(&d->cell[*dir].rgb.b, &line[i]);
	i += ft_strlen_charset(&line[i], ',') + 1;
	d->cell[*dir].color = create_rgb(d->cell[*dir].rgb.r, d->cell[*dir].rgb.g, \
	d->cell[*dir].rgb.b);
}

static void	fill_direction(t_data *d, t_list *list, int x, int y)
{
	if (list->line[x] == 'N')
	{
		d->player.dir = set_vect2f(0, -1);
		d->player.cam = set_vect2f(d->player.fov, 0);
	}
	else if (list->line[x] == 'S')
	{
		d->player.dir = set_vect2f(0, 1);
		d->player.cam = set_vect2f(-d->player.fov, 0);
	}
	else if (list->line[x] == 'W')
	{
		d->player.dir = set_vect2f(-1, 0);
		d->player.cam = set_vect2f(0, -d->player.fov);
	}
	else if (list->line[x] == 'E')
	{
		d->player.dir = set_vect2f(1, 0);
		d->player.cam = set_vect2f(0, d->player.fov);
	}
	d->player.spawn = set_vect2i(x, y);
	d->player.pos = set_vect2f(x + 0.5, y + 0.5);
	d->map.map[y][x] = empty;
}

static void	fill_data_map(t_data *d, t_list *list, int x, int y)
{
	if (x >= list->width || list->line[x] == ' ')
		d->map.map[y][x] = space;
	else if (list->line[x] == '0')
		d->map.map[y][x] = empty;
	else if (list->line[x] == '1')
		d->map.map[y][x] = wall;
	else
		fill_direction(d, list, x, y);
}

void	fill_map(t_data *d)
{
	t_list	*list;
	int		x;
	int		y;

	d->map.map = ft_calloc(d->map.size.y, sizeof(int *));
	if (!d->map.map)
		error(OUT_OF_MEM);
	list = d->map.list;
	y = -1;
	while (++y < d->map.size.y)
	{
		d->map.map[y] = ft_calloc(d->map.size.x, sizeof(int));
		if (!d->map.map[y])
			error(OUT_OF_MEM);
		x = -1;
		while (++x < d->map.size.x)
			fill_data_map(d, list, x, y);
		list = list->next;
	}
}
