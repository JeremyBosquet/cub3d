/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:44:20 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:22:31 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	loop(t_data *d)
{
	if (d->press.shift)
		d->player.speed = 0.08f;
	move_player(d);
	turn_view_with_mouse(d);
	if (d->press.right_arrow)
	{
		d->player.sensi = 0.015f;
		rotate_player_right(d);
	}
	if (d->press.left_arrow)
	{
		d->player.sensi = 0.015f;
		rotate_player_left(d);
	}
	draw_rays(d, WIN_W);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	init(&d);
	parsing(argc, argv, &d);
	logs(&d);
	draw_rays(&d, WIN_W);
	draw_hud(&d);
	mlx_put_image_to_window(d.mlx, d.win, d.img.img, 0, 0);
	mlx_hook(d.win, 17, 1L << 17, &close_window, &d);
	mlx_hook(d.win, 2, 1L << 0, &controller, &d);
	mlx_hook(d.win, 3, 1L << 1, &unpress_key, &d);
	mlx_loop_hook(d.mlx, loop, &d);
	mlx_loop(d.mlx);
	return (0);
}
