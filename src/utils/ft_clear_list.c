/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:05:25 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/19 01:18:05 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_list(char ***list)
{
	int		i;

	if (!*list)
		return ;
	i = 0;
	while ((*list)[i])
	{
		free((*list)[i]);
		(*list)[i++] = NULL;
	}
	free(*list);
	*list = NULL;
}

void	close_fds(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	fd_keeper(NULL, 0, 1);
}
