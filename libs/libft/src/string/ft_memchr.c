/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:11:57 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 15:13:40 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memchr(const void *s, uint8_t c, uint32_t n)
{
	while (n--)
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((unsigned char *)s);
	return (NULL);
}
