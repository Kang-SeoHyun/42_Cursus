/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:56:54 by seokang           #+#    #+#             */
/*   Updated: 2022/09/16 15:34:53 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*s;
	int		fd;
	int		i;

	i = 0;
	fd = open("b.txt", O_RDONLY);
	while (i++ < 3)
	{
		s = get_next_line(fd);
		printf("\n!!!!!나왔다: %s!!!!!다음 돌리기\n", s);
		free(s);
		sleep(2);
	}
	return (0);
}
