/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:48:08 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:54:43 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ~~ ---------------------------- Structures ---------------------------- ~~ //

typedef struct s_vect2i
{
	int	x;
	int	y;
}	t_vect2i;

typedef struct s_vect2f
{
	float	x;
	float	y;
}	t_vect2f;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_const
{
	int	win_half_h;
	int	win_half_w;
}	t_const;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int		size;
}	t_img;

typedef struct s_cell
{
	t_img	tex;
	t_rgb	rgb;
	int		color;
	int		nb_amount;
}	t_cell;

typedef struct s_map
{
	t_list		*list;
	t_vect2i	size;
	int			**map;
	int			fd;
}	t_map;

typedef struct s_player
{
	t_vect2f	pos;
	t_vect2i	spawn;
	t_vect2f	dir;
	t_vect2f	cam;
	float		fov;
	float		sensi;
	float		speed;
}	t_player;

typedef struct s_ray
{
	t_vect2f	raydir;
	t_vect2f	delt;
	t_vect2f	sidedist;
	t_vect2f	step;
	t_vect2i	map_pos;
	double		wallx;
	double		tex_pos;
	double		step_wall;
	float		screenx;
	float		raydist;
	int			tex_x;
	int			tex_y;
	int			side;
	int			lineh;
	int			size_cube;
	int			start;
	int			stop;
	bool		done;
}	t_ray;

typedef struct s_press
{
	bool	a;
	bool	d;
	bool	s;
	bool	w;
	bool	left_arrow;
	bool	right_arrow;
	bool	shift;
}	t_press;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_cell		cell[6];
	t_const		cst;
	t_img		img;
	t_press		press;
	void		*mlx;
	void		*win;
	int			offset;
}	t_data;

#endif
