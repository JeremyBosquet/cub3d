/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:26 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:23:28 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t
	word_length(char *string, char charset)
{
	uint32_t	i;

	if (!string || !charset)
		return (0);
	i = 0;
	while (string[i] && string[i] != charset)
		i++;
	return (i);
}

static uint32_t
	number_of_words(char *string, char charset)
{
	uint32_t	i;
	uint32_t	length;

	i = 0;
	while (*string)
	{
		while (*string && *string == charset)
			string++;
		length = word_length(string, charset);
		string += length;
		if (length)
			i++;
	}
	return (i);
}

static void
	free_split(char ***s, uint16_t size)
{
	uint16_t	i;

	if (!(*s))
		return ;
	i = -1;
	while (++i < size)
		free((*s)[i]);
	free(*s);
	s = NULL;
}

char
	**ft_split(const char *string, char charset)
{
	char		**dest;
	uint32_t	size;
	uint32_t	length;
	uint16_t	i;

	size = number_of_words((char *)string, charset);
	dest = ft_calloc((size + 1), sizeof(char *));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (string && *string && *string == charset)
			string++;
		length = word_length((char *)string, charset);
		dest[i] = ft_strndup(string, length);
		if (!dest[i])
			free_split(&dest, i);
		string += length;
	}
	return (dest);
}
