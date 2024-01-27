/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:32:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/27 18:49:34 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_initializer(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		ft_putendl_fd("fail to set signals", 1);
		exit (EXIT_FAILURE);
	}
}

int	is_after_prompt(int is_after)
{
	static int	after;

	if (is_after != -1)
		after = is_after;
	return (after);
}
