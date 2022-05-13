/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:46:09 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/05 21:54:52 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

// ~~ ------------------------------- Enums ------------------------------ ~~ //

typedef enum e_dir
{
	dir_no,
	dir_so,
	dir_we,
	dir_ea,
	dir_floor,
	dir_ceiling,
}	t_dir;

typedef enum e_map_charset
{
	empty,
	wall,
	space,
}	t_map_charset;

#endif
