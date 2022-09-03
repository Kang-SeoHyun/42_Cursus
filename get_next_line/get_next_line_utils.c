/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:52 by seokang           #+#    #+#             */
/*   Updated: 2022/09/03 19:52:48 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *new_str;
        size_t  total_len;

        if (!s1 || !s2)
                return (0);
        total_len = ft_strlen(s1) + ft_strlen(s2);
        new_str = (char *)malloc(sizeof(char) * (total_len + 1));
        if (!new_str)
                return (0);
        *new_str = '\0';
        while (*s1)
                *new_str++ = *s1++;
		while (*s2)
                *new_str++ = *s2++;
        *new_str = '\0';
        s1 = 0;
        s2 = 0;
        return (new_str);
}