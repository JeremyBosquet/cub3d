/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:13:23 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:56:21 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vline(t_data *d, t_ray *ray, int x)
{
	int	i;

	i = -1;
	while (++i < ray->start)
		my_mlx_put_pixel(d, x, i, d->cell[dir_ceiling].color);
	while (i < ray->stop)
		i++;
	while (i < WIN_H - HUD)
	{
		my_mlx_put_pixel(d, x, i, d->cell[dir_floor].color);
		i++;
	}
}

void	get_dir_wall(t_ray *ray, t_dir *dir)
{
	if (ray->side == 0 && ray->raydir.x > 0)
		*dir = dir_ea;
	else if (ray->side == 0 && ray->raydir.x < 0)
		*dir = dir_we;
	else if (ray->side == 1 && ray->raydir.y > 0)
		*dir = dir_so;
	else if (ray->side == 1 && ray->raydir.y < 0)
		*dir = dir_no;
}

void	draw_walls(t_data *d, t_ray *ray, t_vect2i i)
{
	t_dir	dir;

	get_dir_wall(ray, &dir);
	if (ray->side == 0)
		ray->wallx = d->player.pos.y + ray->raydist * ray->raydir.y;
	else
		ray->wallx = d->player.pos.x + ray->raydist * ray->raydir.x;
	ray->wallx -= floor(ray->wallx);
	ray->tex_x = (int)(ray->wallx * (double)d->cell[dir].tex.width);
	if (ray->side == 0 && ray->raydir.x > 0)
		ray->tex_x = d->cell[dir].tex.width - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir.y < 0)
		ray->tex_x = d->cell[dir].tex.width - ray->tex_x - 1;
	ray->step_wall = 1.0 * d->cell[dir].tex.width / ray->lineh;
	ray->tex_pos = (ray->start - (WIN_H - HUD) * 0.5 + ray->lineh * 0.5) \
	* ray->step_wall;
	i.y = ray->start - 1;
	while (++i.y < ray->stop)
	{
		ray->tex_y = (int)ray->tex_pos & (d->cell[dir].tex.width - 1);
		ray->tex_pos += ray->step_wall;
		my_mlx_put_pixel(d, i.x, i.y, \
		get_pixel_color(&d->cell[dir].tex, ray->tex_x, ray->tex_y));
	}
}
