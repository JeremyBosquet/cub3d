/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:00:16 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 14:41:51 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_data *d, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
			mlx_pixel_put(d->mlx, d->win, (x + j), (y + i), color);
	}
}
