/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:23:28 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/02 13:06:06 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t
	ft_atoi(const char *str)
{
	uint16_t	i;
	int8_t		sign;
	int32_t		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign *= (-1);
	while (str[i] && ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}
