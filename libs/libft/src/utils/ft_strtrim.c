/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:02:11 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:23:47 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strtrim(const char *s1, const char *charset)
{
	uint32_t	s1_len;
	char		*str;

	if (!s1 || !charset)
		return (NULL);
	while (ft_strchr(charset, *s1) != NULL)
		s1++;
	s1_len = ft_strlen(s1);
	while (ft_strchr(charset, s1[s1_len - 1]) != NULL && s1_len != 0)
		s1_len--;
	str = ft_calloc(s1_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1_len--)
		str[s1_len] = s1[s1_len];
	return (str);
}
