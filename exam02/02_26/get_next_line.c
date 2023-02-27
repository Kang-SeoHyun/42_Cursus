/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:50:42 by seokang           #+#    #+#             */
/*   Updated: 2023/02/26 22:09:00 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line = malloc(10000);
	char *word = line;

	while(read(fd, word, 1) > 0 && *word++ != '\n')

	return ((word > line) ? (*word = 0, line) : (free(line), NULL));
}
