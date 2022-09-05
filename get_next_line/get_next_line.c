/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/05 21:59:03 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_baguni_pugi(int fd, char *backup, int reres)
{
	char	*buf;
	char	*new_backup;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (reres == BUFFER_SIZE)
	{
		reres = read(fd, buf, BUFFER_SIZE);
		if (reres == -1)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		buf[reres] = '\0';
		new_backup = ft_strjoin(backup, buf);
		free(backup);
		backup = new_backup;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (backup);
}

char	*ft_na_nugi(char	**buf, char *backup)
{

	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup == 0)
	{
		backup = malloc(sizeof(char) * 1);
		*backup = '\0';
	}
	backup = ft_baguni_pugi(fd, backup, BUFFER_SIZE);
	if (!backup)
		return (NULL);
	backup = ft_na_nugi(&buf, backup);
	return (buf);
}
