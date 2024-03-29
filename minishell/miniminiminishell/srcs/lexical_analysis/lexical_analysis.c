/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:30:56 by seokang           #+#    #+#             */
/*   Updated: 2023/05/23 09:30:58 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*lexical_analysis(t_info *info, char *input)
{
	t_token	*token_list;

	token_list = create_token(input, TOKEN_TYPE_CHUNK);
	handle_heredoc_limiter(info, token_list);
	handle_quotes(info, token_list);
	handle_environment_variables(info, token_list);
	seperate_token_by_arg(token_list, " ");
	seperate_token_by_arg(token_list, "|");
	seperate_token_by_arg(token_list, "<<");
	seperate_token_by_arg(token_list, ">>");
	seperate_token_by_arg(token_list, "<");
	seperate_token_by_arg(token_list, ">");
	handle_chunk(&token_list);
	merge_continuous_argv_token(&token_list);
	remove_space_token(&token_list);
	return (token_list);
}
