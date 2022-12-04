/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:55:32 by seokang           #+#    #+#             */
/*   Updated: 2022/12/04 22:42:51 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_node
{
	int				val;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_var
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				*list;
	int				list_size;
	int				a_size;
	int				b_size;
	int				max_size;
	int				*pivot_arr;
}	t_var;

// stack.c
void	init(t_var *var);

#endif