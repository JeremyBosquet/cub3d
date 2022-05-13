/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:10:49 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 14:04:27 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean(t_data *d)
{
	int		i;
	t_list	*list;

	i = -1;
	while (++i < 6)
	{
		free(d->cell[i].tex.path);
		if (i < dir_floor)
			mlx_destroy_image(d->mlx, d->cell[i].tex.img);
	}
	i = -1;
	list = d->map.list;
	while (++i < d->map.size.y)
		free(d->map.map[i]);
	free(d->map.map);
	ft_lstclear(&d->map.list, free);
	printf(GREEN"\n\t~ The program quit correctly. ~ \n\n"END);
}
