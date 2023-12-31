/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/08 02:57:41 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
	/* display the prompt */
	/* read user input */
	/* parser user input into commands and expand variables if have one. */
	/* search the command */
	/* create a child process (fork) */
	/* execute the command(s) (execv)*/
	/* wait for command completion */
	/* need to finish this little guide */
	/* remember to use extern **environ */
int	main(void)
{
	char	*input;

	clear_console();
	while (true)
	{
		input = readline("minishell~$ ");
		if (input != NULL && ft_strncmp(input, "exit", 4))
		{
			printf("%s\n", input);
			free (input);
		}
		else
			break;
	}
	free(input);
	return (EXIT_SUCCESS);
}
