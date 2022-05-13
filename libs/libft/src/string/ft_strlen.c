/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:43:51 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/03 23:07:09 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t
	ft_strlen(const char *s)
{
	uint32_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

uint32_t
	ft_strlen_charset(const char *s, char c)
{
	uint32_t	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}
