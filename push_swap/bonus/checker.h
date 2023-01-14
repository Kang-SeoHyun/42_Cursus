/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:15:57 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 08:26:34 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
	int				max_size;
}	t_info;

// init_new.c
void		print_error(void);
void		init_stack(t_info *info);
t_node		*init_node(int data);

// push_pop.c
void		push_top(t_stack *stack, t_node *new);
void		push_bottom(t_stack *stack, t_node *new);
t_node		*pop_top(t_stack *stack);
t_node		*pop_bottom(t_stack *stack);

//utils_split.c
char		**ft_split(const char *s, char c);

//validate.c
void		validate_args(t_info *info, int ac, char *av[]);

//oper_s.c
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);

//oper_p.c
void		pa(t_info *info);
void		pb(t_info *info);

//oper_r.c
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);

//oper_Rr.c
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

//ready_sort.c
int			find_max(t_info *info);
void		indexing(t_info *info);
void		stacking(t_info *info);

//sort.c
void		divide_group(t_info *info);
void		ascending_order(t_info *info);
void		sort_array(t_info *info);
void		start_sorting(t_info *info);

//hard_code.c
void		sort_two(t_info *info);
void		sort_three(t_info *info);

#endif