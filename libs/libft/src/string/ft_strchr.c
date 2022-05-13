/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:00:17 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/02 21:35:41 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strchr(const char *s, int32_t c)
{
	uint16_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

char
	*ft_strrchr(const char *s, int32_t c)
{
	uint32_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}
