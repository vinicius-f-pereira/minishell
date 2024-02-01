/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:11 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/29 23:29:34 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unsetenv(const char *name)
{
	char	**env_vars;
	char	*temp;
	int		i;

	env_vars = environ_holder(NULL, 0);
	temp = ft_strjoin(name, "=");
	i = -1;
	while (env_vars[++i])
	{
		if (!ft_strncmp(env_vars[i], temp, ft_strlen(temp)))
		{
			free(env_vars[i]);
			while (env_vars[i++ + 1])
				env_vars[i - 1] = env_vars[i];
			env_vars[i] = NULL;
			break ;
		}
	}
	free(temp);
}

int	unset(char **args)
{
	int		i;

	i = 0;
	while (args[++i])
		ft_unsetenv(args[i]);
	return (EXIT_SUCCESS);
}