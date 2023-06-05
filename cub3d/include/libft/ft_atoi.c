/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:42:54 by seokang           #+#    #+#             */
/*   Updated: 2023/06/05 15:42:56 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	else if (*str == '+')
		str++;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		if (sign * res > 2147483647)
			return (-1);
		else if (sign * res < -2147483648)
			return (0);
		else
			res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
