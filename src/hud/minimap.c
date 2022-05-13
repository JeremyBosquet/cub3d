/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:54:46 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 15:48:01 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_minimap(t_data *d, int x, int y)
{
	int	minimap_w;

	minimap_w = (d->map.size.x * 5) * 0.5;
	draw_square(d, 25 + d->cst.win_half_w + (x * 5) - minimap_w, \
	25 + (WIN_H - HUD) + (y * 5), 0x818589);
	draw_square(d, \
	25 + d->cst.win_half_w + ((int)d->player.pos.x * 5) - minimap_w, \
	25 + (WIN_H - HUD) + ((int)d->player.pos.y * 5), 0xFFFFFF);
}

void	draw_minimap(t_data *d)
{
	int	x;
	int	y;
	int	minimap_w;

	minimap_w = (d->map.size.x * 5) * 0.5;
	y = -1;
	while (++y < d->map.size.y)
	{
		x = -1;
		while (++x < d->map.size.x)
		{
			if (d->map.map[y][x] == wall)
				draw_square(d, 25 + d->cst.win_half_w + (x * 5) - minimap_w, \
				25 + (WIN_H - HUD) + (y * 5), 0x008080);
			else if (x == (int)d->player.pos.x && y == (int)d->player.pos.y)
				draw_square(d, 25 + d->cst.win_half_w + (x * 5) - minimap_w, \
				25 + (WIN_H - HUD) + (y * 5), 0xFFFFFF);
			else if (d->map.map[y][x] == empty)
				draw_square(d, 25 + d->cst.win_half_w + (x * 5) - minimap_w, \
				25 + (WIN_H - HUD) + (y * 5), 0x818589);
		}
	}
}
