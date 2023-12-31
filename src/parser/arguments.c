/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:00:43 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/31 00:27:10 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokenize_argument(char **p, t_token **tokens, int *num)
{
	char	*begin = *p;
	while (**p && !ft_isspace(**p) && **p != '&' && **p != '|' \
			&& **p != '(' && **p != ')')
		(*p)++;
	(*tokens)[*num].type = TOKEN_ARGUMENT;
	(*tokens)[*num].value = ft_strndup(begin, (*p - begin));
	(*num)++;
}
