/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:55:32 by seokang           #+#    #+#             */
/*   Updated: 2022/12/10 20:49:17 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
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
	int				size_array;
}	t_info;

// stack_make.c
void	init_stack(t_info *info);
t_node	*get_new_node(int num);

// push_pop.c
void	push_top(t_stack *stack, t_node *new);
void	push_bottom(t_stack *stack, t_node *new);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

//push_swap.c
void	print_error(void);
int		main(int ac, char *av[]);

//operations_swap.c
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);

//operations_push.c
void	pa(t_info *info);
void	pb(t_info *info);

//operations_rotate.c
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);

//operations_R_rotate.c
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

#endif