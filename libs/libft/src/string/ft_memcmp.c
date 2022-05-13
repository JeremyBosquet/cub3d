/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:14:53 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 15:17:00 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t
	ft_memcmp(const void *s1, const void *s2, uint32_t n)
{
	while (n--)
		if (*(unsigned char *)s1++ - *(unsigned char *)s2++ != 0)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
