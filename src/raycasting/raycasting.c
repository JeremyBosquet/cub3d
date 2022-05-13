/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 02:23:47 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:55:43 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_step(t_data *d, t_ray *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (d->player.pos.x - ray->map_pos.x) * ray->delt.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map_pos.x + 1 - d->player.pos.x) * ray->delt.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (d->player.pos.y - ray->map_pos.y) * ray->delt.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map_pos.y + 1 - d->player.pos.y) * ray->delt.y;
	}
}

static void	dda_algo(t_data *d, t_ray *ray)
{
	while (!ray->done)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->delt.x;
			ray->map_pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->delt.y;
			ray->map_pos.y += ray->step.y;
			ray->side = 1;
		}
		if (d->map.map[ray->map_pos.y][ray->map_pos.x] == wall)
			ray->done = true;
	}
	if (!ray->side)
		ray->raydist = ray->sidedist.x - ray->delt.x;
	else
		ray->raydist = ray->sidedist.y - ray->delt.y;
}

static void	size_rays(t_ray *ray)
{
	ray->lineh = (int)(ray->size_cube / ray->raydist);
	ray->start = -ray->lineh * 0.5 + ray->size_cube * 0.5;
	if (ray->start < 0)
		ray->start = 0;
	ray->stop = ray->lineh * 0.5 + ray->size_cube * 0.5;
	if (ray->stop >= ray->size_cube)
		ray->stop = ray->size_cube - 1;
}

static void	init_rays(t_data *d, t_ray *ray, int i, int nb_rays)
{
	ray->screenx = 2 * i / (float) nb_rays - 1;
	ray->raydir = set_vect2f(d->player.dir.x + d->player.cam.x * ray->screenx, \
	d->player.dir.y + d->player.cam.y * ray->screenx);
	if (ray->raydir.x == 0)
		ray->raydir.x = 1e-30;
	if (ray->raydir.y == 0)
		ray->raydir.y = 1e-30;
	ray->delt = set_vect2f(fabs(1 / ray->raydir.x), fabs(1 / ray->raydir.y));
	ray->map_pos = set_vect2i((int)d->player.pos.x, (int)d->player.pos.y);
}

void	draw_rays(t_data *d, int nb_rays)
{
	t_ray		ray;
	t_vect2i	i;

	i.x = -1;
	while (++i.x < nb_rays)
	{
		init_rays(d, &ray, i.x, nb_rays);
		ray_step(d, &ray);
		ray.done = false;
		dda_algo(d, &ray);
		ray.size_cube = WIN_H - HUD;
		size_rays(&ray);
		draw_walls(d, &ray, i);
		draw_vline(d, &ray, i.x);
	}
}
