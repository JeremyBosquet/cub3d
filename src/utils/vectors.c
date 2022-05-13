/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:04:55 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/05 22:11:37 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect2i	set_vect2i(int x, int y)
{
	t_vect2i	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vect2f	set_vect2f(float x, float y)
{
	t_vect2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
