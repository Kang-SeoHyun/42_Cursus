/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:45:38 by seokang           #+#    #+#             */
/*   Updated: 2023/06/05 15:45:39 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	char	*total_s;

	if (!s1 || !s2)
		return (0);
	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	total_s = malloc (total_len + 1);
	if (!total_s)
		return (0);
	while (i < ft_strlen(s1))
	{
		total_s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		total_s[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	total_s[total_len] = '\0';
	return (total_s);
}
