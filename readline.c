/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:00 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/07 02:53:11 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include <sys/_types/_size_t.h>

env_vars *execute_builtins(char* builtin, char **av, env_vars *list)
{
	char **env;
	int l;
	env = joker(list);
    if (strcmp(builtin, "echo") == 0)
        echoo(av + 1);
    if (strcmp(builtin, "pwd") == 0) 
        pwdd(1);
    if (strcmp(builtin, "export") == 0)
	{
		if (!(av[1]))
			envpp(env);
	    list = exportt_basic(env, av);
	}
	if (strcmp(builtin, "env") == 0)
    	envpp(env);
	if (strcmp(builtin, "cd") == 0)
		l = chdirr(env,av);
return(list);
}
void excutefilepath(char **av,char *path,char **env)
{
	char *to_excute;
	int i=0;
	char **paths;
	char *command_path;

	int lenght = ft_strlen(av[0]);
	command_path = malloc(lenght);
	if (!command_path)
		return;
	command_path  = str_joiner("/",av[0]);
	int lenght1=ft_strlen(command_path);
	paths = split(path, ':');
	if (!paths)
		return;
	while(paths[i])
	{
		lenght =ft_strlen(paths[i]);
		to_excute = malloc(lenght + lenght1);
		if (!to_excute)
			return;
		to_excute = str_joiner(paths[i],command_path);
		if (access(to_excute, X_OK) == 0)
		{
			execve(to_excute, av, env);
		}
		else
			free(to_excute);
		i++;
	}
	free(paths);
	free(command_path);
	return;

}
void free_double(char **str)
{
	int j;

	j = 0;
	while (str[j])
		free(str[j++]);
}