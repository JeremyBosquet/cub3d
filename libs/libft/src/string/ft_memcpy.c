/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:09:20 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 14:19:41 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memcpy(void *dst, const void *src, uint32_t n)
{
	void	*dest;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = dst;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (dest);
}
