/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:04 by seokang           #+#    #+#             */
/*   Updated: 2023/06/05 15:46:05 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx_str;
	size_t	idx_find;

	idx_str = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[idx_str] && idx_str < len)
	{
		idx_find = 0;
		while (haystack[idx_str + idx_find] == needle[idx_find] \
			&& idx_str + idx_find < len)
		{
			idx_find++;
			if (!needle[idx_find])
				return ((char *)&haystack[idx_str]);
		}
		idx_str++;
	}
	return (0);
}
