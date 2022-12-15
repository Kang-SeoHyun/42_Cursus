/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:17:08 by seokang           #+#    #+#             */
/*   Updated: 2022/12/15 23:37:52 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join_args(int ac, char *av[])
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
		if (!)
	}
	free(split_av);
}
