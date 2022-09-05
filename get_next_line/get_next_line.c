/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:48 by seokang           #+#    #+#             */
/*   Updated: 2022/09/05 17:53:48 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*baguni_pugi(int fd, char *backup)
{
	char	*buf;
	int		reres;
	char	*new_backup

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	reres = BUFFER_SIZE;
	while (reres == BUFFER_SIZE)
	{
		reres = read(fd, buf, BUFFER_SIZE);
		if (reres == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[reres] = '\0';
		new_backup = ft_strjoin(backup, buf);
		free(backup);
		backup = new_backup;
		if (ft_strchr(buf, '\n'))
			break ;
	}
}

char	*return_mandulgi(char *backup)
{
	
}

char	*next_backup(char *backup)
{
	
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    //if (is_newline() == -1)
	backup = baguni_pugi(fd, backup);
	if (!backup)
		return (NULL);
	buf = return_mandulgi(backup);
	backup = next_backup(backup);
	return (buf);
}
