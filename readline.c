#include "minishell.h"

void excute_builtins(char* builtin,char **av,char **envp)
{
	if (strcmp(builtin,"echo") == 0)
		echoo(av+1);
	else if (strcmp(builtin, "pwd") == 0)
		pwdd(1);
	else if (strcmp(builtin,"env"))
		envpp(envp);
	//else if (strcmp(builtin,"export"))
		//exportt(envp);
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
