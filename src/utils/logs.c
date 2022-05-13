/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:25:56 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 22:05:12 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_data(t_data *d)
{
	printf(PURPLE" - North texture:"END" %s\n", d->cell[dir_no].tex.path);
	printf(PURPLE" - South texture:"END" %s\n", d->cell[dir_so].tex.path);
	printf(PURPLE" - East  texture:"END" %s\n", d->cell[dir_ea].tex.path);
	printf(PURPLE" - West  texture:"END" %s\n", d->cell[dir_we].tex.path);
	printf("\n");
	if (d->cell[dir_ceiling].tex.path)
		printf(PURPLE" - Ceiling texture:"END" %s\n", \
		d->cell[dir_ceiling].tex.path);
	else
		printf(PURPLE" - Ceiling color:"END" %d\n", d->cell[dir_ceiling].color);
	if (d->cell[dir_floor].tex.path)
		printf(PURPLE" - Floor   texture:"END" %s\n", \
		d->cell[dir_floor].tex.path);
	else
		printf(PURPLE" - Floor   color:"END" %d\n", d->cell[dir_floor].color);
	printf("\n");
}

static void	print_map(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < d->map.size.y)
	{
		x = -1;
		while (++x < d->map.size.x)
		{
			if (d->map.map[y][x] == wall)
				printf(BLUE"■"END);
			else if (y == d->player.spawn.y && x == d->player.spawn.x)
				printf("■");
			else if (d->map.map[y][x] == empty)
				printf(GREY"■"END);
			else if (d->map.map[y][x] == space)
				printf(" ");
		}
		printf("\n");
	}
}

void	logs(t_data *d)
{
	printf(GREEN"\n\t~ The program launches correctly. ~ \n\n"END);
	print_data(d);
	print_map(d);
}
