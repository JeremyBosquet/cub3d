/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:55:25 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 22:04:32 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_textures(t_data *d, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(d->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		error("failed to create texture");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, \
	&tex->endian);
	tex->size = tex->bpp * tex->line_length * tex->endian;
}
