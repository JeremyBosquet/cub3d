/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:33:18 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:40:22 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	uint16_t	i;
	char		*str;

	if (!s)
		return (NULL);
	str = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f(i, s[i]);
	return (str);
}
