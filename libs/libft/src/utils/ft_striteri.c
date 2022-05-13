/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:39:58 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:42:57 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	uint16_t	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		f(i, s[i]);
}
