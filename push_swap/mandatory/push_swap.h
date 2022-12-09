/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:55:32 by seokang           #+#    #+#             */
/*   Updated: 2022/12/09 18:12:49 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	struct s_node	*up;
	int				data;
	struct s_node	*down;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_info
{
	struct s_stack	*stack_a;
	int				size_a;
	struct s_stack	*stack_b;
	int				size_b;
	int				*array;
}	t_info;

// stack_make.c
void	init(t_info *var);
t_node	*get_new_node(int num);

// push_pop.c
void	push_top(t_stack *stack, t_node *new);
void	push_bottom(t_stack *stack, t_node *new);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

#endif