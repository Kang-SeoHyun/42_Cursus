/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:55:32 by seokang           #+#    #+#             */
/*   Updated: 2023/01/08 22:41:43 by seokang          ###   ########.fr       */
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
	int				max_size;
}	t_info;

//push_swap.c
int			main(int ac, char *av[]);

// init_new.c
void		print_error(void);
void		init_stack(t_info *info);
t_node		*init_node(int data);

// push_pop.c
void		push_top(t_stack *stack, t_node *new);
void		push_bottom(t_stack *stack, t_node *new);
t_node		*pop_top(t_stack *stack);
t_node		*pop_bottom(t_stack *stack);

//operations_swap.c
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);

//operations_push.c
void		pa(t_info *info);
void		pb(t_info *info);

//operations_rotate.c
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);

//operations_R_rotate.c
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

//utils_libft.c
int			ft_strlen(char	*s);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);

//utils_split.c
static int	is_charset(char c, char *charset);
static int	count_word(char *str, char *charset);
static char	*str_copy(char **str, char charset);
static char	**free_copy(char **str, int size);
char		**ft_split(char *str, char charset);

//validate.c
static char	*join_args(int ac, char *av[]);
static int	size_check(char const *str, char c);
static int	is_valid_num(char *str);
static void	overlap_dup(t_info *stack_info, int input);
void		validate_args(int ac, char *av[], t_info *stack_info);

//ready_sort.c
void		first_check(t_info	*stack_info);
int			find_max(t_info *stack_info);
void		indexing(t_info *stack_info);
void		stacking(t_info *stack_info);

//sort.c
void		sort_hardcode(t_info *stack_info);
void		sort_array(t_info *stack_info);
void		sorting(t_info *stack_info);
//조금 수정해보기
void		divide_pivot(t_info *stack_info);

//rotate.c
void		get_min_rotate(t_info *stack_info, int *a, int *b);
#endif