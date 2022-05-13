/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:06:52 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 17:23:53 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	unpress_key(int keycode, t_data *d)
{
	if (keycode == SHIFT_KEY && d->press.shift)
	{
		d->player.speed = 0.05;
		d->press.shift = false;
	}
	else if (keycode == LEFT_KEY && d->press.left_arrow)
		d->press.left_arrow = false;
	else if (keycode == RIGHT_KEY && d->press.right_arrow)
		d->press.right_arrow = false;
	else if (keycode == A_KEY && d->press.a)
		d->press.a = false;
	else if (keycode == D_KEY && d->press.d)
		d->press.d = false;
	else if (keycode == S_KEY && d->press.s)
		d->press.s = false;
	else if (keycode == W_KEY && d->press.w)
		d->press.w = false;
	return (0);
}

int	controller(int keycode, t_data *d)
{
	d->press.left_arrow = (d->press.left_arrow || keycode == LEFT_KEY);
	d->press.right_arrow = (d->press.right_arrow || keycode == RIGHT_KEY);
	d->press.a = (d->press.a || keycode == A_KEY);
	d->press.d = (d->press.d || keycode == D_KEY);
	d->press.w = (d->press.w || keycode == W_KEY);
	d->press.s = (d->press.s || keycode == (S_KEY));
	d->press.shift = (d->press.shift || keycode == (SHIFT_KEY));
	if (keycode == ESC_KEY || keycode == Q_KEY)
		close_window(d);
	return (0);
}
