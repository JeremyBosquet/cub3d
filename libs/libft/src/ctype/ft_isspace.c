/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:08:36 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 01:13:26 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool
	ft_isspace(uint8_t character)
{
	if (character == ' ' || (character >= '\t' && character <= '\r'))
		return (true);
	else
		return (false);
}
