/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:17:08 by seokang           #+#    #+#             */
/*   Updated: 2023/01/02 16:46:20 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int ac, char *av[])
{
	int			i;
	int			len;
	char		*str;
	int			idx;
	int			j;

	i = 0;
	len = 0;
	while (++i < ac)
		len += ft_len(av[i]);
	str = (char *)malloc(sizeof(char) * (len + ac));
	if (!str)
		return (NULL);
	i = 0;
	idx = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
			str[idx++] = av[i][j++];
		str[idx++] = ' ';
	}
	str[idx] = '\0';
	return (str);
}

static int	size_check(char const *str, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static int	is_valid_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("+-0123456789", str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	overlap_dup(t_info *stack_info, int input)
{
	int	i;
	int	*tmp;

	i = -1;
	while (++i < stack_info->size_array)
	{
		if (stack_info->array[i] == input)
			print_error();
	}
	stack_info->size_array++;
	tmp = (int *)malloc(sizeof(int) * stack_info->size_array);
	if (!tmp)
		print_error();
	if (stack_info->size_array == 1)
		tmp[0] = input;
	else
	{
		i = -1;
		while (++i < stack_info->size_array - 1)
			tmp[i] = stack_info->array[i];
		tmp[i] = input;
	}
	free(stack_info->array);
	stack_info->array = tmp;
}

void	validate_args(int ac, char *av[], t_info *stack_info)
{
	int		i;
	char	*args;
	char	**split_av;
	int		av_size;
	t_node	*new_node;

	args = join_args(ac, av);
	split_av = ft_split(args, ' ');
	av_size = size_check(args, ' ');
	free(args);
	i = 0;
	while (i < av_size)
	{
		if (!is_valid_num(split_av[i]))
			print_error();
		new_node = init_node(ft_atoi(split_av[i]));
		free(split_av[i]);
		overlap_dup(stack_info, new_node->data);
		i++;
		free(new_node);
	}
	free(split_av);
}
