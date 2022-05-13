/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:45:13 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/06 00:34:49 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	treat_spaces(const char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	return (i);
}

void	get_direction(t_dir *dir, char *line)
{
	if (!ft_strncmp("NO", line, 2))
		*dir = dir_no;
	else if (!ft_strncmp("SO", line, 2))
		*dir = dir_so;
	else if (!ft_strncmp("WE", line, 2))
		*dir = dir_we;
	else if (!ft_strncmp("EA", line, 2))
		*dir = dir_ea;
	else if (!ft_strncmp("F ", line, 2))
		*dir = dir_floor;
	else if (!ft_strncmp("C ", line, 2))
		*dir = dir_ceiling;
	else
		error(INVALID_DIR);
}

void	check_data_colors(char *line)
{
	int	i;
	int	nb_coma;

	nb_coma = 0;
	i = -1;
	while (line[++i] && ft_strchr(COLORS_CHARSETS, line[i]))
		if (line[i] == ',')
			nb_coma++;
	if (line[i] != '\0')
		error(MAP_OVERFLOW);
	if (nb_coma != 2)
		error(INVALID_COLOR);
}

int	get_max_width(t_list *list)
{
	t_list	*tmp;
	int		width;

	width = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->width > width)
			width = tmp->width;
		tmp = tmp->next;
	}
	return (width);
}
