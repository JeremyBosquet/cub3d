/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:35:14 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/05 22:37:44 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_files(int fd)
{
	if (close(fd) == -1)
		error(CLOSE_ERROR);
}

int	open_files(const char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close_files(fd);
		error(FD_DIR);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(WRONG_FD);
	return (fd);
}
