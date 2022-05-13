/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:44:49 by mmosca            #+#    #+#             */
/*   Updated: 2022/05/13 12:28:18 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ~~ ----------------------------- Includes ----------------------------- ~~ //

# include "../libs/libft/inc/libft.h"
# include "../libs/minilibx/mlx.h"

# include <fcntl.h>
# include <math.h>

# include "enums.h"
# include "key.h"
# include "prototypes.h"
# include "structures.h"
# include "verbose.h"

// ~~ ------------------------------ Defines ----------------------------- ~~ //

# define WIN_W 1920
# define WIN_H 1080
# define HUD 190
# define MAP_CHARSETS "01NSWE "
# define COLORS_CHARSETS "0123456789, "

#endif
