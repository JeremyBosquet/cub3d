/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 02:11:48 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:03:42 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_put_pixel(t_data *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_W - 1 || y > WIN_H - 1)
		return ;
	dst = d->img.addr + (y * d->img.line_length + x * (d->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
