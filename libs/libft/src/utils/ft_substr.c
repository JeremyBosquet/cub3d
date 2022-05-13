/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:56:49 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:01:17 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint16_t
	len_to_copy(char *s, uint32_t start, uint32_t len)
{
	uint16_t	i;
	uint16_t	length;

	i = -1;
	length = 0;
	while (s[++i] && length < len)
		if (i >= start)
			length++;
	return (length);
}

char
	*ft_substr(const char *s, uint32_t start, uint32_t len)
{
	uint16_t	i;
	uint16_t	length;
	char		*str;

	if (!s)
		return (NULL);
	length = len_to_copy((char *)s, start, len);
	str = ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < length)
		str[i] = s[start++];
	return (str);
}
