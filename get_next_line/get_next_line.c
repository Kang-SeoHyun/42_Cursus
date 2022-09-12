/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/12 17:51:21 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_baguni_pugi(int fd, char *backup, int reres)
{
	char	*baguni;

	baguni = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!baguni)
		return (NULL);
	while (reres == BUFFER_SIZE)
	{
		reres = read(fd, baguni, BUFFER_SIZE);
		if (reres == -1)
		{
			free(baguni);
			return (NULL);
		}
		// if (reres != BUFFER_SIZE)
		// {
		// 	return 
		// }
		baguni[reres] = '\0';
		backup = ft_strjoin(backup, baguni);
		if (ft_strchr(baguni, '\n'))
			break ;
	}
	free(baguni);
	return (backup);
}

char	*ft_na_nugi(char	**buf, char *backup)
{
	int		idx;
	int		i;

	idx = 0;
	i = 0;
	while (backup[idx] && backup[idx] != '\n')
		idx++;
	if (backup[idx] == '\n')
		i++;
	*buf = (char *)malloc(sizeof(char) * (idx + i + 1));
	if (!*buf)
		return (NULL);
	i = -1;
	while (++i < idx)
		(*buf)[i] = backup[i];
	if (backup[idx] == '\n')
		(*buf)[i++] = '\n';
	(*buf)[i] = '\0';
	backup = ft_strchr(backup, '\n') + 1;
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup == 0)	// ㅊㅓㅅ호출
	{
		backup = (char *)malloc(sizeof(char) * 1);
		*backup = '\0';
	}
	backup = ft_baguni_pugi(fd, backup, BUFFER_SIZE);
	if (!backup)
		return (NULL);
	backup = ft_na_nugi(&buf, backup);
	return (buf);
}
