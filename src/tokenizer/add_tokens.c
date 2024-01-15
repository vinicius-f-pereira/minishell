/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/14 05:22:03 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_token(t_list *tokens,
				const char **start, const char **mover, int token_type)
{
	t_element	*el;
	t_token		*content;

	content = ft_calloc(1, sizeof(t_token));
	if (!content)
		panic_tokenizer("memory allocation failure\n");
	content->str = ft_strndup(*start, *mover - *start);
	if (!content->str)
		panic_tokenizer("memory allocation failure\n");
	content->type = token_type;
	el = ft_lstnewelement(content);
	if (!el)
		panic_tokenizer("memory allocation failure\n");
	ft_lstadd_back(tokens, el);
	if (**mover)
		ft_skip_spaces(mover);
	*start = *mover;
	if (**mover)
		(*mover)++;
}

void	add_quotes_token(t_list *tokens,
					const char **start, const char **mover, int token_type)
{
	char	quote_type;

	quote_type = **start;
	(*mover)++;
	if (**mover)
		while (**mover != quote_type)
			(*mover)++;
	if (**mover)
		(*mover)++;
	add_token(tokens, start, mover, token_type);
}

void	add_symbols_token(t_list *tokens,
					const char **start, const char **mover, int token_type)
{
	if (token_type == AND || token_type == OR || token_type == HEREDOC \
		|| token_type == APPEND)
		(*mover)++;
	add_token(tokens, start, mover, token_type);
}