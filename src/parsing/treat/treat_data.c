/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:54:08 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 22:25:10 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	treat_identifiers(t_data *d, char *line, t_dir *dir)
{
	int	i;

	i = ft_strlen_charset(line, ' ');
	if (i > 2)
		return (0);
	get_direction(dir, line);
	d->cell[*dir].nb_amount++;
	return (i);
}

static int	treat_textures_and_colors(t_data *d, char *line, t_dir *dir)
{
	int	i;
	int	tmp;

	i = ft_strlen_charset(line, ' ');
	tmp = i;
	i += treat_spaces(&line[i]);
	if (line[i] != '\0')
		error(MAP_OVERFLOW);
	line[tmp] = '\0';
	if (check_extensions(line, ".xpm") && *dir < dir_floor)
		fill_textures(d, line, dir);
	else
		fill_colors(d, line, dir);
	return (i);
}

void	treat_data(t_data *d, char *line)
{
	t_dir	dir;
	int		i;

	i = 0;
	i += treat_spaces(&line[i]);
	i += treat_identifiers(d, &line[i], &dir);
	i += treat_spaces(&line[i]);
	if (i == 0)
		error(INVALID_DIR);
	i += treat_textures_and_colors(d, &line[i], &dir);
	i += treat_spaces(&line[i]);
	if (line[i] != '\0')
		error(MAP_OVERFLOW);
}
