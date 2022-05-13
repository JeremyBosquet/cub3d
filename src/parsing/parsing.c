/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:15:31 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 18:19:56 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	treat_line(t_data *d, char *line, char *old, bool *map)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && ft_strchr(MAP_CHARSETS, line[i]))
		i++;
	if (line[i] != '\0')
	{
		j = 0;
		while (old && old[j] && ft_strchr(MAP_CHARSETS, old[j]))
			j++;
		i = treat_spaces(old);
		if (old && old[i] != '\0' && old[j] == '\0')
			error(MAP_OVERFLOW);
		treat_data(d, line);
	}
	else
	{
		*map = true;
		treat_map(d, line);
	}
}

static void	treat_lines(t_data *d, bool *map)
{
	char	*line;
	char	*old;
	int		size;

	old = NULL;
	line = get_next_line(d->map.fd);
	while (line)
	{
		if (*map && line[0] == '\n')
			error(INVALID_DATA_MAP);
		size = ft_strlen(line) - 1;
		if (size > 0 && line[size] == '\n')
			line[size] = '\0';
		if ((size + 1) != treat_spaces(line))
		{
			treat_line(d, line, old, map);
			free(old);
			old = ft_strdup(line);
			if (!old)
				error(OUT_OF_MEM);
		}
		free(line);
		line = get_next_line(d->map.fd);
	}
	free(old);
}

static void	check_map(t_data *d)
{
	t_list	*tmp;
	int		i;
	int		spawn_point;

	spawn_point = 0;
	tmp = d->map.list;
	while (tmp)
	{
		i = -1;
		while (tmp->line[++i])
			if (ft_strchr("NSWE", tmp->line[i]))
				spawn_point++;
		tmp = tmp->next;
	}
	if (spawn_point != 1)
		error(INVALID_SPAWN);
	map_is_close(d);
}

void	parsing(int argc, char **argv, t_data *d)
{
	int		i;
	bool	map;

	if (argc != 2)
		error(INVALID_NB_ARG);
	if (!check_extensions(argv[1], ".cub"))
		error(WRONG_FILE_EXT);
	d->map.fd = open_files(argv[1]);
	map = false;
	treat_lines(d, &map);
	d->map.size = set_vect2i(get_max_width(d->map.list), \
	ft_lstsize(d->map.list));
	fill_map(d);
	check_map(d);
	i = -1;
	while (++i < 6)
	{
		if (d->cell[i].nb_amount != 1)
			error(WRONG_PROPERTIES);
		if (i < dir_floor && !d->cell[i].tex.path)
			error(BAD_TEXTURES);
	}
	close_files(d->map.fd);
}
