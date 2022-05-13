/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:49:11 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 15:01:58 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t
	ft_strlcpy(char *dst, const char *src, uint32_t dstsize)
{
	uint16_t	i;
	uint32_t	srcsize;

	if (src == NULL)
	{
		dst = NULL;
		return (0);
	}
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	i = -1;
	while (src[++i] && i < dstsize - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (srcsize);
}

char
	*ft_strncpy(char *dst, char *src, uint16_t len)
{
	uint16_t	i;

	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	while (i++ < len)
		dst[i] = '\0';
	return (dst);
}

char
	*ft_strcpy(char *dst, char *src)
{
	uint16_t	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
