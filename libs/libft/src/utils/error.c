/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:44:06 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 18:13:29 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	error(char *message)
{
	ft_putstr(fstderr, RED"error: "END);
	ft_putendl(fstderr, message);
	exit(EXIT_FAILURE);
}
