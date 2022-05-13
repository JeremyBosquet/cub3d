/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:54:36 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 00:50:07 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	treat_map(t_data *d, char *line)
{
	char	*tmp;
	int		size;

	size = ft_strlen(line) - 1;
	while (size >= 0 && line[size] && line[size] == ' ')
		size--;
	size++;
	tmp = ft_strndup(line, size + 1);
	if (!tmp)
		error(OUT_OF_MEM);
	ft_lstadd_back(&d->map.list, ft_lstnew(tmp, ft_strlen(tmp)));
}
