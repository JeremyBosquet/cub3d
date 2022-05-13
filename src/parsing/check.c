/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:29:23 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 17:33:54 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_north(int **map, int x, int y)
{
	while (y >= 0 && map[y][x] == empty)
		y--;
	if (y < 0 || map[y][x] != wall)
		error(INVALID_MAP);
}

static void	check_south(int **map, int height, int x, int y)
{
	while (y < height && map[y][x] == empty)
		y++;
	if (y >= height || map[y][x] != wall)
		error(INVALID_MAP);
}

static void	check_west(int **map, int x, int y)
{
	while (x >= 0 && map[y][x] == empty)
		x--;
	if (x < 0 || map[y][x] != wall)
		error(INVALID_MAP);
}

static void	check_east(int **map, int width, int x, int y)
{
	while (x < width && map[y][x] == empty)
		x++;
	if (x >= width || map[y][x] != wall)
		error(INVALID_MAP);
}

void	map_is_close(t_data *d)
{
	int		y;
	int		x;
	t_list	*tmp;

	y = -1;
	tmp = d->map.list;
	while (++y < d->map.size.y)
	{
		x = -1;
		while (++x < tmp->width)
		{
			if (d->map.map[y][x] == empty)
			{
				check_north(d->map.map, x, y);
				check_west(d->map.map, x, y);
				check_south(d->map.map, d->map.size.y, x, y);
				check_east(d->map.map, d->map.size.x, x, y);
			}
		}
		tmp = tmp->next;
	}
}
