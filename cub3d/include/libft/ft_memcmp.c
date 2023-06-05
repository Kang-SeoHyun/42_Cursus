/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:44:39 by seokang           #+#    #+#             */
/*   Updated: 2023/06/05 15:44:40 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t count)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	int					res;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (count--)
	{
		res = *(s1++) - *(s2++);
		if (res)
			return (res);
	}
	return (0);
}
