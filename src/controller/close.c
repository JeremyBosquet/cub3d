/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:59:01 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 02:01:40 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_data *d)
{
	if (d->img.img)
		mlx_destroy_image(d->mlx, d->img.img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	clean(d);
	exit(0);
}
