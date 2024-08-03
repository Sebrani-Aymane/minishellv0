/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:00 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/03 06:06:33 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include <sys/_types/_size_t.h>

void execute_builtins(char* builtin, char **av, char **envp)
{
	env_vars **list;

	list = list_init(envp);
	if (!list)
		return;
    if (strcmp(builtin, "echo") == 0)
        echoo(av + 1);
    if (strcmp(builtin, "pwd") == 0) 
        pwdd(1);
    if (strcmp(builtin, "export") == 0)
	    list = exportt_basic((*list)->env, av);
    if (strcmp(builtin, "env") == 0)
    	envpp((*list)->env);
		
	

}

int excutefilepath(char **av,char **envp)
{
	char *to_excute;
	int i=0;
	char **paths;
	char *command_path;

	command_path = malloc(strlen(av[1] + 2));
	if (!command_path)
		return(printf("error command path\n"),1);
	command_path  = str_joiner("/",av[1]);
	paths = split(get_path(envp), ':');
	if (!paths)
		return(printf("ERROR SPLIT\n"),1);
	while(paths[i])
	{
		to_excute = malloc(strlen(paths[i] + strlen(command_path)));
		to_excute = str_joiner(paths[i],command_path);
		if (access(to_excute, X_OK) == 0)
		{
			execve(to_excute, av +1, envp);
		}
		else
			free(to_excute);
		i++;
	}
	free(paths);
	free(command_path);
	return(0);

}
void free_double(char **str)
{
	int j;

	j = 0;
	while (str[j])
		free(str[j++]);
}
