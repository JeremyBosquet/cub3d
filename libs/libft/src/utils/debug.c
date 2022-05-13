/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:47:04 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 18:13:58 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	print_debug(char *file, uint32_t line)
{
	dprintf(fstderr, PURPLE"%s:%d "END"this is debug message\n", file, line);
}

void
	print_debug_string(char *value, char *file, uint32_t line)
{
	dprintf(fstderr, PURPLE"%s:%d "END"%s\n", file, line, value);
}

void
	print_debug_int(uint32_t value, char *file, uint32_t line)
{
	dprintf(fstderr, PURPLE"%s:%d "END"%d\n", file, line, value);
}
