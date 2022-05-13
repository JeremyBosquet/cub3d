/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:35:15 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 13:43:21 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	create_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 16 | g << 8 | b);
}

void	str_to_rgb(uint32_t *v_value, char *line)
{
	*v_value = ft_atoi(line);
	if (*v_value < 0 || *v_value > 255)
		error(INVALID_COLOR);
}
