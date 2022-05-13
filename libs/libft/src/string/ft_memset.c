/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:54:51 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 14:23:13 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *b, uint8_t c, uint32_t len)
{
	void	*tmp;

	tmp = b;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (tmp);
}
