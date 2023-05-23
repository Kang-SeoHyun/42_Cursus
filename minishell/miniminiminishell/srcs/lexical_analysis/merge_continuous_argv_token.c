/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_continuous_argv_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:30:54 by seokang           #+#    #+#             */
/*   Updated: 2023/05/23 09:30:55 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// ARGV, ARGV => ARGV
void	merge_continuous_argv_token(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;
	char	*merge_str;

	head = token_list;
	cur = *token_list;
	while (cur && cur->next)
	{
		if (cur->type == TOKEN_TYPE_ARGV && cur->next->type == TOKEN_TYPE_ARGV)
		{
			merge_str = ft_strjoin(cur->string, cur->next->string);
			free(cur->string);
			cur->string = merge_str;
			delete_token(cur->next, head);
		}
		else
			cur = cur->next;
	}
}
