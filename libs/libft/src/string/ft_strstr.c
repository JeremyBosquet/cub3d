/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:17:44 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 15:26:50 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, uint32_t len)
{
	uint16_t	i;
	uint16_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (!needle[i])
			return ((char *)&haystack[i]);
	}
	return (NULL);
}

char
	*ft_strstr(const char *haystack, const char *needle)
{
	uint16_t	i;
	uint16_t	position;

	if (!needle[0])
		return ((char *)haystack);
	position = -1;
	while (haystack[++position])
	{
		if (haystack[position] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[position + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[position]);
		}
	}
	return (NULL);
}
