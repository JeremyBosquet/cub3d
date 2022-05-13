/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:06:22 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/07 16:57:20 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// ~~ ---------------------------- Includes ------------------------------ ~~ //

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include "ft_enums.h"
# include "ft_prototypes.h"
# include "ft_structures.h"
# include "ft_verbose.h"

# define BUFFER_SIZE 32

// # define debug print_debug(__FILE__, __LINE__)
// # define idebug(x) print_debug_int(x, __FILE__, __LINE__)
// # define sdebug(x) print_debug_string(x, __FILE__, __LINE__)

# define END "\033[0m"
# define GREY "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"

#endif
