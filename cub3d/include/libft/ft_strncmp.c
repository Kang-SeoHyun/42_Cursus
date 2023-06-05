/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:00 by seokang           #+#    #+#             */
/*   Updated: 2023/06/05 15:46:00 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (n--)
	{
		if (!s1[idx] && !s2[idx])
			return (0);
		if (s1[idx] != s2[idx])
			return ((const unsigned char)s1[idx] \
				- (const unsigned char)s2[idx]);
		idx++;
	}
	return (0);
}
