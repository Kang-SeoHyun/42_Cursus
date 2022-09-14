/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:42:11 by seokang           #+#    #+#             */
/*   Updated: 2022/09/14 21:10:57 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("c.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("\033[0;33mprintf : %s\n\033[0m", str);
		free(str);
	}
}
