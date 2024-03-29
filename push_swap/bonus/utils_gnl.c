/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:52 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:05:32 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	char	*new_str;
	int		i;

	if (!s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	new_str[i] = '\0';
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strndup(char *s, int start, int num)
{
	int		idx_s;
	int		idx_t;
	char	*temp;

	idx_s = 0;
	idx_t = 0;
	temp = (char *)malloc(sizeof(char) * num + 1);
	if (!temp)
		return (NULL);
	while (s[idx_s] && idx_t < num)
		temp[idx_t++] = s[start + idx_s++];
	temp[idx_t] = '\0';
	return (temp);
}
