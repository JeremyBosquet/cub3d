/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:14:34 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 18:18:30 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_help_key(t_data *d)
{
	mlx_string_put(d->mlx, d->win, 185, 70 + (WIN_H - HUD), 0xFFFFFF, \
	"[W] - Move up");
	mlx_string_put(d->mlx, d->win, 185, 90 + (WIN_H - HUD), 0xFFFFFF, \
	"[A] - Move left");
	mlx_string_put(d->mlx, d->win, 185, 110 + (WIN_H - HUD), 0xFFFFFF, \
	"[S] - Move down");
	mlx_string_put(d->mlx, d->win, 185, 130 + (WIN_H - HUD), 0xFFFFFF, \
	"[D] - Move right");
	mlx_string_put(d->mlx, d->win, 475, 70 + (WIN_H - HUD), 0xFFFFFF, \
	"[<-] - Move camera left");
	mlx_string_put(d->mlx, d->win, 475, 90 + (WIN_H - HUD), 0xFFFFFF, \
	"[->] - Move camera right");
	mlx_string_put(d->mlx, d->win, 475, 110 + (WIN_H - HUD), 0xFFFFFF, \
	"[SHIFT] - Sprint");
	mlx_string_put(d->mlx, d->win, 475, 130 + (WIN_H - HUD), 0xFFFFFF, \
	"[ESC] - Quit");
}

static void	draw_info(t_data *d)
{
	mlx_string_put(d->mlx, d->win, WIN_W - 275, 70 + (WIN_H - HUD), 0xFFFFFF, \
	"Project: cub3D");
	mlx_string_put(d->mlx, d->win, WIN_W - 275, 90 + (WIN_H - HUD), 0xFFFFFF, \
	"Author: jbosquet - mmosca");
	mlx_string_put(d->mlx, d->win, WIN_W - 275, 110 + (WIN_H - HUD), 0xFFFFFF, \
	"Date: 2022/03/03");
	mlx_string_put(d->mlx, d->win, WIN_W - 275, 130 + (WIN_H - HUD), 0xFFFFFF, \
	"Copyright: COUSCOUS-3D");
}

void	draw_hud(t_data *d)
{
	draw_minimap(d);
	draw_help_key(d);
	draw_info(d);
}
