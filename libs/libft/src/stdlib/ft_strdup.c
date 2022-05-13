/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:31:31 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/02 15:07:28 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strndup(const char *s1, uint32_t n)
{
	char	*ptr;

	ptr = ft_calloc(n + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, n + 1);
	return (ptr);
}

char
	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
