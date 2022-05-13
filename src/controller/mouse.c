/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:25:14 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 17:21:59 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_view_with_mouse(t_data *d)
{
	t_vect2i	mouse_pos;
	int			delta;

	mlx_mouse_get_pos(d->win, &mouse_pos.x, &mouse_pos.y);
	delta = d->cst.win_half_w - mouse_pos.x;
	if (delta > d->cst.win_half_w + 1)
	{
		d->player.sensi = (float)delta / 1000;
		rotate_player_left(d);
	}
	else if (delta < d->cst.win_half_w - 1)
	{
		d->player.sensi = (float)-delta / 1000;
		rotate_player_right(d);
	}
	mlx_mouse_move(d->win, d->cst.win_half_w, d->cst.win_half_h);
}
