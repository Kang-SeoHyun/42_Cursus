/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_environment_variables.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:31:04 by seokang           #+#    #+#             */
/*   Updated: 2023/05/23 09:31:05 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	convert_result_to_token(t_token *token_list, char **strs)
{
	t_token	*temp;

	temp = token_list->next;
	token_list->next = NULL;
	free(token_list->string);
	token_list->string = ft_strdup(strs[0]);
	if (strs[1][0])
		add_token(&token_list, create_token(strs[1], TOKEN_TYPE_ARGV));
	if (strs[3][0])
	{
		add_token(&token_list, create_token(strs[2], TOKEN_TYPE_SPACE));
		add_token(&token_list, create_token(strs[3], TOKEN_TYPE_ARGV));
	}
	token_list = add_token(&token_list, create_token(strs[4],
				TOKEN_TYPE_CHUNK));
	free_2d_arr(strs);
	token_list->next = temp;
}

// CHUNK => CHUNK, ARGV, SPACE, ARGV, CHUNK
void	handle_environment_variables(t_info *info, t_token *token_list)
{
	char	**strs;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = seperate_environment_variables(info, token_list->string);
			if (strs)
				convert_result_to_token(token_list, strs);
		}
		token_list = token_list->next;
	}
}
