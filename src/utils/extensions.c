/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:18:21 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/05 22:21:14 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_extensions(const char *path, const char *extension)
{
	int	path_len;
	int	ext_len;

	if (!path || !extension)
		return (false);
	path_len = ft_strlen(path);
	ext_len = ft_strlen(extension);
	if (ext_len > path_len || ft_strncmp(&path[path_len - ext_len], extension, \
	ext_len))
		return (false);
	else
		return (true);
}
