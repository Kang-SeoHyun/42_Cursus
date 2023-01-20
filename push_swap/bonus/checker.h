/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:55:32 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:36:13 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

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
	long long		*array;
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

//utils_libft.c
int			ft_strlen(char	*s);
char		*ft_strchr(const char *s, int c);
long long	ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);

//utils_split.c
char		**ft_split(const char *s, char c);

//validate.c
void		validate_args(t_info *info, int ac, char *av[]);

//utils_gnl.c
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(char *s, int start, int num);

//get_next_line.c
char		*get_next_line(int fd);

//check_here.c
void		stacking(t_info *info);
void		command_check(char *op, t_info *info);
int			sort_check(t_info	*info);
void		checker(t_info *info);

#endif