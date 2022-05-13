/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:47:07 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:55:47 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "structures.h"

//	~~ –––––––––––––––––––––––––––– Prototypes ––––––––––––––––––––––––––– ~~ //

//	~~	Controller –––––––––––––––––––––

//	~	close.c
int			close_window(t_data *d);

//	~	controller.c
int			unpress_key(int keycode, t_data *d);
int			controller(int keycode, t_data *d);

//	~	mouse.c
void		turn_view_with_mouse(t_data *d);

//	~	player.c
void		move_player(t_data *d);
void		rotate_player_left(t_data *d);
void		rotate_player_right(t_data *d);

//	~~	Hud ––––––––––––––––––––––––––––

//	~	hud.c
void		draw_hud(t_data *d);

//	~	minimap.c
void		update_minimap(t_data *d, int x, int y);
void		draw_minimap(t_data *d);

//	~~	Parsing ––––––––––––––––––––––––

//	~	treat_data.c
void		treat_data(t_data *d, char *line);

//	~	treat_map.c
void		treat_map(t_data *d, char *line);

//	~	check.c
void		map_is_close(t_data *d);

//	~	fill.c
void		fill_textures(t_data *d, char *line, t_dir *dir);
void		fill_colors(t_data *d, char *line, t_dir *dir);
void		fill_map(t_data *d);

//	~	parsing.c
void		parsing(int argc, char **argv, t_data *d);

//	~	utils.c
int			treat_spaces(const char *line);
void		get_direction(t_dir *dir, char *line);
void		check_data_colors(char *line);
int			get_max_width(t_list *list);

//	~~	Raycasting –––––––––––––––––––––

//	~	raycasting.c
void		draw_rays(t_data *d, int nb_rays);

//	~	raycasting_utils.c
void		draw_vline(t_data *d, t_ray *ray, int x);
void		get_dir_wall(t_ray *ray, t_dir *dir);
void		draw_walls(t_data *d, t_ray *ray, t_vect2i i);

//	~~	Structures –––––––––––––––––––––

//	~	clean.c
void		clean(t_data *d);

//	~	init.c
void		init(t_data *d);

//	~~	Utils ––––––––––––––––––––––––––

//	~	draw.c
void		draw_square(t_data *d, int x, int y, int color);

//	~	extensions.c
bool		check_extensions(const char *path, const char *extension);

//	~	files.c
void		close_files(int fd);
int			open_files(const char *path);

//	~	logs.c
void		logs(t_data *d);

//	~	mlx_pixel.c
void		my_mlx_put_pixel(t_data *d, int x, int y, int color);
int			get_pixel_color(t_img *img, int x, int y);

//	~	rgb.c
int32_t		create_rgb(uint8_t r, uint8_t g, uint8_t b);
void		str_to_rgb(uint32_t *v_value, char *line);

//	~	textures.c
void		create_textures(t_data *d, t_img *texture, char *path);

//	~	vector.c
t_vect2i	set_vect2i(int x, int y);
t_vect2f	set_vect2f(float x, float y);

#endif
