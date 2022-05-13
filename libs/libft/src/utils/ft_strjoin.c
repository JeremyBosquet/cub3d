/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:50:01 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 18:24:47 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	free_strjoin(char *s1, char *s2, uint8_t who_free)
{
	if (who_free == 1)
		free(s1);
	else if (who_free == 2)
		free(s2);
	else if (who_free == 3)
	{
		free(s1);
		free(s2);
	}
}

char
	*ft_strfjoin(const char *s1, const char *s2, uint8_t who_free)
{
	uint16_t	i;
	uint16_t	j;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	free_strjoin((char *)s1, (char *)s2, who_free);
	return (str);
}

char
	*ft_strjoin(const char *s1, const char *s2)
{
	uint16_t	i;
	uint16_t	j;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	return (str);
}
