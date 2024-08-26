/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 06:25:11 by asebrani          #+#    #+#             */
/*   Updated: 2024/08/26 11:35:27 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
/*
void piipe(env_vars *list,char **av,char **env)
{
	int i=0;
	int pid;
	int fd[2];
	char str[100000];


	while (av[i])
	{
		if (strcmp(av[i],"|") == 0)
		{
			if (pipe(fd) == -1)
				return(void)(printf("Error with pipe"));
			pid = fork();
			if (pid == 0)
			{
				//child
				dup2(fd[0],STDOUT_FILENO);
				close (fd[0]);
				close (fd[1]);
				printf("%s",av[0]);
				execute_the_thing(av,env,list);
			}
			else
			{
				dup2(fd[1],fd[0]);
				close(fd[0]);
				close (fd[1]);
				av = split(str,' ');
				execute_the_thing(av,env,list);
			}
		}
		i++;
	}
}
*/



void piipe(env_vars *list, char **av, char **env)
{
    int i = 0;
    int pid;
    int fd[2];

    while (av[i])
    {
        if (strcmp(av[i], "|") == 0)
        {
            av[i] = NULL;

            if (pipe(fd) == -1)
            {
                perror("Error with pipe");
                return;
            }

            pid = fork();
            if (pid == -1)
            {
                perror("Error with fork");
                return;
            }
            else if (pid == 0) // Child process
            {
                close(fd[0]); 
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]); 
                execute_the_thing(av, env, list);
				puts("hre\n");
            }
            else // Parent process
            {
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO); 
                close(fd[0]); 
                av = &av[i + 1];
                i = -1; 
   				execute_the_thing(av, env, list);
				puts("2hre\n");

            }
			waitpid(0,NULL,0);
        }
		else
			execute_the_thing(av, env, list);
        i++;
    }
}
void execute_the_thing(char **av,char **env,env_vars *list)
{
	char **builtins;
	int j=0;
	char *str;
	int i;
	i = 1;
	
	str = get_path(env,"PATH=");
	builtins = split("cd echo pwd export unset env exit", ' ');

	while (builtins[++j])
	{
		if (strcmp(av[0],builtins[j]) == 0)
		{
			list = execute_builtins(builtins[j],av,list,env);
			i = 0;
		}
	}
	if (i)
		excutefilepath(av,str,env);
	free_double(builtins);
}
