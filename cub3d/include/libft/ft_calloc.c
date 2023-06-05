/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:43:07 by seokang           #+#    #+#             */
/*   Updated: 2023/06/05 15:43:08 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((count == SIZE_MAX && size > 1) || (count > 1 && size == SIZE_MAX))
		return (NULL);
	p = malloc(size * count);
	if (!p)
		return (0);
	ft_memset(p, 0, size * count);
	return (p);
}
