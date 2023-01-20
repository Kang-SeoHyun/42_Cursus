/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:03:34 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:08:43 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stacking(t_info *info)
{
	t_node	*new;
	int		i;

	i = 0;
	while (i < info->size_array)
	{
		new = init_node(info->array[i] + 1);
		if (!new)
			print_error();
		push_bottom(info->stack_a, new);
		i++;
	}
	info->size_a = info->size_array;
	info->max_size = info->size_array;
}

void	command_check(char *op, t_info *info)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(info);
	else if (!ft_strcmp(op, "sb\n"))
		sb(info);
	else if (!ft_strcmp(op, "ss\n"))
		ss(info);
	else if (!ft_strcmp(op, "pa\n"))
		pa(info);
	else if (!ft_strcmp(op, "pb\n"))
		pb(info);
	else if (!ft_strcmp(op, "ra\n"))
		ra(info);
	else if (!ft_strcmp(op, "rb\n"))
		rb(info);
	else if (!ft_strcmp(op, "rr\n"))
		rr(info);
	else if (!ft_strcmp(op, "rra\n"))
		rra(info);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(info);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(info);
	else
		print_error();
}

int	sort_check(t_info	*info)
{
	int		size;
	int		check;
	t_node	*tmp;

	size = info->size_array;
	check = 0;
	tmp = info->stack_a->top->next;
	if (info->size_a != info->size_array)
		return (0);
	while (size > 1)
	{
		if (tmp->data > tmp->next->data)
			check++;
		size--;
		tmp = tmp->next;
	}
	if (check == info->size_array - 1)
		return (1);
	return (0);
}

void	checker(t_info *info)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		command_check(op, info);
		free (op);
	}
	if (sort_check(info) == 1 && !(info->size_b))
		write(1, "OK\n", 3);
	else if (sort_check(info) == 0 || info->size_b)
		write(1, "KO\n", 3);
	else
		write(1, "Error\n", 6);
}
