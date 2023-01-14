/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:42:50 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 08:43:50 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	find_max(t_info *info)
{
	int		i;
	int		change;

	change = -2147483648;
	i = 0;
	while (i < info->size_array)
	{
		if (change < info->array[i])
			change = info->array[i];
		i++;
	}
	i = 0;
	while (i < info->size_array)
	{
		if (change == info->array[i])
		{
			info->array[i] = -2147483648;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	indexing(t_info *info)
{
	int	idx;
	int	*idx_array;
	int	max_idx;

	idx_array = (int *)malloc(sizeof(int) * info->size_array);
	if (!idx_array)
		print_error();
	idx = info->size_array - 1;
	while (idx >= 0)
	{
		max_idx = find_max(info);
		idx_array[max_idx] = idx;
		idx--;
	}
	free(info->array);
	info->array = idx_array;
}

void	stacking(t_info *info)
{
	t_node	*new;
	int		i;

	i = 0;
	while (i < info->size_array)
	{
		new = init_node(info->array[i] + 1);
		push_bottom(info->stack_a, new);
		i++;
	}
	info->size_a = info->size_array;
	info->max_size = info->size_array;
}
