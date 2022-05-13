/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:27:55 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/02 21:41:00 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_calloc(uint32_t count, uint32_t size)
{
	char		*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, count * size));
}
