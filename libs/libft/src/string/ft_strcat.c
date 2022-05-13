/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:02:23 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 15:14:47 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t
	ft_strlcat(char *dst, const char *src, uint32_t dstsize)
{
	uint16_t	i;
	uint16_t	j;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = -1;
	while (src[++j] && i + j + 1 < dstsize)
		dst[i + j] = src[j];
	if (i != dstsize)
		dst[i + j] = '\0';
	return (ft_strlen(dst) + i);
}

char
	*ft_strncat(char *dst, char *src, uint16_t size)
{
	uint32_t	i;
	uint16_t	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j] && j < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}

char
	*ft_strcat(char *s1, char *s2)
{
	uint32_t	i;
	uint16_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
