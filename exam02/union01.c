/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:36:48 by seokang           #+#    #+#             */
/*   Updated: 2023/02/26 21:43:51 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	ascii[256] = {0, };
	int	i;
	int	j;

	i = 1;
	if (ac == 3)
	{
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if (ascii[(int)av[i][j]] == 0)
				{
					write (1, &av[i][j], 1);
					ascii[(int)av[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}