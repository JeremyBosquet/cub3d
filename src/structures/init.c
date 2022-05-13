/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:58:02 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 17:22:44 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_data *d)
{
	d->mlx = mlx_init();
	if (!d->mlx)
		error(MLX_FAILED);
	d->win = mlx_new_window(d->mlx, WIN_W, WIN_H, "cub3D");
	d->img.img = mlx_new_image(d->mlx, WIN_W, WIN_H - HUD);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, \
	&d->img.line_length, &d->img.endian);
	mlx_mouse_hide();
	mlx_mouse_move(d->win, d->cst.win_half_w, d->cst.win_half_h);
}

void	init(t_data *d)
{
	ft_memset(d, 0, sizeof(t_data));
	ft_memset(&d->map, 0, sizeof(t_map));
	ft_memset(&d->cell, 0, sizeof(t_cell));
	ft_memset(&d->cst, 0, sizeof(t_const));
	ft_memset(&d->player, 0, sizeof(t_player));
	ft_memset(&d->img, 0, sizeof(t_img));
	init_mlx(d);
	d->cst.win_half_h = WIN_H * 0.5;
	d->cst.win_half_w = WIN_W * 0.5;
	d->player.fov = 0.66f;
	d->player.speed = 0.05f;
	d->player.sensi = 0.015f;
}
