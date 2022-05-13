/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:22:56 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 01:23:39 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool
	ft_isdigit(uint8_t character)
{
	if (character >= '0' && character <= '9')
		return (true);
	else
		return (false);
}
