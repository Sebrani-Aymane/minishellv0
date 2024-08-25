/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:59:01 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/25 16:10:37 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int	main(int ac, char **argv, char **envp)
{

	env_vars *list;
	int j;
	int i;

	list = list_init(envp);
	(void)ac;
	(void)argv;
	char **av = NULL;
	while (1)
	{
		i = 1;
		j = -1;
		char *cmd = readline("minishell $ ");
		av = split (cmd,' ');
		if (!av || !(*av))
			return(0);
		piipe(list,av,envp);
	}
	return(0);
}