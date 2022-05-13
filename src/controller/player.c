/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:43:17 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 17:46:51 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_pos(t_data *d, t_vect2f pred, t_vect2i old_pos)
{
	if (d->map.map[(int)pred.y][(int)d->player.pos.x] == 0)
	{
		d->player.pos.y = pred.y;
		update_minimap(d, d->player.pos.x, old_pos.y);
	}
	if (d->map.map[(int)d->player.pos.y][(int)pred.x] == 0)
	{
		d->player.pos.x = pred.x;
		update_minimap(d, old_pos.x, d->player.pos.y);
	}
}

void	move_player(t_data *d)
{
	t_vect2f	pred;
	t_vect2f	dir;
	double		angle;
	t_vect2i	old_pos;

	dir.y = -(d->press.s && !d->press.w) + (d->press.w && !d->press.s);
	dir.x = -(d->press.d && !d->press.a) + (d->press.a && !d->press.d);
	if (!dir.x && !dir.y)
		return ;
	angle = atan2(dir.y, dir.x);
	pred.x = d->player.pos.x + (dir.x != 0) \
	* ((d->player.cam.x * d->player.speed) * -cos(angle));
	pred.y = d->player.pos.y + (dir.x != 0) \
	* ((d->player.cam.y * d->player.speed) * -cos(angle));
	pred.x += (dir.y != 0) * ((d->player.dir.x * d->player.speed) * sin(angle));
	pred.y += (dir.y != 0) * ((d->player.dir.y * d->player.speed) * sin(angle));
	old_pos = set_vect2i((int)d->player.pos.x, (int)d->player.pos.y);
	set_pos(d, pred, old_pos);
}

void	rotate_player_left(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->player.dir.x;
	d->player.dir.x = d->player.dir.x * cos(-d->player.sensi) \
	- d->player.dir.y * sin(-d->player.sensi);
	d->player.dir.y = old_dir_x * sin(-d->player.sensi) \
	+ d->player.dir.y * cos(-d->player.sensi);
	old_plane_x = d->player.cam.x;
	d->player.cam.x = d->player.cam.x * cos(-d->player.sensi) \
	- d->player.cam.y * sin(-d->player.sensi);
	d->player.cam.y = old_plane_x * sin(-d->player.sensi) \
	+ d->player.cam.y * cos(-d->player.sensi);
}

void	rotate_player_right(t_data *d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->player.dir.x;
	d->player.dir.x = d->player.dir.x * cos(d->player.sensi) \
	- d->player.dir.y * sin(d->player.sensi);
	d->player.dir.y = old_dir_x * sin(d->player.sensi) \
	+ d->player.dir.y * cos(d->player.sensi);
	old_plane_x = d->player.cam.x;
	d->player.cam.x = d->player.cam.x * cos(d->player.sensi) \
	- d->player.cam.y * sin(d->player.sensi);
	d->player.cam.y = old_plane_x * sin(d->player.sensi) \
	+ d->player.cam.y * cos(d->player.sensi);
}
