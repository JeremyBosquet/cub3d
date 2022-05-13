/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:12:39 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/02 21:37:49 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	*ft_free(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*gnl_line(char *buffer)
{
	int		i;
	char	*string;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	string = ft_calloc(i + 1, sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		string[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		string[i++] = '\n';
	string[i] = '\0';
	return (string);
}

char	*gnl_save(char *buffer)
{
	int		i;
	int		j;
	char	*string;

	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (ft_free(buffer));
	string = ft_calloc((ft_strlen(buffer) - i) + 1, sizeof(char));
	if (!string)
		return (NULL);
	i++;
	while (buffer[i])
		string[j++] = buffer[i++];
	string[j] = '\0';
	ft_free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;
	static char	*tmp = NULL;

	bytes_read = 1;
	if (!tmp)
		tmp = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || !buffer || bytes_read < 0)
		return (ft_free(buffer), ft_free(tmp));
	while (bytes_read != 0 && !ft_strchr(tmp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(buffer));
		buffer[bytes_read] = '\0';
		tmp = ft_strfjoin(tmp, buffer, 1);
	}
	ft_free(buffer);
	line = gnl_line(tmp);
	tmp = gnl_save(tmp);
	return (line);
}
