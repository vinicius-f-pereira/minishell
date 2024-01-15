/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/15 19:39:46 by bmoretti         ###   ########.fr       */
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
int main(void)
{
	char	*input;
	t_list	*tokens;

	clear_console();
	while (true)
	{
		input = readline("minishell~$ ");
		if (input != NULL && ft_strncmp(input, "exit", 4))
		{
			tokens = tokenizer(input);
			(void)tokens;
			free(input);
		}
		else
			break;
	}
	free(input);
	return (EXIT_SUCCESS);
}
